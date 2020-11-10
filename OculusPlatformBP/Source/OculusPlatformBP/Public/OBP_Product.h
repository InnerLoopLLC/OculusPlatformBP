// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_Product.generated.h"

// --------------------
// OVR_Product.h
// --------------------
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Product : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrProduct* ovrProductHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Product")
		FString GetDescription();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Product")
		FString GetFormattedPrice();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Product")
		FString GetName();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Product")
		FString GetSKU();
};