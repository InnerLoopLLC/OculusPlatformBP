// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Requests_Challenges.h"

// --------------------
// Initializers
// --------------------

UOBP_Challenges_DeclineInvite::UOBP_Challenges_DeclineInvite(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Challenges_Get::UOBP_Challenges_Get(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Challenges_GetEntries::UOBP_Challenges_GetEntries(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Challenges_GetEntriesAfterRank::UOBP_Challenges_GetEntriesAfterRank(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Challenges_GetEntriesByIds::UOBP_Challenges_GetEntriesByIds(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Challenges_GetList::UOBP_Challenges_GetList(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Challenges_GetNextChallenges::UOBP_Challenges_GetNextChallenges(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Challenges_GetNextEntries::UOBP_Challenges_GetNextEntries(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Challenges_GetPreviousChallenges::UOBP_Challenges_GetPreviousChallenges(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Challenges_GetPreviousEntries::UOBP_Challenges_GetPreviousEntries(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Challenges_Join::UOBP_Challenges_Join(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Challenges_Leave::UOBP_Challenges_Leave(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_Requests_Challenges.h
// --------------------

//---DeclineInvite---
void UOBP_Challenges_DeclineInvite::Activate()
{
#if PLATFORM_MINOR_VERSION >= 51
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Challenges_DeclineInvite(OBP_FStringToInt64(ChallengeID));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Challenges::DeclineInvite", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Challenges_DeclineInvite)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully declined a challenge invite."));
					auto ThisChallenge = NewObject<UOBP_Challenge>();
					ThisChallenge->ovrChallengeHandle = ovr_Message_GetChallenge(Message);
					OnSuccess.Broadcast(ThisChallenge);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to decline a challenge invite."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Challenges::DeclineInvite");
		OnFailure.Broadcast(nullptr);
	}
#else
	OBP_PlatformVersionError("Challenges::DeclineInvite", "v19");
	OnFailure.Broadcast(nullptr);
#endif
}

UOBP_Challenges_DeclineInvite* UOBP_Challenges_DeclineInvite::DeclineInvite(UObject* WorldContextObject, FString ChallengeID)
{
	auto DeclineInvite = NewObject<UOBP_Challenges_DeclineInvite>();
	DeclineInvite->ChallengeID = ChallengeID;
	return DeclineInvite;
}

//---Get---
void UOBP_Challenges_Get::Activate()
{
#if PLATFORM_MINOR_VERSION >= 51
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Challenges_Get(OBP_FStringToInt64(ChallengeID));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Challenges::Get", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Challenges_Get)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got a challenge invite."));
					auto ThisChallenge = NewObject<UOBP_Challenge>();
					ThisChallenge->ovrChallengeHandle = ovr_Message_GetChallenge(Message);
					OnSuccess.Broadcast(ThisChallenge);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get a challenge invite."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Challenges::Get");
		OnFailure.Broadcast(nullptr);
	}
#else
	OBP_PlatformVersionError("Challenges::Get", "v19");
	OnFailure.Broadcast(nullptr);
#endif
}

UOBP_Challenges_Get* UOBP_Challenges_Get::Get(UObject* WorldContextObject, FString ChallengeID)
{
	auto Get = NewObject<UOBP_Challenges_Get>();
	Get->ChallengeID = ChallengeID;
	return Get;
}

//---GetEntries---
void UOBP_Challenges_GetEntries::Activate()
{
#if PLATFORM_MINOR_VERSION >= 51
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

		ovrRequest RequestId = ovr_Challenges_GetEntries(OBP_FStringToInt64(ChallengeID), Limit, ovrFilter, ovrStartAt);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Challenges::GetEntries", Message);
				OnFailure.Broadcast(TArray<UOBP_ChallengeEntry*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Challenges_GetEntries)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got challenge entries."));
					auto ThisChallengeEntryArray = NewObject<UOBP_ChallengeEntryArray>();
					ThisChallengeEntryArray->ovrChallengeEntryArrayHandle = ovr_Message_GetChallengeEntryArray(Message);

					TArray<UOBP_ChallengeEntry*> ChallengeEntries;

					for (size_t i = 0; i < ovr_ChallengeEntryArray_GetSize(ThisChallengeEntryArray->ovrChallengeEntryArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_ChallengeEntry>();
						ThisElement->ovrChallengeEntryHandle = ovr_ChallengeEntryArray_GetElement(ThisChallengeEntryArray->ovrChallengeEntryArrayHandle, i);
						ChallengeEntries.Add(ThisElement);
					}

					OnSuccess.Broadcast(ChallengeEntries, ThisChallengeEntryArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get challenge entries."));
					OnFailure.Broadcast(TArray<UOBP_ChallengeEntry*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Challenges::GetEntries");
		OnFailure.Broadcast(TArray<UOBP_ChallengeEntry*>(), nullptr);
	}
#else
	OBP_PlatformVersionError("Challenges::GetEntries", "v19");
	OnFailure.Broadcast(TArray<UOBP_ChallengeEntry*>(), nullptr);
#endif
}

UOBP_Challenges_GetEntries* UOBP_Challenges_GetEntries::GetEntries(UObject* WorldContextObject, FString ChallengeID, int32 Limit, EOBP_LeaderboardFilterType Filter, EOBP_LeaderboardStartAt StartAt)
{
	auto GetEntries = NewObject<UOBP_Challenges_GetEntries>();
	GetEntries->ChallengeID = ChallengeID;
	GetEntries->Limit = Limit;
	GetEntries->Filter = Filter;
	GetEntries->StartAt = StartAt;
	return GetEntries;
}

//---GetEntriesAfterRank---
void UOBP_Challenges_GetEntriesAfterRank::Activate()
{
#if PLATFORM_MINOR_VERSION >= 51
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Challenges_GetEntriesAfterRank(OBP_FStringToInt64(ChallengeID), Limit, AfterRank);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Challenges::GetEntriesAfterRank", Message);
				OnFailure.Broadcast(TArray<UOBP_ChallengeEntry*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Challenges_GetEntriesAfterRank)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got challenge entries after rank."));
					auto ThisChallengeEntryArray = NewObject<UOBP_ChallengeEntryArray>();
					ThisChallengeEntryArray->ovrChallengeEntryArrayHandle = ovr_Message_GetChallengeEntryArray(Message);
					
					TArray<UOBP_ChallengeEntry*> ChallengeEntries;

					for (size_t i = 0; i < ovr_ChallengeEntryArray_GetSize(ThisChallengeEntryArray->ovrChallengeEntryArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_ChallengeEntry>();
						ThisElement->ovrChallengeEntryHandle = ovr_ChallengeEntryArray_GetElement(ThisChallengeEntryArray->ovrChallengeEntryArrayHandle, i);
						ChallengeEntries.Add(ThisElement);
					}

					OnSuccess.Broadcast(ChallengeEntries, ThisChallengeEntryArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get challenge entries after rank."));
					OnFailure.Broadcast(TArray<UOBP_ChallengeEntry*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Challenges::GetEntriesAfterRank");
		OnFailure.Broadcast(TArray<UOBP_ChallengeEntry*>(), nullptr);
	}
#else
	OBP_PlatformVersionError("Challenges::GetEntriesAfterRank", "v19");
	OnFailure.Broadcast(TArray<UOBP_ChallengeEntry*>(), nullptr);
#endif
}

UOBP_Challenges_GetEntriesAfterRank* UOBP_Challenges_GetEntriesAfterRank::GetEntriesAfterRank(UObject* WorldContextObject, FString ChallengeID, int32 Limit, int32 AfterRank)
{
	auto GetEntriesAfterRank = NewObject<UOBP_Challenges_GetEntriesAfterRank>();
	GetEntriesAfterRank->ChallengeID = ChallengeID;
	GetEntriesAfterRank->Limit = Limit;
	GetEntriesAfterRank->AfterRank = AfterRank;
	return GetEntriesAfterRank;
}

//---GetEntriesByIds---
void UOBP_Challenges_GetEntriesByIds::Activate()
{
#if PLATFORM_MINOR_VERSION >= 51
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrID* ovrIds = NULL; // initialize an array pointer
		ovrIds = new ovrID[UserIds.Num()]; // dynamically size the array

		for (size_t i = 0; i < UserIds.Num(); i++)
		{
			ovrIds[i] = FCString::Atoi64(*UserIds[i]); // copy data to the new array
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

		ovrRequest RequestId = ovr_Challenges_GetEntriesByIds(OBP_FStringToInt64(ChallengeID), Limit, ovrStartAt, ovrIds, UserIdLength);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Challenges::GetEntriesByIds", Message);
				OnFailure.Broadcast(TArray<UOBP_ChallengeEntry*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Challenges_GetEntriesByIds)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got challenge entries by IDs."));
					auto ThisChallengeEntryArray = NewObject<UOBP_ChallengeEntryArray>();
					ThisChallengeEntryArray->ovrChallengeEntryArrayHandle = ovr_Message_GetChallengeEntryArray(Message);
					
					TArray<UOBP_ChallengeEntry*> ChallengeEntries;

					for (size_t i = 0; i < ovr_ChallengeEntryArray_GetSize(ThisChallengeEntryArray->ovrChallengeEntryArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_ChallengeEntry>();
						ThisElement->ovrChallengeEntryHandle = ovr_ChallengeEntryArray_GetElement(ThisChallengeEntryArray->ovrChallengeEntryArrayHandle, i);
						ChallengeEntries.Add(ThisElement);
					}

					OnSuccess.Broadcast(ChallengeEntries, ThisChallengeEntryArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get challenge entries by IDs."));
					OnFailure.Broadcast(TArray<UOBP_ChallengeEntry*>(), nullptr);
				}
			}
		}));
		delete[] ovrIds; // release the memory allocated for the array
	}
	else
	{
		OBP_SubsystemError("Challenges::GetEntriesByIds");
		OnFailure.Broadcast(TArray<UOBP_ChallengeEntry*>(), nullptr);
	}
#else
	OBP_PlatformVersionError("Challenges::GetEntriesByIds", "v19");
	OnFailure.Broadcast(TArray<UOBP_ChallengeEntry*>(), nullptr);
#endif
}

UOBP_Challenges_GetEntriesByIds* UOBP_Challenges_GetEntriesByIds::GetEntriesByIds(UObject* WorldContextObject, FString ChallengeID, int32 Limit, EOBP_LeaderboardStartAt StartAt, TArray<FString> UserIds, int32 UserIdLength)
{
	auto GetEntriesByIds = NewObject<UOBP_Challenges_GetEntriesByIds>();
	GetEntriesByIds->ChallengeID = ChallengeID;
	GetEntriesByIds->Limit = Limit;
	GetEntriesByIds->StartAt = StartAt;
	GetEntriesByIds->UserIds = UserIds;
	GetEntriesByIds->UserIdLength = UserIdLength;
	return GetEntriesByIds;
}

//---GetList---
void UOBP_Challenges_GetList::Activate()
{
#if PLATFORM_MINOR_VERSION >= 51
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		auto ovrChallengeOptionsHandle = ovr_ChallengeOptions_Create();

		ovr_ChallengeOptions_SetDescription(ovrChallengeOptionsHandle, TCHAR_TO_ANSI(*ChallengeOptions.Description));
		ovr_ChallengeOptions_SetEndDate(ovrChallengeOptionsHandle, ChallengeOptions.EndDate);
		ovr_ChallengeOptions_SetIncludeActiveChallenges(ovrChallengeOptionsHandle, ChallengeOptions.bIncludeActiveChallenges);
		ovr_ChallengeOptions_SetIncludeFutureChallenges(ovrChallengeOptionsHandle, ChallengeOptions.bIncludeFutureChallenges);
		ovr_ChallengeOptions_SetIncludePastChallenges(ovrChallengeOptionsHandle, ChallengeOptions.bIncludePastChallenges);
		ovr_ChallengeOptions_SetLeaderboardName(ovrChallengeOptionsHandle, TCHAR_TO_ANSI(*ChallengeOptions.LeaderboardName));
		ovr_ChallengeOptions_SetStartDate(ovrChallengeOptionsHandle, ChallengeOptions.StartDate);
		ovr_ChallengeOptions_SetTitle(ovrChallengeOptionsHandle, TCHAR_TO_ANSI(*ChallengeOptions.Title));

		switch (ChallengeOptions.ViewerFilter)
		{
		case EOBP_ChallengeViewerFilter::Unknown:
			ovr_ChallengeOptions_SetViewerFilter(ovrChallengeOptionsHandle, ovrChallengeViewerFilter_Unknown);
			break;
		case EOBP_ChallengeViewerFilter::AllVisible:
			ovr_ChallengeOptions_SetViewerFilter(ovrChallengeOptionsHandle, ovrChallengeViewerFilter_AllVisible);
			break;
		case EOBP_ChallengeViewerFilter::Participating:
			ovr_ChallengeOptions_SetViewerFilter(ovrChallengeOptionsHandle, ovrChallengeViewerFilter_Participating);
			break;
		case EOBP_ChallengeViewerFilter::Invited:
			ovr_ChallengeOptions_SetViewerFilter(ovrChallengeOptionsHandle, ovrChallengeViewerFilter_Invited);
			break;
		case EOBP_ChallengeViewerFilter::ParticipatingOrInvited:
			ovr_ChallengeOptions_SetViewerFilter(ovrChallengeOptionsHandle, ovrChallengeViewerFilter_ParticipatingOrInvited);
			break;
		default:
			ovr_ChallengeOptions_SetViewerFilter(ovrChallengeOptionsHandle, ovrChallengeViewerFilter_Unknown);
			break;
		}

		switch (ChallengeOptions.Visibility)
		{
		case EOBP_ChallengeVisibility::Unknown:
			ovr_ChallengeOptions_SetVisibility(ovrChallengeOptionsHandle, ovrChallengeVisibility_Unknown);
			break;
		case EOBP_ChallengeVisibility::InviteOnly:
			ovr_ChallengeOptions_SetVisibility(ovrChallengeOptionsHandle, ovrChallengeVisibility_InviteOnly);
			break;
		case EOBP_ChallengeVisibility::Public:
			ovr_ChallengeOptions_SetVisibility(ovrChallengeOptionsHandle, ovrChallengeVisibility_Public);
			break;
		case EOBP_ChallengeVisibility::Private:
			ovr_ChallengeOptions_SetVisibility(ovrChallengeOptionsHandle, ovrChallengeVisibility_Private);
			break;
		default:
			ovr_ChallengeOptions_SetVisibility(ovrChallengeOptionsHandle, ovrChallengeVisibility_Unknown);
			break;
		}

		ovrRequest RequestId = ovr_Challenges_GetList(ovrChallengeOptionsHandle, Limit);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Challenges::GetList", Message);
				OnFailure.Broadcast(TArray<UOBP_Challenge*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Challenges_GetList)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got list of challenges."));
					auto ThisChallengeArray = NewObject<UOBP_ChallengeArray>();
					ThisChallengeArray->ovrChallengeArrayHandle = ovr_Message_GetChallengeArray(Message);
					
					TArray<UOBP_Challenge*> Challenges;

					for (size_t i = 0; i < ovr_ChallengeArray_GetSize(ThisChallengeArray->ovrChallengeArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_Challenge>();
						ThisElement->ovrChallengeHandle = ovr_ChallengeArray_GetElement(ThisChallengeArray->ovrChallengeArrayHandle, i);
						Challenges.Add(ThisElement);
					}

					OnSuccess.Broadcast(Challenges, ThisChallengeArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get list of challenges."));
					OnFailure.Broadcast(TArray<UOBP_Challenge*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Challenges::GetList");
		OnFailure.Broadcast(TArray<UOBP_Challenge*>(), nullptr);
	}
#else
	OBP_PlatformVersionError("Challenges::GetList", "v19");
	OnFailure.Broadcast(TArray<UOBP_Challenge*>(), nullptr);
#endif
}

UOBP_Challenges_GetList* UOBP_Challenges_GetList::GetList(UObject* WorldContextObject, FOBP_ChallengeOptionsStruct ChallengeOptions, int32 Limit)
{
	auto GetList = NewObject<UOBP_Challenges_GetList>();
	GetList->Limit = Limit;
	GetList->ChallengeOptions = ChallengeOptions;
	return GetList;
}

//---GetNextChallenges---
void UOBP_Challenges_GetNextChallenges::Activate()
{
#if PLATFORM_MINOR_VERSION >= 51
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Challenges_GetNextChallenges(ChallengeArray->ovrChallengeArrayHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Challenges::GetNextChallenges", Message);
				OnFailure.Broadcast(TArray<UOBP_Challenge*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Challenges_GetNextChallenges)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got next challenges."));
					auto ThisChallengeArray = NewObject<UOBP_ChallengeArray>();
					ThisChallengeArray->ovrChallengeArrayHandle = ovr_Message_GetChallengeArray(Message);
					
					TArray<UOBP_Challenge*> Challenges;

					for (size_t i = 0; i < ovr_ChallengeArray_GetSize(ThisChallengeArray->ovrChallengeArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_Challenge>();
						ThisElement->ovrChallengeHandle = ovr_ChallengeArray_GetElement(ThisChallengeArray->ovrChallengeArrayHandle, i);
						Challenges.Add(ThisElement);
					}

					OnSuccess.Broadcast(Challenges, ThisChallengeArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get next challenges."));
					OnFailure.Broadcast(TArray<UOBP_Challenge*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Challenges::GetNextChallenges");
		OnFailure.Broadcast(TArray<UOBP_Challenge*>(), nullptr);
	}
#else
	OBP_PlatformVersionError("Challenges::GetNextChallenges", "v19");
	OnFailure.Broadcast(TArray<UOBP_Challenge*>(), nullptr);
#endif
}

UOBP_Challenges_GetNextChallenges* UOBP_Challenges_GetNextChallenges::GetNextChallenges(UObject* WorldContextObject, UOBP_ChallengeArray* ChallengeArray)
{
	auto GetNextChallenges = NewObject<UOBP_Challenges_GetNextChallenges>();
	GetNextChallenges->ChallengeArray = ChallengeArray;
	return GetNextChallenges;
}

//---GetNextEntries---
void UOBP_Challenges_GetNextEntries::Activate()
{
#if PLATFORM_MINOR_VERSION >= 51
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Challenges_GetNextEntries(ChallengeEntryArray->ovrChallengeEntryArrayHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Challenges::GetNextEntries", Message);
				OnFailure.Broadcast(TArray<UOBP_ChallengeEntry*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Challenges_GetNextEntries)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got next challenge entries."));
					auto ThisChallengeEntryArray = NewObject<UOBP_ChallengeEntryArray>();
					ThisChallengeEntryArray->ovrChallengeEntryArrayHandle = ovr_Message_GetChallengeEntryArray(Message);
					
					TArray<UOBP_ChallengeEntry*> ChallengeEntries;

					for (size_t i = 0; i < ovr_ChallengeEntryArray_GetSize(ThisChallengeEntryArray->ovrChallengeEntryArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_ChallengeEntry>();
						ThisElement->ovrChallengeEntryHandle = ovr_ChallengeEntryArray_GetElement(ThisChallengeEntryArray->ovrChallengeEntryArrayHandle, i);
						ChallengeEntries.Add(ThisElement);
					}

					OnSuccess.Broadcast(ChallengeEntries, ThisChallengeEntryArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get next challenge entries."));
					OnFailure.Broadcast(TArray<UOBP_ChallengeEntry*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Challenges::GetNextEntries");
		OnFailure.Broadcast(TArray<UOBP_ChallengeEntry*>(), nullptr);
	}
#else
	OBP_PlatformVersionError("Challenges::GetNextEntries", "v19");
	OnFailure.Broadcast(TArray<UOBP_ChallengeEntry*>(), nullptr);
#endif
}

UOBP_Challenges_GetNextEntries* UOBP_Challenges_GetNextEntries::GetNextEntries(UObject* WorldContextObject, UOBP_ChallengeEntryArray* ChallengeEntryArray)
{
	auto GetNextEntries = NewObject<UOBP_Challenges_GetNextEntries>();
	GetNextEntries->ChallengeEntryArray = ChallengeEntryArray;
	return GetNextEntries;
}

//---GetPreviousChallenges---
void UOBP_Challenges_GetPreviousChallenges::Activate()
{
#if PLATFORM_MINOR_VERSION >= 51
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Challenges_GetPreviousChallenges(ChallengeArray->ovrChallengeArrayHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Challenges::GetPreviousChallenges", Message);
				OnFailure.Broadcast(TArray<UOBP_Challenge*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Challenges_GetPreviousChallenges)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got previous challenges."));
					auto ThisChallengeArray = NewObject<UOBP_ChallengeArray>();
					ThisChallengeArray->ovrChallengeArrayHandle = ovr_Message_GetChallengeArray(Message);
					
					TArray<UOBP_Challenge*> Challenges;

					for (size_t i = 0; i < ovr_ChallengeArray_GetSize(ThisChallengeArray->ovrChallengeArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_Challenge>();
						ThisElement->ovrChallengeHandle = ovr_ChallengeArray_GetElement(ThisChallengeArray->ovrChallengeArrayHandle, i);
						Challenges.Add(ThisElement);
					}

					OnSuccess.Broadcast(Challenges, ThisChallengeArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get previous challenges."));
					OnFailure.Broadcast(TArray<UOBP_Challenge*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Challenges::GetPreviousChallenges");
		OnFailure.Broadcast(TArray<UOBP_Challenge*>(), nullptr);
	}
#else
	OBP_PlatformVersionError("Challenges::GetPreviousChallenges", "v19");
	OnFailure.Broadcast(TArray<UOBP_Challenge*>(), nullptr);
#endif
}

UOBP_Challenges_GetPreviousChallenges* UOBP_Challenges_GetPreviousChallenges::GetPreviousChallenges(UObject* WorldContextObject, UOBP_ChallengeArray* ChallengeArray)
{
	auto GetPreviousChallenges = NewObject<UOBP_Challenges_GetPreviousChallenges>();
	GetPreviousChallenges->ChallengeArray = ChallengeArray;
	return GetPreviousChallenges;
}

//---GetPreviousEntries---
void UOBP_Challenges_GetPreviousEntries::Activate()
{
#if PLATFORM_MINOR_VERSION >= 51
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Challenges_GetPreviousEntries(ChallengeEntryArray->ovrChallengeEntryArrayHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Challenges::GetPreviousEntries", Message);
				OnFailure.Broadcast(TArray<UOBP_ChallengeEntry*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Challenges_GetPreviousEntries)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got previous challenge entries."));
					auto ThisChallengeEntryArray = NewObject<UOBP_ChallengeEntryArray>();
					ThisChallengeEntryArray->ovrChallengeEntryArrayHandle = ovr_Message_GetChallengeEntryArray(Message);
					
					TArray<UOBP_ChallengeEntry*> ChallengeEntries;

					for (size_t i = 0; i < ovr_ChallengeEntryArray_GetSize(ThisChallengeEntryArray->ovrChallengeEntryArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_ChallengeEntry>();
						ThisElement->ovrChallengeEntryHandle = ovr_ChallengeEntryArray_GetElement(ThisChallengeEntryArray->ovrChallengeEntryArrayHandle, i);
						ChallengeEntries.Add(ThisElement);
					}

					OnSuccess.Broadcast(ChallengeEntries, ThisChallengeEntryArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get previous challenge entries."));
					OnFailure.Broadcast(TArray<UOBP_ChallengeEntry*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Challenges::GetPreviousEntries");
		OnFailure.Broadcast(TArray<UOBP_ChallengeEntry*>(), nullptr);
	}
#else
	OBP_PlatformVersionError("Challenges::GetPreviousEntries", "v19");
	OnFailure.Broadcast(TArray<UOBP_ChallengeEntry*>(), nullptr);
#endif
}

UOBP_Challenges_GetPreviousEntries* UOBP_Challenges_GetPreviousEntries::GetPreviousEntries(UObject* WorldContextObject, UOBP_ChallengeEntryArray* ChallengeEntryArray)
{
	auto GetPreviousEntries = NewObject<UOBP_Challenges_GetPreviousEntries>();
	GetPreviousEntries->ChallengeEntryArray = ChallengeEntryArray;
	return GetPreviousEntries;
}

//---Join---
void UOBP_Challenges_Join::Activate()
{
#if PLATFORM_MINOR_VERSION >= 51
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Challenges_Join(OBP_FStringToInt64(ChallengeId));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Challenges::Join", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Challenges_Join)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully joined a challenge."));
					auto ThisChallenge = NewObject<UOBP_Challenge>();
					ThisChallenge->ovrChallengeHandle = ovr_Message_GetChallenge(Message);
					OnSuccess.Broadcast(ThisChallenge);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to join a challenge."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Challenges::Join");
		OnFailure.Broadcast(nullptr);
	}
#else
	OBP_PlatformVersionError("Challenges::Join", "v19");
	OnFailure.Broadcast(nullptr);
#endif
}

UOBP_Challenges_Join* UOBP_Challenges_Join::Join(UObject* WorldContextObject, FString ChallengeId)
{
	auto ChallengesJoin = NewObject<UOBP_Challenges_Join>();
	ChallengesJoin->ChallengeId = ChallengeId;
	return ChallengesJoin;
}

//---Leave---
void UOBP_Challenges_Leave::Activate()
{
#if PLATFORM_MINOR_VERSION >= 51
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Challenges_Leave(OBP_FStringToInt64(ChallengeId));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Challenges::Leave", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Challenges_Leave)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully left a challenge."));
					auto ThisChallenge = NewObject<UOBP_Challenge>();
					ThisChallenge->ovrChallengeHandle = ovr_Message_GetChallenge(Message);
					OnSuccess.Broadcast(ThisChallenge);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to leave a challenge."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Challenges::Leave");
		OnFailure.Broadcast(nullptr);
	}
#else
	OBP_PlatformVersionError("Challenges::Leave", "v19");
	OnFailure.Broadcast(nullptr);
#endif
}

UOBP_Challenges_Leave* UOBP_Challenges_Leave::Leave(UObject* WorldContextObject, FString ChallengeId)
{
	auto ChallengesLeave = NewObject<UOBP_Challenges_Leave>();
	ChallengesLeave->ChallengeId = ChallengeId;
	return ChallengesLeave;
}