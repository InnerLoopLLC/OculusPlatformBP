// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Destination.h"

// --------------------
// Initializers
// --------------------

UOBP_Destination::UOBP_Destination(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_Destination.h
// --------------------

FString UOBP_Destination::GetApiName()
{
#if PLATFORM_MINOR_VERSION >= 41
	return ovr_Destination_GetApiName(ovrDestinationHandle);
#else
	OBP_PlatformVersionError("Destination::GetApiName", "1.41");
	return FString();
#endif
}

FString UOBP_Destination::GetDeeplinkMessage()
{
#if PLATFORM_MINOR_VERSION >= 41
	return ovr_Destination_GetDeeplinkMessage(ovrDestinationHandle);
#else
	OBP_PlatformVersionError("Destination::GetDeeplinkMessage", "1.41");
	return FString();
#endif
}

FString UOBP_Destination::GetDisplayName()
{
#if PLATFORM_MINOR_VERSION >= 41
	return ovr_Destination_GetDisplayName(ovrDestinationHandle);
#else
	OBP_PlatformVersionError("Destination::GetDisplayName", "1.41");
	return FString();
#endif
}