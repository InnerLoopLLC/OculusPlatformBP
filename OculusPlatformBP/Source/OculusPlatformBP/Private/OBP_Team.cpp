// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Team.h"

// --------------------
// Initializers
// --------------------

UOBP_Team::UOBP_Team(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// ovr_Team.h
// --------------------

UOBP_UserArray* UOBP_Team::GetAssignedUsers()
{
#if PLATFORM_MINOR_VERSION >= 39
	auto UserArray = NewObject<UOBP_UserArray>();
	UserArray->ovrUserArrayHandle = ovr_Team_GetAssignedUsers(ovrTeamHandle);
	return UserArray;
#else
	OBP_PlatformVersionError("Team::GetAssignedUsers", "1.39");
	return nullptr;
#endif
}

int32 UOBP_Team::GetMaxUsers()
{
#if PLATFORM_MINOR_VERSION >= 39
	return ovr_Team_GetMaxUsers(ovrTeamHandle);
#else
	OBP_PlatformVersionError("Team::GetMaxUsers", "1.39");
	return 0;
#endif
}

int32 UOBP_Team::GetMinUsers()
{
#if PLATFORM_MINOR_VERSION >= 39
	return ovr_Team_GetMinUsers(ovrTeamHandle);
#else
	OBP_PlatformVersionError("Team::GetMinUsers", "1.39");
	return 0;
#endif
}

FString UOBP_Team::GetName()
{
#if PLATFORM_MINOR_VERSION >= 39
	return ovr_Team_GetName(ovrTeamHandle);
#else
	OBP_PlatformVersionError("Team::GetName", "1.39");
	return FString();
#endif
}