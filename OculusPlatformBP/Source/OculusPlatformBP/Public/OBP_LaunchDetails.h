// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_UserArray.h"
#include "OBP_LaunchDetails.generated.h"

// --------------------
// OVR_LaunchDetails.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_LaunchDetails : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrLaunchDetails* ovrLaunchDetailsHandle;

	/* An opaque string provided by the developer to help them deeplink to content on app startup. */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Application|Launch Details")
		FString GetDeeplinkMessage();

	/* If provided, the intended destination the user would like to go to.
	Requires OculusPlatfromSDK 1.41 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Application|Launch Details")
		FString GetDestinationApiName();

	/* If provided, the intended lobby the user would like to be in. 
	Requires OculusPlatformSDK v28 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Application|Launch Details")
		FString GetLobbySessionID();

	/* If provided, the intended session the user would like to be in.
	Requires OculusPlatformSDK v28 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Application|Launch Details")
		FString GetMatchSessionID();

	/* A string typically used to distinguish where the deeplink came from. For instance, a DEEPLINK launch type could be coming from events or rich presence. */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Application|Launch Details")
		FString GetLaunchSource();

	/* If provided, the intended room the user would like to be in. */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Application|Launch Details")
		FString GetRoomID();

	/* A unique identifer to keep track of a user going through the deeplinking flow 
	Requires OculusPlatfromSDK v23 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Application|Launch Details")
		FString GetTrackingID();

	/* If provided, the intended users the user would like to be with This method may return null. This indicates that the value is not present or that the curent app or user is not permitted to access it. */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Application|Launch Details")
		UOBP_UserArray* GetUsers();

	/* An opaque string provided by the developer to help them deeplink to content on app startup. */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Application|Launch Details")
		EOBP_LaunchType GetLaunchType();
};