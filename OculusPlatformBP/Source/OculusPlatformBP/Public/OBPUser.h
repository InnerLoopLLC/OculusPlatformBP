// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBPUser.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetUser, UOBP_User*, User);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetAccessToken, FString, AccessToken);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetLoggedInUser, UOBP_User*, LoggedInUser);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetLoggedInUserFriends, UOBP_User*, LoggedInUser);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetLoggedInUserFriendsAndRooms, UOBP_User*, LoggedInUser);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetLoggedInUserRecentlyMetUsersAndRooms, UOBP_User*, LoggedInUser);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetNextUserAndRoomArrayPage, UOBP_User*, LoggedInUser);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetNextUserArrayPage, UOBP_User*, LoggedInUser);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetOrgScopedID, int64, OrgScopedID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetSdkAccounts, UOBP_User*, LoggedInUser);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetUserProof, UOBP_User*, LoggedInUser);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLaunchFriendRequestFlow, UOBP_User*, LoggedInUser);

// --------------------
// OVR_Requests_User.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetUser : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	int64 ovrId;

	UPROPERTY(BlueprintAssignable)
		FGetUser OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetUser OnFailure;

	/* Retrieve the user with the given ID. This might fail if the ID is invalid or the user is blocked.
	NOTE: Users will have a unique ID per application.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetUser* GetUser(UObject* WorldContextObject, int64 UserID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetAccessToken : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetAccessToken OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetAccessToken OnFailure;

	/*Return an access token for this user, suitable for making REST calls against graph.oculus.com.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetAccessToken* GetAccessToken(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetLoggedInUser : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetLoggedInUser OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetLoggedInUser OnFailure;

	/*Retrieve the currently signed in user. This call is available offline.
	NOTE: This will not return the user's presence as it should always be 'online' in your application.
	NOTE: Users will have a unique ID per application.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetLoggedInUser* GetLoggedInUser(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetLoggedInUserFriends : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetLoggedInUserFriends OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetLoggedInUserFriends OnFailure;

	/*Retrieve a list of the logged in user's friends.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetLoggedInUserFriends* GetLoggedInUserFriends(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetOrgScopedID : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	int64 UserID;

	UPROPERTY(BlueprintAssignable)
		FGetOrgScopedID OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetOrgScopedID OnFailure;

	/*returns an ovrID which is unique per org. allows different apps within the same org to identify the user.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetOrgScopedID* GetOrgScopedID(UObject* WorldContextObject, int64 UserID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_LaunchProfile : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	int64 UserID;

	/*Launch the profile of the given user. The profile surfaces information about the user and supports relevant actions that the viewer may take on that user, e.g. sending a friend request.
	Note: Only works on mobile.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_LaunchProfile* LaunchProfile(UObject* WorldContextObject, int64 UserID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

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