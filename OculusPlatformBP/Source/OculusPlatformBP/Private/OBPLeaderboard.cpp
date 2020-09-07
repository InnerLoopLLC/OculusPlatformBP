// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBPLeaderboard.h"

/*
UOBP_Leaderboard::UOBP_Leaderboard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// Leaderboard.h
// --------------------

// not yet implemented
UOBP_Leaderboard* CreateLeaderboard(UObject* WorldContextObject)
{
	return NewObject<UOBP_Leaderboard>();
}

FString UOBP_Leaderboard::GetApiName()
{
	// requires OculusPlatfromSDK v18 (1.50) or later; default UE4 distribution = 1.40
#if PLATFORM_MINOR_VERSION >= 50
	return ovr_Leaderboard_GetApiName(ovrLeaderboardHandle);
#endif
}


// --------------------
// LeaderboardEntry.h
// --------------------

UOBP_LeaderboardEntry::UOBP_LeaderboardEntry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_LeaderboardEntry* CreateLeaderboardEntry(UObject* WorldContextObject)
{
	return NewObject<UOBP_LeaderboardEntry>();
}

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

void UOBP_LeaderboardEntry::GetUser()
{
	// returns ovrUserHandle // need to implement ovrUser.h
	//ovr_LeaderboardEntry_GetUser(ovrLeaderboardEntryHandle);
}

// --------------------
// Leaderboard Requests
// --------------------
/*
void UOBP_Leaderboard::GetLeaderboardEntries()
{
	ovrRequest RequestId = ovr_Leaderboard_GetEntries(const char* leaderboardName, int limit, ovrLeaderboardFilterType filter, ovrLeaderboardStartAt startAt);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError) {
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Error getting Leaderboard entries"));
		}
		else {
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got Leaderboard entries"));
		}
	}));
}

void UOBP_Leaderboard::GetLeaderboardEntriesAfterRank()
{
	ovrRequest RequestId = ovr_Leaderboard_GetEntriesAfterRank(const char* leaderboardName, int limit, unsigned long long afterRank);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError) {
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Error getting Leaderboard entries after rank"));
		}
		else {
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got Leaderboard entries after rank"));
		}
	}));
}

// not yet implemented
// requires OculusPlatfromSDK v16 (1.48) or later; default UE4 distribution = 1.40
#if PLATFORM_MINOR_VERSION >= 48
void UOBP_Leaderboard::GetLeaderboardEntriesByIds()
{
	ovrRequest RequestId = ovr_Leaderboard_GetEntriesByIds(const char* leaderboardName, int limit, ovrLeaderboardStartAt startAt, ovrID * userIDs, unsigned int userIDLength);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError) {
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Error getting Leaderboard entries by IDs"));
		}
		else {
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got Leaderboard entries by IDs"));
		}
	}));
}
#endif

void UOBP_Leaderboard::GetNextLeaderboardEntries()
{
	ovrRequest RequestId = ovr_Leaderboard_GetNextEntries(const ovrLeaderboardEntryArrayHandle handle);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError) {
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Error getting next Leaderboard entries"));
		}
		else {
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got next Leaderboard entries"));
		}
	}));
}

void UOBP_Leaderboard::GetPreviousLeaderboardEntries()
{
	ovrRequest RequestId = ovr_Leaderboard_GetPreviousEntries(const ovrLeaderboardEntryArrayHandle handle);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError) {
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Error getting previous Leaderboard entries"));
		}
		else {
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got previous Leaderboard entries"));
		}
	}));
}

void UOBP_Leaderboard::WriteLeaderboardEntry()
{
	ovrRequest RequestId = ovr_Leaderboard_WriteEntry(const char* leaderboardName, long long score, const void* extraData, unsigned int extraDataLength, bool forceUpdate);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError) {
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Error writing Leaderboard entry"));
		}
		else {
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got Leaderboard entry"));
		}
	}));
}
*/