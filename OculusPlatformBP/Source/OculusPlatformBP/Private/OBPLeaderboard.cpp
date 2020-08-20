// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBPLeaderboard.h"

UOBPLeaderboard::UOBPLeaderboard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// Leaderboard Functions
// --------------------

UOBPLeaderboard* Leaderboard::CreateLeaderboard(UObject* WorldContextObject)
{
	return NewObject<UOBPLeaderboard>();
}

FString UOBPLeaderboard::GetApiName()
{
	return ovr_Leaderboard_GetApiName(ovrLeaderboardHandle);
}

// --------------------
// Leaderboard Requests
// --------------------

void UOBPLeaderboard::GetLeaderboardEntries()
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

void UOBPLeaderboard::GetLeaderboardEntriesAfterRank()
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

// requires OculusPlatfromSDK v16 (1.48) or later; default UE4 distribution = 1.40
#if PLATFORM_MINOR_VERSION >= 48
void UOBPLeaderboard::GetLeaderboardEntriesByIds()
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

void UOBPLeaderboard::GetNextLeaderboardEntries()
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

void UOBPLeaderboard::GetPreviousLeaderboardEntries()
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

void UOBPLeaderboard::WriteLeaderboardEntry()
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