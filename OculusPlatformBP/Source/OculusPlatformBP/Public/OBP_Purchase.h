// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_Purchase.generated.h"

// --------------------
// OVR_Purchase.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Purchase : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrPurchase* ovrPurchaseHandle;

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|IAP|Purchase")
		int32 GetExpirationTime();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|IAP|Purchase")
		int32 GetGrantTime();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|IAP|Purchase", meta = (DeprecatedFunction,
		DeprecationMessage = "This function has been deprecated! Use Purchase::GetPurchaseStrID node instead."))
		FString GetPurchaseID();

	// requires OculusPlatfromSDK v28 or later
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|IAP|Purchase")
		FString GetPurchaseStrID();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|IAP|Purchase")
		FString GetSKU();
};