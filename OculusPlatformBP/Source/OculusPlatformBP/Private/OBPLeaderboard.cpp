// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBPLeaderboard.h"

// --------------------
// Initializers
// --------------------
/*
UOBP_Leaderboard::UOBP_Leaderboard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
*/
UOBP_LeaderboardEntry::UOBP_LeaderboardEntry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_LeaderboardEntryArray::UOBP_LeaderboardEntryArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_GetEntries::UOBP_GetEntries(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_GetEntriesAfterRank::UOBP_GetEntriesAfterRank(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_GetEntriesByIds::UOBP_GetEntriesByIds(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_GetNextEntries::UOBP_GetNextEntries(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_GetPreviousEntries::UOBP_GetPreviousEntries(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_WriteEntry::UOBP_WriteEntry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// ovr_Requests_Leaderboard.h
// --------------------

//---GetEntries---
void UOBP_GetEntries::Activate()
{
	UOBP_LeaderboardEntryArray* LeaderboardEntryArray = NewObject<UOBP_LeaderboardEntryArray>();

	ovrLeaderboardFilterType LeaderboardFilter = OBP_LeaderboardFilterToEnum(Filter);
	ovrLeaderboardStartAt LeaderboardStartAt = OBP_LeaderboardStartAtToEnum(StartAt);

	ovrRequest RequestId = ovr_Leaderboard_GetEntries(TCHAR_TO_ANSI(*LeaderboardName), Limit, LeaderboardFilter, LeaderboardStartAt);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this, LeaderboardEntryArray](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("Leaderboard::GetEntries", Message);
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_Leaderboard_GetEntries)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got leaderboard entries."));
				LeaderboardEntryArray->ovrLeaderboardEntryArrayHandle = ovr_Message_GetLeaderboardEntryArray(Message);
				OnSuccess.Broadcast(LeaderboardEntryArray);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get leaderboard entries."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
}

UOBP_GetEntries* UOBP_GetEntries::GetEntries(UObject* WorldContextObject, FString LeaderboardName, int Limit, EOBPLeaderboardFilterType Filter, EOBPLeaderboardStartAt StartAt)
{
	UOBP_GetEntries* Entries = NewObject<UOBP_GetEntries>();
	Entries->LeaderboardName = LeaderboardName;
	Entries->Limit = Limit;
	Entries->Filter = Filter;
	Entries->StartAt = StartAt;
	return Entries;
}

//---GetEntriesAfterRank---
void UOBP_GetEntriesAfterRank::Activate()
{
	UOBP_LeaderboardEntryArray* LeaderboardEntryArray = NewObject<UOBP_LeaderboardEntryArray>();

	ovrRequest RequestId = ovr_Leaderboard_GetEntriesAfterRank(TCHAR_TO_ANSI(*LeaderboardName), Limit, AfterRank);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this, LeaderboardEntryArray](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("Leaderboard::GetEntriesAfterRank", Message);
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_Leaderboard_GetEntriesAfterRank)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got leaderboard entries after rank."));
				LeaderboardEntryArray->ovrLeaderboardEntryArrayHandle = ovr_Message_GetLeaderboardEntryArray(Message);
				OnSuccess.Broadcast(LeaderboardEntryArray);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get leaderboard entries after rank."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
}

UOBP_GetEntriesAfterRank* UOBP_GetEntriesAfterRank::GetEntriesAfterRank(UObject* WorldContextObject, FString LeaderboardName, int Limit, int64 AfterRank)
{
	UOBP_GetEntriesAfterRank* EntriesAfterRank = NewObject<UOBP_GetEntriesAfterRank>();
	EntriesAfterRank->LeaderboardName = LeaderboardName;
	EntriesAfterRank->Limit = Limit;
	EntriesAfterRank->AfterRank = AfterRank;
	return EntriesAfterRank;
}

//---GetEntriesByIds---
void UOBP_GetEntriesByIds::Activate()
{
#if PLATFORM_MINOR_VERSION >= 47
	UOBP_LeaderboardEntryArray* LeaderboardEntryArray = NewObject<UOBP_LeaderboardEntryArray>();

	ovrLeaderboardStartAt LeaderboardStartAt = OBP_LeaderboardStartAtToEnum(StartAt);

	ovrRequest RequestId = ovr_Leaderboard_GetEntriesByIds(TCHAR_TO_ANSI(*LeaderboardName), Limit, LeaderboardStartAt, UserIdArray, UserIdLength);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this, LeaderboardEntryArray](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("Leaderboard::GetEntriesByIds", Message);
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_Leaderboard_GetEntriesByIds)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got leaderboard entries by IDs."));
				LeaderboardEntryArray->ovrLeaderboardEntryArrayHandle = ovr_Message_GetLeaderboardEntryArray(Message);
				OnSuccess.Broadcast(LeaderboardEntryArray);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get leaderboard entries by IDs."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
#else
	OBP_PlatformVersionError("Leaderboard::GetEntriesByIds", "v15");
	OnFailure.Broadcast(nullptr);
#endif
}

UOBP_GetEntriesByIds* UOBP_GetEntriesByIds::GetEntriesByIds(UObject* WorldContextObject, FString LeaderboardName, int Limit, EOBPLeaderboardStartAt StartAt, TArray<int64> UserIdArray, int UserIdLength)
{
	UOBP_GetEntriesByIds* Entries = NewObject<UOBP_GetEntriesByIds>();
	Entries->LeaderboardName = LeaderboardName;
	Entries->Limit = Limit;
	Entries->StartAt = StartAt;
	Entries->UserIdArray = UserIdArray;
	Entries->UserIdLength = UserIdLength;
	return Entries;
}

//---GetNextEntries---
void UOBP_GetNextEntries::Activate()
{
	ovrRequest RequestId = ovr_Leaderboard_GetNextEntries(NextLeaderboardEntryArray->ovrLeaderboardEntryArrayHandle);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("Leaderboard::GetNextEntries", Message);
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_Leaderboard_GetNextEntries)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got next leaderboard entries."));
				NextLeaderboardEntryArray->ovrLeaderboardEntryArrayHandle = ovr_Message_GetLeaderboardEntryArray(Message);
				OnSuccess.Broadcast(NextLeaderboardEntryArray);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get next leaderboard entries."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
}
 
UOBP_GetNextEntries* UOBP_GetNextEntries::GetNextEntries(UObject* WorldContextObject, UOBP_LeaderboardEntryArray* LeaderboardEntryArray)
{
	UOBP_GetNextEntries* NextEntries = NewObject<UOBP_GetNextEntries>();
	NextEntries->NextLeaderboardEntryArray = LeaderboardEntryArray;
	return NextEntries;
}

//---GetPreviousEntries---
void UOBP_GetPreviousEntries::Activate()
{
	ovrRequest RequestId = ovr_Leaderboard_GetPreviousEntries(PreviousLeaderboardEntryArray->ovrLeaderboardEntryArrayHandle);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("Leaderboard::GetPreviousEntries", Message);
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_Leaderboard_GetPreviousEntries)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got previous leaderboard entries."));
				PreviousLeaderboardEntryArray->ovrLeaderboardEntryArrayHandle = ovr_Message_GetLeaderboardEntryArray(Message);
				OnSuccess.Broadcast(PreviousLeaderboardEntryArray);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get previous leaderboard entries."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
}

