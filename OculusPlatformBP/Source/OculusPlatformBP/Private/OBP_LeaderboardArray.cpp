// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_LeaderboardArray.h"

// --------------------
// Initializers
// --------------------

UOBP_LeaderboardArray::UOBP_LeaderboardArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_LeaderboardArray.h
// --------------------

UOBP_Leaderboard* UOBP_LeaderboardArray::GetElement(int32 Index)
{
#if PLATFORM_MINOR_VERSION >= 59
	auto LeaderboardToGet = NewObject<UOBP_Leaderboard>();
	LeaderboardToGet->ovrLeaderboardHandle = ovr_LeaderboardArray_GetElement(ovrLeaderboardArrayHandle, Index);
	return LeaderboardToGet;
#else
	OBP_PlatformVersionError("LeaderboardArray::GetElement", "v27");
	return nullptr;
#endif
}

FString UOBP_LeaderboardArray::GetNextUrl()
{
#if PLATFORM_MINOR_VERSION >= 59
	return ovr_LeaderboardArray_GetNextUrl(ovrLeaderboardArrayHandle);
#else
	OBP_PlatformVersionError("LeaderboardArray::GetNextURL", "v27");
	return "";
#endif
}

int32 UOBP_LeaderboardArray::GetSize()
{
#if PLATFORM_MINOR_VERSION >= 59
	return ovr_LeaderboardArray_GetSize(ovrLeaderboardArrayHandle);
#else
	OBP_PlatformVersionError("LeaderboardArray::GetSize", "v27");
	return 0;
#endif
}

bool UOBP_LeaderboardArray::HasNextPage()
{
#if PLATFORM_MINOR_VERSION >= 59
	return ovr_LeaderboardArray_HasNextPage(ovrLeaderboardArrayHandle);
#else
	OBP_PlatformVersionError("LeaderboardArray::HasNextPage", "v27");
	return false;
#endif
}