// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBPUser.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGetUser, UOBP_User*, User);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGetLoggedInUser, UOBP_User*, LoggedInUser);

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetUser : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	int64 ovrId;

	UPROPERTY(BlueprintAssignable)
		FOnGetUser OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FOnGetUser OnFailure;

	/* Retrieve the user with the given ID. This might fail if the ID is invalid or the user is blocked.
	NOTE: Users will have a unique ID per application.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetUser* GetUser(UObject* WorldContextObject, int64 UserID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_LoggedInUser : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FOnGetLoggedInUser OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FOnGetLoggedInUser OnFailure;

	/*Retrieve the currently signed in user. This call is available offline.
	NOTE: This will not return the user's presence as it should always be 'online' in your application.
	NOTE: Users will have a unique ID per application.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_LoggedInUser* GetLoggedInUser(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_User : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	// --------------------
	// OVR_User.h (https://developer.oculus.com/reference/platform/v19/o_v_r_rich_presence_options_8h)
	// --------------------

	ovrUser* ovrUserHandle;

	/*A potentially non unique displayable name chosen by the user. Could also be the same as the oculus_ID
	Requires OculusPlatfromSDK v18 (1.50) or later*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User")
		FString GetDisplayName();

	/*Human readable string of what the user is currently doing. Not intended to be parsed as it might change at anytime or be translated*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User")
		FString GetPresence();

	/*Intended to be parsed and used to deeplink to parts of the app.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User")
		FString GetPresenceDeeplinkMessage();

	/*If provided, the destination this user is currently at in the app.
	Requires OculusPlatfromSDK 1.41 or later*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User")
		FString GetPresenceDestinationApiName();

	/*Enum value of what the user is currently doing.*/
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