// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_SdkAccountArray.h"

// --------------------
// Initializers
// --------------------

UOBP_SdkAccountArray::UOBP_SdkAccountArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_SdkAccountArray.h
// --------------------

UOBP_SdkAccount* UOBP_SdkAccountArray::GetElement(int32 Index)
{
	auto SdkAccount = NewObject<UOBP_SdkAccount>();
	SdkAccount->ovrSdkAccountHandle = ovr_SdkAccountArray_GetElement(ovrSdkAccountArrayHandle, Index);
	return SdkAccount;
}

int32 UOBP_SdkAccountArray::GetSize()
{
	return ovr_SdkAccountArray_GetSize(ovrSdkAccountArrayHandle);
}