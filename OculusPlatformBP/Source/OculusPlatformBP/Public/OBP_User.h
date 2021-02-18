// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_User.generated.h"

// --------------------
// OVR_User.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_User : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrUser* ovrUserHandle;

	/*A potentially non unique displayable name chosen by the user. Could also be the same as the oculus_ID
	Requires OculusPlatfromSDK v18 (1.50) or later*/
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User")
		FString GetDisplayName();

	/*Human readable string of what the user is currently doing. Not intended to be parsed as it might change at anytime or be translated*/
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User")
		FString GetPresence();

	/*Intended to be parsed and used to deeplink to parts of the app.
	Requires OculusPlatfromSDK 1.40 or later*/
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User")
		FString GetPresenceDeeplinkMessage();

	/*If provided, the destination this user is currently at in the app.
	Requires OculusPlatfromSDK 1.41 or later*/
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User")
		FString GetPresenceDestinationApiName();

	/*Enum value of what the user is currently doing.*/
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User")
		EOBP_UserPresenceStatus GetPresenceStatus();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User")
		FString GetID();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User")
		FString GetImageURL();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User")
		FString GetInviteToken();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User")
		FString GetOculusID();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User")
		FString GetSmallImageUrl();
};