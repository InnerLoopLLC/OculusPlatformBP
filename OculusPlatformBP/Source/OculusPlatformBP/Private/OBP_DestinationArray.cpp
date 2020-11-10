// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_DestinationArray.h"

// --------------------
// Initializers
// --------------------

UOBP_DestinationArray::UOBP_DestinationArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_DestinationArray.h
// --------------------

UOBP_Destination* UOBP_DestinationArray::GetElement(int32 Index)
{
#if PLATFORM_MINOR_VERSION >= 41
	auto Destination = NewObject<UOBP_Destination>();
	Destination->ovrDestinationHandle = ovr_DestinationArray_GetElement(ovrDestinationArrayHandle, Index);
	return Destination;
#else
	OBP_PlatformVersionError("DestinationArray::GetElement", "1.41");
	return nullptr;
#endif
}

FString UOBP_DestinationArray::GetNextUrl()
{
#if PLATFORM_MINOR_VERSION >= 41
	return ovr_DestinationArray_GetNextUrl(ovrDestinationArrayHandle);
#else
	OBP_PlatformVersionError("DestinationArray::GetNextUrl", "1.41");
	return FString();
#endif
}

int32 UOBP_DestinationArray::GetSize()
{
#if PLATFORM_MINOR_VERSION >= 41
	return ovr_DestinationArray_GetSize(ovrDestinationArrayHandle);
#else
	OBP_PlatformVersionError("DestinationArray::GetSize", "1.41");
	return 0;
#endif
}

bool UOBP_DestinationArray::HasNextPage()
{
#if PLATFORM_MINOR_VERSION >= 41
	return ovr_DestinationArray_HasNextPage(ovrDestinationArrayHandle);
#else
	OBP_PlatformVersionError("DestinationArray::HasNextPage", "1.41");
	return false;
#endif
}