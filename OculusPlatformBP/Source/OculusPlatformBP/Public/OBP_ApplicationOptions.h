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

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Application|Application Options", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", DeprecatedFunction, DeprecationMessage = "Call LaunchOtherApp() directly instead."))
		static UOBP_ApplicationOptions* CreateApplicationOptions(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Application|Application Options", meta = (DeprecatedFunction, DeprecationMessage = "Call LaunchOtherApp() directly instead."))
		void DestroyApplicationOptions();

	/* A message to be passed to a launched app, which can be retrieved with ovr_LaunchDetails_GetDeeplinkMessage() */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Application|Application Options", meta = (DeprecatedFunction, DeprecationMessage = "Call LaunchOtherApp() directly instead."))
		void SetDeeplinkMessage(FString Value);
};