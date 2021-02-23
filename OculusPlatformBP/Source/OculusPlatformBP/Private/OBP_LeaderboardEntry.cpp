// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_LeaderboardEntry.h"

// --------------------
// Initializers
// --------------------

UOBP_LeaderboardEntry::UOBP_LeaderboardEntry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_LeaderboardEntry.h
// --------------------

FString UOBP_LeaderboardEntry::GetDisplayScore()
{
#if PLATFORM_MINOR_VERSION >= 57
	return ovr_LeaderboardEntry_GetDisplayScore(ovrLeaderboardEntryHandle);
#else
	OBP_PlatformVersionError("LeaderboardEntry::GetDisplayScore", "v25");
	return FString();
#endif
}

FString UOBP_LeaderboardEntry::GetExtraData()
{
	return ovr_LeaderboardEntry_GetExtraData(ovrLeaderboardEntryHandle);
}

int32 UOBP_LeaderboardEntry::GetExtraDataLength()
{
	return ovr_LeaderboardEntry_GetExtraDataLength(ovrLeaderboardEntryHandle);
}

int32 UOBP_LeaderboardEntry::GetRank()
{
	return ovr_LeaderboardEntry_GetRank(ovrLeaderboardEntryHandle);
}

int32 UOBP_LeaderboardEntry::GetScore()
{
	return ovr_LeaderboardEntry_GetScore(ovrLeaderboardEntryHandle);
}

UOBP_SupplementaryMetric* UOBP_LeaderboardEntry::GetSupplementaryMetric()
{
#if PLATFORM_MINOR_VERSION >= 57
	auto SupplementaryMetricToGet = NewObject<UOBP_SupplementaryMetric>();
	SupplementaryMetricToGet->ovrSupplementaryMetricHandle = ovr_LeaderboardEntry_GetSupplementaryMetric(ovrLeaderboardEntryHandle);
	return SupplementaryMetricToGet;
#else
	OBP_PlatformVersionError("LeaderboardEntry::GetDisplayScore", "v25");
	return nullptr;
#endif
}

int32 UOBP_LeaderboardEntry::GetTimestamp()
{
	return ovr_LeaderboardEntry_GetTimestamp(ovrLeaderboardEntryHandle);
}

UOBP_User* UOBP_LeaderboardEntry::GetUser()
{
	auto UserToGet = NewObject<UOBP_User>();
	UserToGet->ovrUserHandle = ovr_LeaderboardEntry_GetUser(ovrLeaderboardEntryHandle);
	return UserToGet;
}