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
	OBP_DeprecatedError("Purchase::GetPurchaseID", "Use Purchase::GetPurchaseStrID node instead");
	return FString();
}

// requires OculusPlatfromSDK v28 or later
FString UOBP_Purchase::GetPurchaseStrID()
{
#if PLATFORM_MINOR_VERSION >= 60
	return ovr_Purchase_GetPurchaseStrID(ovrPurchaseHandle);
#else
	OBP_PlatformVersionError("Purchase::GetPurchaseStrID", "v28");
	return FString();
#endif
}

FString UOBP_Purchase::GetSKU()
{
	return ovr_Purchase_GetSKU(ovrPurchaseHandle);
}