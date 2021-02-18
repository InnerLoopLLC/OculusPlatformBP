// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_AssetDetails.h"
#include "OBP_AssetDetailsArray.generated.h"

// --------------------
// OVR_AssetDetailsArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_AssetDetailsArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrAssetDetailsArray* ovrAssetDetailsArrayHandle;

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Asset File|Asset Details Array")
		UOBP_AssetDetails* GetElement(int32 Index);

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Asset File|Asset Details Array")
		int32 GetSize();
};