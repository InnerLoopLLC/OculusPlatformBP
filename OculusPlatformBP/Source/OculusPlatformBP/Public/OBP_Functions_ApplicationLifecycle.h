// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_LaunchDetails.h"
#include "OBP_Functions_ApplicationLifecycle.generated.h"

// --------------------
// OVR_Functions_ApplicationLifecycle.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Functions_ApplicationLifecycle : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	/* Returns information about how the application was started. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Application|Application Lifecycle", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_LaunchDetails* GetLaunchDetails(UObject* WorldContextObject);
};