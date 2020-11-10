// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Purchase.h"

// --------------------
// Initializers
// --------------------

UOBP_Purchase::UOBP_Purchase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_Purchase.h
// --------------------

int32 UOBP_Purchase::GetExpirationTime()
{
	return ovr_Purchase_GetExpirationTime(ovrPurchaseHandle);
}

int32 UOBP_Purchase::GetGrantTime()
{
	return ovr_Purchase_GetGrantTime(ovrPurchaseHandle);
}

FString UOBP_Purchase::GetPurchaseID()
{
	return OBP_Int64ToFString(ovr_Purchase_GetPurchaseID(ovrPurchaseHandle));
}

FString UOBP_Purchase::GetSKU()
{
	return ovr_Purchase_GetSKU(ovrPurchaseHandle);
}