UOBP_GetPreviousEntries* UOBP_GetPreviousEntries::GetPreviousEntries(UObject* WorldContextObject, UOBP_LeaderboardEntryArray* LeaderboardEntryArray)
{
	UOBP_GetPreviousEntries* PreviousEntries = NewObject<UOBP_GetPreviousEntries>();
	PreviousEntries->PreviousLeaderboardEntryArray = LeaderboardEntryArray;
	return PreviousEntries;
}

//---WriteEntry---
void UOBP_WriteEntry::Activate()
{
	ovrRequest RequestId = ovr_Leaderboard_WriteEntry(TCHAR_TO_ANSI(*LeaderboardName), Score, TCHAR_TO_ANSI(*ExtraData), ExtraDataLength, bForceUpdate);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("Leaderboard::WriteEntry", Message);
			OnFailure.Broadcast(false);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_Leaderboard_WriteEntry)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully wrote leaderboard entry."));
				bool bDidUpdate = ovr_LeaderboardUpdateStatus_GetDidUpdate(ovr_Message_GetLeaderboardUpdateStatus(Message));
				OnSuccess.Broadcast(bDidUpdate);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to write leaderboard entry."));
				OnFailure.Broadcast(false);
			}
		}
	}));
}

UOBP_WriteEntry* UOBP_WriteEntry::WriteEntry(UObject* WorldContextObject, FString LeaderboardName, int64 Score, FString ExtraData, int ExtraDataLength, bool bForceUpdate)
{
	UOBP_WriteEntry* WriteEntry = NewObject<UOBP_WriteEntry>();
	WriteEntry->LeaderboardName = LeaderboardName;
	WriteEntry->Score = Score;
	WriteEntry->ExtraData = ExtraData;
	WriteEntry->ExtraDataLength = ExtraDataLength;
	WriteEntry->bForceUpdate = bForceUpdate;
	return WriteEntry;
}

