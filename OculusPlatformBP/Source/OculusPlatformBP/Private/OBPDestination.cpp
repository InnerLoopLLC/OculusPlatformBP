// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBPDestination.h"

UOBP_Destination::UOBP_Destination(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_DestinationArray::UOBP_DestinationArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_Destination.h (https://developer.oculus.com/reference/platform/v19/o_v_r_destination_8h)
// --------------------

FString UOBP_Destination::GetApiName()
{
#if PLATFORM_MINOR_VERSION >= 41
	return ovr_Destination_GetApiName(ovrDestinationHandle);
#else
	OBP_PlatformVersionError("GetApiName", "1.41");
	return "";
#endif
}

FString UOBP_Destination::GetDeeplinkMessage()
{
#if PLATFORM_MINOR_VERSION >= 41
	return ovr_Destination_GetDeeplinkMessage(ovrDestinationHandle);
#else
	OBP_PlatformVersionError("GetDeeplinkMessage", "1.41");
	return "";
#endif
}

FString UOBP_Destination::GetDisplayName()
{
#if PLATFORM_MINOR_VERSION >= 41
	return ovr_Destination_GetDisplayName(ovrDestinationHandle);
#else
	OBP_PlatformVersionError("GetDisplayName", "1.41");
	return "";
#endif
}

// --------------------
// OVR_DestinationArray.h (https://developer.oculus.com/reference/platform/v19/o_v_r_destination_array_8h/)
// --------------------

UOBP_Destination* UOBP_DestinationArray::GetElement(int32 Index)
{
#if PLATFORM_MINOR_VERSION >= 41
	return ovr_DestinationArray_GetElement(ovrDestinationArrayHandle, Index);
#else
	OBP_PlatformVersionError("GetElement", "1.41");
	return nullptr;
#endif
}

FString UOBP_DestinationArray::GetNextUrl()
{
#if PLATFORM_MINOR_VERSION >= 41
	return ovr_DestinationArray_GetNextUrl(ovrDestinationArrayHandle);
#else
	OBP_PlatformVersionError("GetNextUrl", "1.41");
	return "";
#endif
}

int32 UOBP_DestinationArray::GetSize()
{
#if PLATFORM_MINOR_VERSION >= 41
	return ovr_DestinationArray_GetSize(ovrDestinationArrayHandle);
#else
	OBP_PlatformVersionError("GetSize", "1.41");
	return 0;
#endif
}

bool UOBP_DestinationArray::HasNextPage()
{
#if PLATFORM_MINOR_VERSION >= 41
	return ovr_DestinationArray_HasNextPage(ovrDestinationArrayHandle);
#else
	OBP_PlatformVersionError("HasNextPage", "1.41");
	return false;
#endif
}