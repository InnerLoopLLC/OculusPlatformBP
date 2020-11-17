// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_AssetDetailsArray.h"

// --------------------
// Initializers
// --------------------

UOBP_AssetDetailsArray::UOBP_AssetDetailsArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_AssetDetailsArray.h
// --------------------

UOBP_AssetDetails* UOBP_AssetDetailsArray::GetElement(int32 Index)
{
	auto AssetDetailsToGet = NewObject<UOBP_AssetDetails>();
	AssetDetailsToGet->ovrAssetDetailsHandle = ovr_AssetDetailsArray_GetElement(ovrAssetDetailsArrayHandle, Index);
	return AssetDetailsToGet;
}

int32 UOBP_AssetDetailsArray::GetSize()
{
	return ovr_AssetDetailsArray_GetSize(ovrAssetDetailsArrayHandle);
}