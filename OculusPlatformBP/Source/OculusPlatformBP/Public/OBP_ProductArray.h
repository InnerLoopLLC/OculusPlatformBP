// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_Product.h"
#include "OBP_ProductArray.generated.h"

// --------------------
// OVR_ProductArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_ProductArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrProductArray* ovrProductArrayHandle;

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|IAP|Product Array")
		UOBP_Product* GetElement(int32 Index);

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|IAP|Product Array")
		FString GetNextUrl();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|IAP|Product Array")
		int32 GetSize();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|IAP|Product Array")
		bool HasNextPage();
};