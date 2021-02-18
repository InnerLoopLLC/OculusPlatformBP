// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_SdkAccount.generated.h"

// --------------------
// OVR_SdkAccount.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_SdkAccount : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrSdkAccount* ovrSdkAccountHandle;

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Misc|SdkAccount")
		EOBP_SdkAccountType GetAccountType();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Misc|SdkAccount")
		FString GetUserId();
};