// --------------------
// ovr_LeaderboardEntry.h
// --------------------

FString UOBP_LeaderboardEntry::GetExtraData()
{
	return ovr_LeaderboardEntry_GetExtraData(ovrLeaderboardEntryHandle);
}

int UOBP_LeaderboardEntry::GetExtraDataLength()
{
	return ovr_LeaderboardEntry_GetExtraDataLength(ovrLeaderboardEntryHandle);
}

int UOBP_LeaderboardEntry::GetRank()
{
	return ovr_LeaderboardEntry_GetRank(ovrLeaderboardEntryHandle);
}

int64 UOBP_LeaderboardEntry::GetScore()
{
	return ovr_LeaderboardEntry_GetScore(ovrLeaderboardEntryHandle);
}

int64 UOBP_LeaderboardEntry::GetTimestamp()
{
	return ovr_LeaderboardEntry_GetTimestamp(ovrLeaderboardEntryHandle);
}

UOBP_User* UOBP_LeaderboardEntry::GetUser()
{
	UOBP_User* UserToGet = NewObject<UOBP_User>();
	UserToGet->ovrUserHandle = ovr_LeaderboardEntry_GetUser(ovrLeaderboardEntryHandle);
	return UserToGet;
}

// --------------------
// ovr_LeaderboardEntryArray.h
// --------------------

UOBP_LeaderboardEntry* UOBP_LeaderboardEntryArray::GetElement(int Index)
{
	UOBP_LeaderboardEntry* LeaderboardEntryToGet = NewObject<UOBP_LeaderboardEntry>();
	LeaderboardEntryToGet->ovrLeaderboardEntryHandle = ovr_LeaderboardEntryArray_GetElement(ovrLeaderboardEntryArrayHandle, Index);
	return LeaderboardEntryToGet;
}

FString UOBP_LeaderboardEntryArray::GetNextUrl()
{
	return ovr_LeaderboardEntryArray_GetNextUrl(ovrLeaderboardEntryArrayHandle);
}

FString UOBP_LeaderboardEntryArray::GetPreviousUrl()
{
	return ovr_LeaderboardEntryArray_GetPreviousUrl(ovrLeaderboardEntryArrayHandle);
}

int UOBP_LeaderboardEntryArray::GetSize()
{
	return ovr_LeaderboardEntryArray_GetSize(ovrLeaderboardEntryArrayHandle);
}

int64 UOBP_LeaderboardEntryArray::GetTotalCount()
{
	return ovr_LeaderboardEntryArray_GetTotalCount(ovrLeaderboardEntryArrayHandle);
}

bool UOBP_LeaderboardEntryArray::HasNextPage()
{
	return ovr_LeaderboardEntryArray_HasNextPage(ovrLeaderboardEntryArrayHandle);
}

bool UOBP_LeaderboardEntryArray::HasPreviousPage()
{
	return ovr_LeaderboardEntryArray_HasPreviousPage(ovrLeaderboardEntryArrayHandle);
}