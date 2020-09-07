// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBPUser.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSuccessfulGetLoggedInUser, UOBP_User*, LoggedInUser);

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_LoggedInUser : public UBlueprintAsyncActionBase //UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FOnSuccessfulGetLoggedInUser OnSuccess;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_LoggedInUser* GetLoggedInUser(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
	//~UBlueprintAsyncActionBase interface

private:
	UFUNCTION()
		void ReturnLoggedInUser();
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_User : public UBlueprintAsyncActionBase //UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	// --------------------
	// OVR_User.h (https://developer.oculus.com/reference/platform/v19/o_v_r_rich_presence_options_8h)
	// --------------------

	ovrUser* ovrUserHandle;

	// Requires OculusPlatfromSDK v18 (1.50) or later
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User")
		FString GetDisplayName();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User")
		FString GetPresence();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User")
		FString GetPresenceDeeplinkMessage();

	// Requires OculusPlatfromSDK 1.41 or later
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User")
		FString GetPresenceDestinationApiName();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User")
		EOBP_UserPresenceStatus GetPresenceStatus();

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