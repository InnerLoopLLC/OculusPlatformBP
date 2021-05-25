// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Requests_Leaderboard.h"

// --------------------
// Initializers
// --------------------

UOBP_Leaderboard_Get::UOBP_Leaderboard_Get(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Leaderboard_GetEntries::UOBP_Leaderboard_GetEntries(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Leaderboard_GetEntriesAfterRank::UOBP_Leaderboard_GetEntriesAfterRank(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Leaderboard_GetEntriesByIds::UOBP_Leaderboard_GetEntriesByIds(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Leaderboard_GetNextEntries::UOBP_Leaderboard_GetNextEntries(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Leaderboard_GetNextLeaderboardArrayPage::UOBP_Leaderboard_GetNextLeaderboardArrayPage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Leaderboard_GetPreviousEntries::UOBP_Leaderboard_GetPreviousEntries(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Leaderboard_WriteEntry::UOBP_Leaderboard_WriteEntry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Leaderboard_WriteEntryWithSupplementaryMetric::UOBP_Leaderboard_WriteEntryWithSupplementaryMetric(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_Requests_Leaderboard.h
// --------------------

//---Get---
void UOBP_Leaderboard_Get::Activate()
{
#if PLATFORM_MINOR_VERSION >= 59
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{

		ovrRequest RequestId = ovr_Leaderboard_Get(TCHAR_TO_ANSI(*LeaderboardName));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Leaderboard::Get", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Leaderboard_Get)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got leaderboard."));

					// The message response will return a LeaderboardArray, but the array will always contain a single entry. So, we're just returning that entry directly.
					auto ThisLeaderboard = NewObject<UOBP_Leaderboard>();
					ThisLeaderboard->ovrLeaderboardHandle = ovr_LeaderboardArray_GetElement(ovr_Message_GetLeaderboardArray(Message), 0);

					OnSuccess.Broadcast(ThisLeaderboard);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get leaderboard."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Leaderboard::Get");
		OnFailure.Broadcast(nullptr);
	}
#else
	OBP_PlatformVersionError("Leaderboard::Get", "v27");
	OnFailure.Broadcast(nullptr);
#endif
}

UOBP_Leaderboard_Get* UOBP_Leaderboard_Get::Get(UObject* WorldContextObject, FString LeaderboardName)
{
	auto Leaderboard = NewObject<UOBP_Leaderboard_Get>();
	Leaderboard->LeaderboardName = LeaderboardName;
	return Leaderboard;
}

//---GetEntries---
void UOBP_Leaderboard_GetEntries::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		auto ovrFilter = ovrLeaderboard_FilterNone;

		switch (Filter)
		{
		case EOBP_LeaderboardFilterType::None:
			ovrFilter = ovrLeaderboard_FilterNone;
		case EOBP_LeaderboardFilterType::Friends:
			ovrFilter = ovrLeaderboard_FilterFriends;
		case EOBP_LeaderboardFilterType::Unknown:
			ovrFilter = ovrLeaderboard_FilterUnknown;
		case EOBP_LeaderboardFilterType::UserIds:
#if PLATFORM_MINOR_VERSION >= 47
			ovrFilter = ovrLeaderboard_FilterUserIds;
#else
			ovrFilter = ovrLeaderboard_FilterNone;
#endif
		default:
			ovrFilter = ovrLeaderboard_FilterNone;
		}
		
		auto ovrStartAt = ovrLeaderboard_StartAtTop;
		switch (StartAt)
		{
		case EOBP_LeaderboardStartAt::Top:
			ovrStartAt = ovrLeaderboard_StartAtTop;
		case EOBP_LeaderboardStartAt::CenteredOnViewer:
			ovrStartAt = ovrLeaderboard_StartAtCenteredOnViewer;
		case EOBP_LeaderboardStartAt::CenteredOnViewerOrTop:
			ovrStartAt = ovrLeaderboard_StartAtCenteredOnViewerOrTop;
		case EOBP_LeaderboardStartAt::Unknown:
			ovrStartAt = ovrLeaderboard_StartAtUnknown;
		default:
			ovrStartAt = ovrLeaderboard_StartAtTop;
		}

		ovrRequest RequestId = ovr_Leaderboard_GetEntries(TCHAR_TO_ANSI(*LeaderboardName), Limit, ovrFilter, ovrStartAt);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Leaderboard::GetEntries", Message);
				OnFailure.Broadcast(TArray<UOBP_LeaderboardEntry*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Leaderboard_GetEntries)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got leaderboard entries."));
					auto ThisLeaderboardEntryArray = NewObject<UOBP_LeaderboardEntryArray>();
					ThisLeaderboardEntryArray->ovrLeaderboardEntryArrayHandle = ovr_Message_GetLeaderboardEntryArray(Message);

					TArray<UOBP_LeaderboardEntry*> ArrayOfEntries;

					for (size_t i = 0; i < ovr_LeaderboardEntryArray_GetSize(ThisLeaderboardEntryArray->ovrLeaderboardEntryArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_LeaderboardEntry>();
						ThisElement->ovrLeaderboardEntryHandle = ovr_LeaderboardEntryArray_GetElement(ThisLeaderboardEntryArray->ovrLeaderboardEntryArrayHandle, i);
						ArrayOfEntries.Add(ThisElement);
					}

					OnSuccess.Broadcast(ArrayOfEntries, ThisLeaderboardEntryArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get leaderboard entries."));
					OnFailure.Broadcast(TArray<UOBP_LeaderboardEntry*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Leaderboard::GetEntries");
		OnFailure.Broadcast(TArray<UOBP_LeaderboardEntry*>(), nullptr);
	}
}

UOBP_Leaderboard_GetEntries* UOBP_Leaderboard_GetEntries::GetEntries(UObject* WorldContextObject, FString LeaderboardName, int32 Limit, EOBP_LeaderboardFilterType Filter, EOBP_LeaderboardStartAt StartAt)
{
	auto Entries = NewObject<UOBP_Leaderboard_GetEntries>();
	Entries->LeaderboardName = LeaderboardName;
	Entries->Limit = Limit;
	Entries->Filter = Filter;
	Entries->StartAt = StartAt;
	return Entries;
}

//---GetEntriesAfterRank---
void UOBP_Leaderboard_GetEntriesAfterRank::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Leaderboard_GetEntriesAfterRank(TCHAR_TO_ANSI(*LeaderboardName), Limit, AfterRank);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Leaderboard::GetEntriesAfterRank", Message);
				OnFailure.Broadcast(TArray<UOBP_LeaderboardEntry*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Leaderboard_GetEntriesAfterRank)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got leaderboard entries after rank."));
					auto ThisLeaderboardEntryArray = NewObject<UOBP_LeaderboardEntryArray>();
					ThisLeaderboardEntryArray->ovrLeaderboardEntryArrayHandle = ovr_Message_GetLeaderboardEntryArray(Message);

					TArray<UOBP_LeaderboardEntry*> ArrayOfEntries;

					for (size_t i = 0; i < ovr_LeaderboardEntryArray_GetSize(ThisLeaderboardEntryArray->ovrLeaderboardEntryArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_LeaderboardEntry>();
						ThisElement->ovrLeaderboardEntryHandle = ovr_LeaderboardEntryArray_GetElement(ThisLeaderboardEntryArray->ovrLeaderboardEntryArrayHandle, i);
						ArrayOfEntries.Add(ThisElement);
					}

					OnSuccess.Broadcast(ArrayOfEntries, ThisLeaderboardEntryArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get leaderboard entries after rank."));
					OnFailure.Broadcast(TArray<UOBP_LeaderboardEntry*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Leaderboard::GetEntriesAfterRank");
		OnFailure.Broadcast(TArray<UOBP_LeaderboardEntry*>(), nullptr);
	}
}

UOBP_Leaderboard_GetEntriesAfterRank* UOBP_Leaderboard_GetEntriesAfterRank::GetEntriesAfterRank(UObject* WorldContextObject, FString LeaderboardName, int32 Limit, int32 AfterRank)
{
	auto EntriesAfterRank = NewObject<UOBP_Leaderboard_GetEntriesAfterRank>();
	EntriesAfterRank->LeaderboardName = LeaderboardName;
	EntriesAfterRank->Limit = Limit;
	EntriesAfterRank->AfterRank = AfterRank;
	return EntriesAfterRank;
}

//---GetEntriesByIds---
void UOBP_Leaderboard_GetEntriesByIds::Activate()
{
#if PLATFORM_MINOR_VERSION >= 47
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		auto ovrStartAt = ovrLeaderboard_StartAtTop;
		switch (StartAt)
		{
		case EOBP_LeaderboardStartAt::Top:
			ovrStartAt = ovrLeaderboard_StartAtTop;
		case EOBP_LeaderboardStartAt::CenteredOnViewer:
			ovrStartAt = ovrLeaderboard_StartAtCenteredOnViewer;
		case EOBP_LeaderboardStartAt::CenteredOnViewerOrTop:
			ovrStartAt = ovrLeaderboard_StartAtCenteredOnViewerOrTop;
		case EOBP_LeaderboardStartAt::Unknown:
			ovrStartAt = ovrLeaderboard_StartAtUnknown;
		default:
			ovrStartAt = ovrLeaderboard_StartAtTop;
		}

		ovrID* ovrIds = NULL; // initialize an array pointer
		ovrIds = new ovrID[UserIds.Num()]; // dynamically size the array

		for (size_t i = 0; i < UserIds.Num(); i++)
		{
			ovrIds[i] = FCString::Atoi64(*UserIds[i]); // copy data to the new array
		}

		ovrRequest RequestId = ovr_Leaderboard_GetEntriesByIds(TCHAR_TO_ANSI(*LeaderboardName), Limit, ovrStartAt, ovrIds, UserIdLength);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Leaderboard::GetEntriesByIds", Message);
				OnFailure.Broadcast(TArray<UOBP_LeaderboardEntry*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Leaderboard_GetEntriesByIds)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got leaderboard entries by IDs."));
					auto LeaderboardEntryArray = NewObject<UOBP_LeaderboardEntryArray>();
					LeaderboardEntryArray->ovrLeaderboardEntryArrayHandle = ovr_Message_GetLeaderboardEntryArray(Message);

					TArray<UOBP_LeaderboardEntry*> ArrayOfEntries;

					for (size_t i = 0; i < ovr_LeaderboardEntryArray_GetSize(LeaderboardEntryArray->ovrLeaderboardEntryArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_LeaderboardEntry>();
						ThisElement->ovrLeaderboardEntryHandle = ovr_LeaderboardEntryArray_GetElement(LeaderboardEntryArray->ovrLeaderboardEntryArrayHandle, i);
						ArrayOfEntries.Add(ThisElement);
					}

					OnSuccess.Broadcast(ArrayOfEntries, LeaderboardEntryArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get leaderboard entries by IDs."));
					OnFailure.Broadcast(TArray<UOBP_LeaderboardEntry*>(), nullptr);
				}
			}
		}));
		delete[] ovrIds; // release the memory allocated for the array
	}
	else
	{
		OBP_SubsystemError("Leaderboard::GetEntriesByIds");
		OnFailure.Broadcast(TArray<UOBP_LeaderboardEntry*>(), nullptr);
	}
#else
	OBP_PlatformVersionError("Leaderboard::GetEntriesByIds", "v15");
	OnFailure.Broadcast(TArray<UOBP_LeaderboardEntry*>(), nullptr);
#endif
}

UOBP_Leaderboard_GetEntriesByIds* UOBP_Leaderboard_GetEntriesByIds::GetEntriesByIds(UObject* WorldContextObject, FString LeaderboardName, int32 Limit, EOBP_LeaderboardStartAt StartAt, TArray<FString> UserIds, int32 UserIdLength)
{
	auto Entries = NewObject<UOBP_Leaderboard_GetEntriesByIds>();
	Entries->LeaderboardName = LeaderboardName;
	Entries->Limit = Limit;
	Entries->StartAt = StartAt;
	Entries->UserIds = UserIds;
	Entries->UserIdLength = UserIdLength;
	return Entries;
}

//---GetNextEntries---
void UOBP_Leaderboard_GetNextEntries::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Leaderboard_GetNextEntries(LeaderboardEntryArray->ovrLeaderboardEntryArrayHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Leaderboard::GetNextEntries", Message);
				OnFailure.Broadcast(TArray<UOBP_LeaderboardEntry*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Leaderboard_GetNextEntries)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got next leaderboard entries."));
					auto ThisNextLeaderboardEntryArray = NewObject<UOBP_LeaderboardEntryArray>();
					ThisNextLeaderboardEntryArray->ovrLeaderboardEntryArrayHandle = ovr_Message_GetLeaderboardEntryArray(Message);
				
					TArray<UOBP_LeaderboardEntry*> ArrayOfEntries;

					for (size_t i = 0; i < ovr_LeaderboardEntryArray_GetSize(ThisNextLeaderboardEntryArray->ovrLeaderboardEntryArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_LeaderboardEntry>();
						ThisElement->ovrLeaderboardEntryHandle = ovr_LeaderboardEntryArray_GetElement(ThisNextLeaderboardEntryArray->ovrLeaderboardEntryArrayHandle, i);
						ArrayOfEntries.Add(ThisElement);
					}

					OnSuccess.Broadcast(ArrayOfEntries, ThisNextLeaderboardEntryArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get next leaderboard entries."));
					OnFailure.Broadcast(TArray<UOBP_LeaderboardEntry*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Leaderboard::GetNextEntries");
		OnFailure.Broadcast(TArray<UOBP_LeaderboardEntry*>(), nullptr);
	}
}
 
UOBP_Leaderboard_GetNextEntries* UOBP_Leaderboard_GetNextEntries::GetNextEntries(UObject* WorldContextObject, UOBP_LeaderboardEntryArray* LeaderboardEntryArray)
{
	auto NextEntries = NewObject<UOBP_Leaderboard_GetNextEntries>();
	NextEntries->LeaderboardEntryArray = LeaderboardEntryArray;
	return NextEntries;
}

//---GetNextLeaderboardArrayPage---
void UOBP_Leaderboard_GetNextLeaderboardArrayPage::Activate()
{
#if PLATFORM_MINOR_VERSION >= 59
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{

		ovrRequest RequestId = ovr_Leaderboard_GetNextLeaderboardArrayPage(LeaderboardArray->ovrLeaderboardArrayHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Leaderboard::GetNextLeaderboardArrayPage", Message);
				OnFailure.Broadcast(TArray<UOBP_Leaderboard*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Leaderboard_GetNextLeaderboardArrayPage)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got next leaderboard array page."));
					auto ThisLeaderboardArray = NewObject<UOBP_LeaderboardArray>();
					ThisLeaderboardArray->ovrLeaderboardArrayHandle = ovr_Message_GetLeaderboardArray(Message);

					TArray<UOBP_Leaderboard*> ArrayOfLeaderboards;

					for (size_t i = 0; i < ovr_LeaderboardArray_GetSize(ThisLeaderboardArray->ovrLeaderboardArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_Leaderboard>();
						ThisElement->ovrLeaderboardHandle = ovr_LeaderboardArray_GetElement(ThisLeaderboardArray->ovrLeaderboardArrayHandle, i);
						ArrayOfLeaderboards.Add(ThisElement);
					}

					OnSuccess.Broadcast(ArrayOfLeaderboards, ThisLeaderboardArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get next leaderboard array page."));
					OnFailure.Broadcast(TArray<UOBP_Leaderboard*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Leaderboard::GetNextLeaderboardArrayPage");
		OnFailure.Broadcast(TArray<UOBP_Leaderboard*>(), nullptr);
	}
#else
	OBP_PlatformVersionError("Leaderboard::GetNextLeaderboardArrayPage", "v27");
	OnFailure.Broadcast(TArray<UOBP_Leaderboard*>(), nullptr);
#endif
}

UOBP_Leaderboard_GetNextLeaderboardArrayPage* UOBP_Leaderboard_GetNextLeaderboardArrayPage::GetNextLeaderboardArrayPage(UObject* WorldContextObject, UOBP_LeaderboardArray* LeaderboardArray)
{
	auto NextLeaderboardArrayPage = NewObject<UOBP_Leaderboard_GetNextLeaderboardArrayPage>();
	NextLeaderboardArrayPage->LeaderboardArray = LeaderboardArray;
	return NextLeaderboardArrayPage;
}

//---GetPreviousEntries---
void UOBP_Leaderboard_GetPreviousEntries::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Leaderboard_GetPreviousEntries(LeaderboardEntryArray->ovrLeaderboardEntryArrayHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Leaderboard::GetPreviousEntries", Message);
				OnFailure.Broadcast(TArray<UOBP_LeaderboardEntry*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Leaderboard_GetPreviousEntries)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got previous leaderboard entries."));
					auto ThisPreviousLeaderboardEntryArray = NewObject<UOBP_LeaderboardEntryArray>();
					ThisPreviousLeaderboardEntryArray->ovrLeaderboardEntryArrayHandle = ovr_Message_GetLeaderboardEntryArray(Message);

					TArray<UOBP_LeaderboardEntry*> ArrayOfEntries;

					for (size_t i = 0; i < ovr_LeaderboardEntryArray_GetSize(ThisPreviousLeaderboardEntryArray->ovrLeaderboardEntryArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_LeaderboardEntry>();
						ThisElement->ovrLeaderboardEntryHandle = ovr_LeaderboardEntryArray_GetElement(ThisPreviousLeaderboardEntryArray->ovrLeaderboardEntryArrayHandle, i);
						ArrayOfEntries.Add(ThisElement);
					}

					OnSuccess.Broadcast(ArrayOfEntries, ThisPreviousLeaderboardEntryArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get previous leaderboard entries."));
					OnFailure.Broadcast(TArray<UOBP_LeaderboardEntry*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Leaderboard::GetPreviousEntries");
		OnFailure.Broadcast(TArray<UOBP_LeaderboardEntry*>(), nullptr);
	}
}

UOBP_Leaderboard_GetPreviousEntries* UOBP_Leaderboard_GetPreviousEntries::GetPreviousEntries(UObject* WorldContextObject, UOBP_LeaderboardEntryArray* LeaderboardEntryArray)
{
	auto PreviousEntries = NewObject<UOBP_Leaderboard_GetPreviousEntries>();
	PreviousEntries->LeaderboardEntryArray = LeaderboardEntryArray;
	return PreviousEntries;
}

//---WriteEntry---
void UOBP_Leaderboard_WriteEntry::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Leaderboard_WriteEntry(TCHAR_TO_ANSI(*LeaderboardName), Score, TCHAR_TO_ANSI(*ExtraData), ExtraDataLength, bForceUpdate);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Leaderboard::WriteEntry", Message);
				OnFailure.Broadcast(false, "", 0);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Leaderboard_WriteEntry)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully wrote leaderboard entry."));
					auto bDidUpdate = ovr_LeaderboardUpdateStatus_GetDidUpdate(ovr_Message_GetLeaderboardUpdateStatus(Message));
#if PLATFORM_MINOR_VERSION >= 51
					auto UpdatedChallengeId = OBP_Int64ToFString(ovr_LeaderboardUpdateStatus_GetUpdatedChallengeId(ovr_Message_GetLeaderboardUpdateStatus(Message), 0));
					auto UpdatedChallengeIdSize = ovr_LeaderboardUpdateStatus_GetUpdatedChallengeIdsSize(ovr_Message_GetLeaderboardUpdateStatus(Message));
#else
					FString UpdatedChallengeId = "";
					int32 UpdatedChallengeIdSize = 0;
#endif
					OnSuccess.Broadcast(bDidUpdate, UpdatedChallengeId, UpdatedChallengeIdSize);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to write leaderboard entry."));
					OnFailure.Broadcast(false, "", 0);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Leaderboard::WriteEntry");
		OnFailure.Broadcast(false, "", 0);
	}
}

UOBP_Leaderboard_WriteEntry* UOBP_Leaderboard_WriteEntry::WriteEntry(UObject* WorldContextObject, FString LeaderboardName, int32 Score, FString ExtraData, int32 ExtraDataLength, bool bForceUpdate)
{
	auto WriteEntry = NewObject<UOBP_Leaderboard_WriteEntry>();
	WriteEntry->LeaderboardName = LeaderboardName;
	WriteEntry->Score = Score;
	WriteEntry->ExtraData = ExtraData;
	WriteEntry->ExtraDataLength = ExtraDataLength;
	WriteEntry->bForceUpdate = bForceUpdate;
	return WriteEntry;
}

//---WriteEntryWithSupplementaryMetric---
void UOBP_Leaderboard_WriteEntryWithSupplementaryMetric::Activate()
{
#if PLATFORM_MINOR_VERSION >= 57
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Leaderboard_WriteEntryWithSupplementaryMetric(TCHAR_TO_ANSI(*LeaderboardName), Score, SupplementaryMetric, TCHAR_TO_ANSI(*ExtraData), ExtraDataLength, bForceUpdate);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Leaderboard::WriteEntryWithSupplementaryMetric", Message);
				OnFailure.Broadcast(false, "", 0);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Leaderboard_WriteEntryWithSupplementaryMetric)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully wrote leaderboard entry with supplementary metric."));
					auto bDidUpdate = ovr_LeaderboardUpdateStatus_GetDidUpdate(ovr_Message_GetLeaderboardUpdateStatus(Message));
#if PLATFORM_MINOR_VERSION >= 51
					auto UpdatedChallengeId = OBP_Int64ToFString(ovr_LeaderboardUpdateStatus_GetUpdatedChallengeId(ovr_Message_GetLeaderboardUpdateStatus(Message), 0));
					auto UpdatedChallengeIdSize = ovr_LeaderboardUpdateStatus_GetUpdatedChallengeIdsSize(ovr_Message_GetLeaderboardUpdateStatus(Message));
#else
					FString UpdatedChallengeId = "";
					int32 UpdatedChallengeIdSize = 0;
#endif
					OnSuccess.Broadcast(bDidUpdate, UpdatedChallengeId, UpdatedChallengeIdSize);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to write leaderboard entry with supplementary metric."));
					OnFailure.Broadcast(false, "", 0);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Leaderboard::WriteEntryWithSupplementaryMetric");
		OnFailure.Broadcast(false, "", 0);
	}
#else
	OBP_PlatformVersionError("Leaderboard::WriteEntryWithSupplementaryMetric", "v25");
	OnFailure.Broadcast(false, "", 0);
#endif
}

UOBP_Leaderboard_WriteEntryWithSupplementaryMetric* UOBP_Leaderboard_WriteEntryWithSupplementaryMetric::WriteEntryWithSupplementaryMetric(UObject* WorldContextObject, FString LeaderboardName, int32 Score, int32 SupplementaryMetric, FString ExtraData, int32 ExtraDataLength, bool bForceUpdate)
{
	auto WriteEntryWithSupplementaryMetric = NewObject<UOBP_Leaderboard_WriteEntryWithSupplementaryMetric>();
	WriteEntryWithSupplementaryMetric->LeaderboardName = LeaderboardName;
	WriteEntryWithSupplementaryMetric->Score = Score;
	WriteEntryWithSupplementaryMetric->SupplementaryMetric = SupplementaryMetric;
	WriteEntryWithSupplementaryMetric->ExtraData = ExtraData;
	WriteEntryWithSupplementaryMetric->ExtraDataLength = ExtraDataLength;
	WriteEntryWithSupplementaryMetric->bForceUpdate = bForceUpdate;
	return WriteEntryWithSupplementaryMetric;
}