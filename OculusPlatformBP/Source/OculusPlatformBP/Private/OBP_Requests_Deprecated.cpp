// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Requests_Deprecated.h"

// --------------------
//	THIS FILE CONSISTS OF DEPRECATED FUNCTIONS ONLY!
//	These allow projects that have not yet been updated to open without crashing.
//	This will all be deleted in a future update.
// --------------------

UOBP_Challenges_Create::UOBP_Challenges_Create(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Challenges_Delete::UOBP_Challenges_Delete(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Challenges_UpdateInfo::UOBP_Challenges_UpdateInfo(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_Requests_Deprecated.h
// --------------------

//---Create---
void UOBP_Challenges_Create::Activate()
{
	OBP_DeprecatedError("OBP_Requests_Challenges::Create", "Use server-to-server API call instead.");
}

UOBP_Challenges_Create* UOBP_Challenges_Create::Create(UObject* WorldContextObject, FString LeaderboardName, FOBP_ChallengeOptionsStruct ChallengeOptions)
{
	return NewObject<UOBP_Challenges_Create>();
}

//---Delete---
void UOBP_Challenges_Delete::Activate()
{
	OBP_DeprecatedError("OBP_Requests_Challenges::Delete", "Use server-to-server API call instead.");
}

UOBP_Challenges_Delete* UOBP_Challenges_Delete::Delete(UObject* WorldContextObject, FString ChallengeID)
{
	return NewObject<UOBP_Challenges_Delete>();
}

//---UpdateInfo---
void UOBP_Challenges_UpdateInfo::Activate()
{
	OBP_DeprecatedError("OBP_Requests_Challenges::UpdateInfo", "Use server-to-server API call instead.");
}

UOBP_Challenges_UpdateInfo* UOBP_Challenges_UpdateInfo::UpdateInfo(UObject* WorldContextObject, FString ChallengeId, FOBP_ChallengeOptionsStruct ChallengeOptions)
{
	return NewObject<UOBP_Challenges_UpdateInfo>();
}