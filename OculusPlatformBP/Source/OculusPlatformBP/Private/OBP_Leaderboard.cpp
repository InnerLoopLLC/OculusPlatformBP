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

UOBP_Destination* UOBP_Leaderboard::GetDestination()
{
#if PLATFORM_MINOR_VERSION >= 59
	auto Destination = NewObject<UOBP_Destination>();
	Destination->ovrDestinationHandle = ovr_Leaderboard_GetDestination(ovrLeaderboardHandle);
	return Destination;
#else
	OBP_PlatformVersionError("Leaderboard::GetDestination", "v27");
	return nullptr;
#endif
}

FString UOBP_Leaderboard::GetID()
{
#if PLATFORM_MINOR_VERSION >= 59
	return OBP_Int64ToFString(ovr_Leaderboard_GetID(ovrLeaderboardHandle));
#else
	OBP_PlatformVersionError("Leaderboard::GetID", "v27");
	return FString();
#endif
}
