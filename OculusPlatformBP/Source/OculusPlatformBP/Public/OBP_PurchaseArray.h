// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_Purchase.h"
#include "OBP_PurchaseArray.generated.h"

// --------------------
// OVR_PurchaseArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_PurchaseArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrPurchaseArray* ovrPurchaseArrayHandle;

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|IAP|Purchase Array")
		UOBP_Purchase* GetElement(int32 Index);

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|IAP|Purchase Array")
		FString GetNextUrl();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|IAP|Purchase Array")
		int32 GetSize();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|IAP|Purchase Array")
		bool HasNextPage();
};