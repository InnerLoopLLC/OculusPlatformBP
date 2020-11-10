// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Challenge.h"

// --------------------
// Initializers
// --------------------

UOBP_Challenge::UOBP_Challenge(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_Challenge.h
// --------------------

EOBP_ChallengeCreationType UOBP_Challenge::GetCreationType()
{
#if PLATFORM_MINOR_VERSION >= 51
	auto CreationType = ovr_Challenge_GetCreationType(ovrChallengeHandle);
	switch (CreationType)
	{
	case ovrChallengeCreationType_Unknown:
		return EOBP_ChallengeCreationType::Unknown;
	case ovrChallengeCreationType_UserCreated:
		return EOBP_ChallengeCreationType::UserCreated;
	case ovrChallengeCreationType_DeveloperCreated:
		return EOBP_ChallengeCreationType::DeveloperCreated;
	default:
		return EOBP_ChallengeCreationType::Unknown;
	}
#else
	OBP_PlatformVersionError("Challenge::GetCreationType", "v19");
	return EOBP_ChallengeCreationType::Unknown;
#endif
}

FString UOBP_Challenge::GetDescription()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_Challenge_GetDescription(ovrChallengeHandle);
#else
	OBP_PlatformVersionError("Challenge::GetDescription", "v19");
	return FString();;
#endif
}

UOBP_UserArray* UOBP_Challenge::GetInvitedUsers()
{
#if PLATFORM_MINOR_VERSION >= 51
	auto InvitedUsersToGet = NewObject<UOBP_UserArray>();
	InvitedUsersToGet->ovrUserArrayHandle = ovr_Challenge_GetInvitedUsers(ovrChallengeHandle);
	return InvitedUsersToGet;
#else
	OBP_PlatformVersionError("Challenge::GetInvitedUsers", "v19");
	return nullptr;
#endif
}

UOBP_Leaderboard* UOBP_Challenge::GetLeaderboard()
{
#if PLATFORM_MINOR_VERSION >= 51
	auto LeaderboardToGet = NewObject<UOBP_Leaderboard>();
	LeaderboardToGet->ovrLeaderboardHandle = ovr_Challenge_GetLeaderboard(ovrChallengeHandle);
	return LeaderboardToGet;
#else
	OBP_PlatformVersionError("Challenge::GetLeaderboard", "v19");
	return nullptr;
#endif
}

UOBP_UserArray* UOBP_Challenge::GetParticipants()
{
#if PLATFORM_MINOR_VERSION >= 51
	auto InvitedUsersToGet = NewObject<UOBP_UserArray>();
	InvitedUsersToGet->ovrUserArrayHandle = ovr_Challenge_GetParticipants(ovrChallengeHandle);
	return InvitedUsersToGet;
#else
	OBP_PlatformVersionError("Challenge::GetParticipants", "v19");
	return nullptr;
#endif
}

FString UOBP_Challenge::GetTitle()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_Challenge_GetTitle(ovrChallengeHandle);
#else
	OBP_PlatformVersionError("Challenge::GetTitle", "v19");
	return FString();;
#endif
}

EOBP_ChallengeVisibility UOBP_Challenge::GetVisibility()
{
#if PLATFORM_MINOR_VERSION >= 51
	auto VisibilityToGet = ovr_Challenge_GetVisibility(ovrChallengeHandle);
	switch (VisibilityToGet)
	{
	case ovrChallengeVisibility_Unknown:
		return EOBP_ChallengeVisibility::Unknown;
	case ovrChallengeVisibility_InviteOnly:
		return EOBP_ChallengeVisibility::InviteOnly;
	case ovrChallengeVisibility_Public:
		return EOBP_ChallengeVisibility::Public;
	case ovrChallengeVisibility_Private:
		return EOBP_ChallengeVisibility::Private;
	default:
		return EOBP_ChallengeVisibility::Unknown;
}
#else
	OBP_PlatformVersionError("Challenge::GetVisibility", "v19");
	return EOBP_ChallengeVisibility::Unknown;
#endif
}

int32 UOBP_Challenge::GetEndDate()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_Challenge_GetEndDate(ovrChallengeHandle);
#else
	OBP_PlatformVersionError("Challenge::GetEndDate", "v19");
	return 0;
#endif
}

FString UOBP_Challenge::GetID()
{
#if PLATFORM_MINOR_VERSION >= 51
	return OBP_Int64ToFString(ovr_Challenge_GetID(ovrChallengeHandle));
#else
	OBP_PlatformVersionError("Challenge::GetID", "v19");
	return FString();
#endif
}

int32 UOBP_Challenge::GetStartDate()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_Challenge_GetStartDate(ovrChallengeHandle);
#else
	OBP_PlatformVersionError("Challenge::GetStartDate", "v19");
	return 0;
#endif
}
