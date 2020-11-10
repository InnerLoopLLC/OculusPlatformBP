// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Leaderboard.h"

// --------------------
// Initializers
// --------------------

UOBP_Leaderboard::UOBP_Leaderboard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_Leaderboard.h
// --------------------

FString UOBP_Leaderboard::GetApiName()
{
#if PLATFORM_MINOR_VERSION >= 50
	return ovr_Leaderboard_GetApiName(ovrLeaderboardHandle);
#else
	OBP_PlatformVersionError("Leaderboard::GetApiName", "v18");
	return FString();
#endif
}