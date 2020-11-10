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

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Purchase")
		int32 GetExpirationTime();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Purchase")
		int32 GetGrantTime();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Purchase")
		FString GetPurchaseID();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Purchase")
		FString GetSKU();
};