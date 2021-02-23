// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_ChallengeEntry.h"

// --------------------
// Initializers
// --------------------

UOBP_ChallengeEntry::UOBP_ChallengeEntry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_ChallengeEntry.h
// --------------------

FString UOBP_ChallengeEntry::GetDisplayScore()
{
#if PLATFORM_MINOR_VERSION >= 57
	return ovr_ChallengeEntry_GetDisplayScore(ovrChallengeEntryHandle);
#else
	OBP_PlatformVersionError("ChallengeEntry::GetDisplayScore", "v25");
	return FString();
#endif
}

FString UOBP_ChallengeEntry::GetExtraData()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_ChallengeEntry_GetExtraData(ovrChallengeEntryHandle);
#else
	OBP_PlatformVersionError("ChallengeEntry::GetExtraData", "v19");
	return FString();
#endif
}

int32 UOBP_ChallengeEntry::GetExtraDataLength()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_ChallengeEntry_GetExtraDataLength(ovrChallengeEntryHandle);
#else
	OBP_PlatformVersionError("ChallengeEntry::GetExtraDataLength", "v19");
	return 0;
#endif
}

int32 UOBP_ChallengeEntry::GetRank()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_ChallengeEntry_GetRank(ovrChallengeEntryHandle);
#else
	OBP_PlatformVersionError("ChallengeEntry::GetRank", "v19");
	return 0;
#endif
}

int32 UOBP_ChallengeEntry::GetScore()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_ChallengeEntry_GetScore(ovrChallengeEntryHandle);
#else
	OBP_PlatformVersionError("ChallengeEntry::GetScore", "v19");
	return 0;
#endif
}

int32 UOBP_ChallengeEntry::GetTimestamp()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_ChallengeEntry_GetTimestamp(ovrChallengeEntryHandle);
#else
	OBP_PlatformVersionError("ChallengeEntry::GetTimestamp", "v19");
	return 0;
#endif
}

UOBP_User* UOBP_ChallengeEntry::GetUser()
{
#if PLATFORM_MINOR_VERSION >= 51
	auto UserToGet = NewObject<UOBP_User>();
	UserToGet->ovrUserHandle = ovr_ChallengeEntry_GetUser(ovrChallengeEntryHandle);
	return nullptr;
#else
	OBP_PlatformVersionError("ChallengeEntry::GetUser", "v19");
	return 0;
#endif
}
