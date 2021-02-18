// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_SdkAccount.h"
#include "OBP_SdkAccountArray.generated.h"

// --------------------
// OVR_SdkAccountArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_SdkAccountArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrSdkAccountArray* ovrSdkAccountArrayHandle;

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Misc|SdkAccount")
		UOBP_SdkAccount* GetElement(int32 Index);

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Misc|SdkAccount")
		int32 GetSize();
};