// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_ApplicationVersion.generated.h"

// --------------------
// OVR_ApplicationVersion.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_ApplicationVersion : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrApplicationVersion* ovrApplicationVersionHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Application|Application Version")
		int32 GetCurrentCode();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Application|Application Version")
		FString GetCurrentName();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Application|Application Version")
		int32 GetLatestCode();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Application|Application Version")
		FString GetLatestName();
};