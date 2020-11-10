// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_ProductArray.h"

// --------------------
// Initializers
// --------------------

UOBP_ProductArray::UOBP_ProductArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_ProductArray.h
// --------------------

UOBP_Product* UOBP_ProductArray::GetElement(int32 Index)
{
	auto ProductToGet = NewObject<UOBP_Product>();
	ProductToGet->ovrProductHandle = ovr_ProductArray_GetElement(ovrProductArrayHandle, Index);
	return ProductToGet;
}

FString UOBP_ProductArray::GetNextUrl()
{
	return ovr_ProductArray_GetNextUrl(ovrProductArrayHandle);
}

int32 UOBP_ProductArray::GetSize()
{
	return ovr_ProductArray_GetSize(ovrProductArrayHandle);
}

bool UOBP_ProductArray::HasNextPage()
{
	return ovr_ProductArray_HasNextPage(ovrProductArrayHandle);
}