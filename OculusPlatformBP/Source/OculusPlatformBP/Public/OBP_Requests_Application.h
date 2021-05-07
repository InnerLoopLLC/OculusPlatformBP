// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_ApplicationVersion.h"
#include "OBP_Requests_Application.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FApplication_GetVersion, UOBP_ApplicationVersion*, ApplicationVersion);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FApplication_LaunchOtherApp, FString, String);

// --------------------
// OVR_Requests_Application.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Application_GetVersion : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FApplication_GetVersion OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FApplication_GetVersion OnFailure;

	/* Requests version information, including the currently installed and latest available version name and version code. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Application|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Application_GetVersion* GetVersion(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Application_LaunchOtherApp : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString AppID;
	FString DeeplinkMessage;

	UPROPERTY(BlueprintAssignable)
		FApplication_LaunchOtherApp OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FApplication_LaunchOtherApp OnFailure;

	/* Launches a different application in the user's library. If the user does not have that application installed, they will be taken to that app's page in the Oculus Store */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Application|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Application_LaunchOtherApp* LaunchOtherApp(UObject* WorldContextObject, FString AppID, FString DeeplinkMessage);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};