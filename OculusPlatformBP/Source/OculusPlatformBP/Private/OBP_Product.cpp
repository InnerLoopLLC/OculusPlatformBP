// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Product.h"

// --------------------
// Initializers
// --------------------

UOBP_Product::UOBP_Product(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_Product.h
// --------------------

FString UOBP_Product::GetDescription()
{
	return ovr_Product_GetDescription(ovrProductHandle);
}

FString UOBP_Product::GetFormattedPrice()
{
	return ovr_Product_GetFormattedPrice(ovrProductHandle);
}

FString UOBP_Product::GetName()
{
	return ovr_Product_GetName(ovrProductHandle);
}

FString UOBP_Product::GetSKU()
{
	return ovr_Product_GetSKU(ovrProductHandle);
}