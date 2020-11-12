// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_ApplicationVersion.h"

// --------------------
// Initializers
// --------------------

UOBP_ApplicationVersion::UOBP_ApplicationVersion(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_ApplicationVersion.h
// --------------------

int32 UOBP_ApplicationVersion::GetCurrentCode()
{
	return ovr_ApplicationVersion_GetCurrentCode(ovrApplicationVersionHandle);
}

FString UOBP_ApplicationVersion::GetCurrentName()
{
	return ovr_ApplicationVersion_GetCurrentName(ovrApplicationVersionHandle);
}

int32 UOBP_ApplicationVersion::GetLatestCode()
{
	return ovr_ApplicationVersion_GetLatestCode(ovrApplicationVersionHandle);
}

FString UOBP_ApplicationVersion::GetLatestName()
{
	return ovr_ApplicationVersion_GetLatestName(ovrApplicationVersionHandle);
}