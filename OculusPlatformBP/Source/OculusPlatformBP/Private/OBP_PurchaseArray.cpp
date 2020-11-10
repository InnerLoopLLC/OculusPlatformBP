// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_PurchaseArray.h"

// --------------------
// Initializers
// --------------------

UOBP_PurchaseArray::UOBP_PurchaseArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_PurchaseArray.h
// --------------------

UOBP_Purchase* UOBP_PurchaseArray::GetElement(int32 Index)
{
	auto PurchaseToGet = NewObject<UOBP_Purchase>();
	PurchaseToGet->ovrPurchaseHandle = ovr_PurchaseArray_GetElement(ovrPurchaseArrayHandle, Index);
	return PurchaseToGet;
}

FString UOBP_PurchaseArray::GetNextUrl()
{
	return ovr_PurchaseArray_GetNextUrl(ovrPurchaseArrayHandle);
}

int32 UOBP_PurchaseArray::GetSize()
{
	return ovr_PurchaseArray_GetSize(ovrPurchaseArrayHandle);
}

bool UOBP_PurchaseArray::HasNextPage()
{
	return ovr_PurchaseArray_HasNextPage(ovrPurchaseArrayHandle);
}