// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_ApplicationOptions.generated.h"

// --------------------
// OVR_ApplicationOptions.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_ApplicationOptions : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrApplicationOptions* ovrApplicationOptionsHandle;

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Application|Application Options", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_ApplicationOptions* CreateApplicationOptions(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Application|Application Options")
		void DestroyApplicationOptions();

	/* A message to be passed to a launched app, which can be retrieved with ovr_LaunchDetails_GetDeeplinkMessage() */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Application|Application Options")
		void SetDeeplinkMessage(FString Value);
};