// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Functions_ApplicationLifecycle.h"

// --------------------
// Initializers
// --------------------

UOBP_Functions_ApplicationLifecycle::UOBP_Functions_ApplicationLifecycle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_Functions_ApplicationLifecycle.h
// --------------------

UOBP_LaunchDetails* UOBP_Functions_ApplicationLifecycle::GetLaunchDetails(UObject* WorldContextObject)
{
	auto LaunchDetails = NewObject<UOBP_LaunchDetails>();
	LaunchDetails->ovrLaunchDetailsHandle = ovr_ApplicationLifecycle_GetLaunchDetails();
	return LaunchDetails;
}