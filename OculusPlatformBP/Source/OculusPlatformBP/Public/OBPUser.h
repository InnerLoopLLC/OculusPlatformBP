// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBPUser.generated.h"

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBPUser : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	// --------------------
	// OVR_User.h (https://developer.oculus.com/reference/platform/v19/o_v_r_rich_presence_options_8h)
	// --------------------

	ovrUser* ovrUserHandle;

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBPUser* CreateUser(UObject* WorldContextObject);

	// requires OculusPlatfromSDK v18 (1.50) or later
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User")
		FString GetDisplayName();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User")
		FString GetPresence();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User")
		FString GetPresenceDeeplinkMessage();

	// requires OculusPlatfromSDK 1.41 or later
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User")
		FString GetPresenceDestinationApiName();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User")
		EOBPUserPresenceStatus GetPresenceStatus();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User")
		int64 GetID();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User")
		FString GetImageURL();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User")
		FString GetInviteToken();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User")
		FString GetOculusID();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User")
		FString GetSmallImageUrl();
};