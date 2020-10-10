// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBPUser.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetUser, UOBP_User*, User);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetAccessToken, FString, AccessToken);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetLoggedInUser, UOBP_User*, LoggedInUser);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetLoggedInUserFriends, UOBP_UserArray*, LoggedInUserFriends);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetLoggedInUserFriendsAndRooms, UOBP_UserAndRoomArray*, LoggedInUserFriendsAndRooms);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetLoggedInUserRecentlyMetUsersAndRooms, UOBP_UserAndRoomArray*, LoggedInUserRecentlyMetUsersAndRooms);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetNextUserAndRoomArrayPage, UOBP_UserAndRoomArray*, NextUserAndRoomArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetNextUserArrayPage, UOBP_UserArray*, NextUserArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetOrgScopedID, int64, OrgScopedID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetSdkAccounts, UOBP_SdkAccountArray*, SdkAccounts);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetUserProof, FString, UserProof);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLaunchFriendRequestFlow, bool, bDidCancel, bool, bDidSendRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLaunchProfile);

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
class OCULUSPLATFORMBP_API UOBP_GetLoggedInUserFriendsAndRooms : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetLoggedInUserFriendsAndRooms OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetLoggedInUserFriendsAndRooms OnFailure;

	/*Retrieve a list of the logged in user's friends and any rooms they might be in.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetLoggedInUserFriendsAndRooms* GetLoggedInUserFriendsAndRooms(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetLoggedInUserRecentlyMetUsersAndRooms : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_UserOptions* UserOptions;

	UPROPERTY(BlueprintAssignable)
		FGetLoggedInUserRecentlyMetUsersAndRooms OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetLoggedInUserRecentlyMetUsersAndRooms OnFailure;

	/*Returns a list of users that the logged in user was in a room with recently, sorted by relevance, along with any rooms they might be in. 
	All you need to do to use this method is to use our Rooms API, and we will track the number of times users are together, their most recent encounter, and the amount of time they spend together.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetLoggedInUserRecentlyMetUsersAndRooms* GetLoggedInUserRecentlyMetUsersAndRooms(UObject* WorldContextObject, UOBP_UserOptions* UserOptions);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetNextUserAndRoomArrayPage : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_UserAndRoomArray* UserAndRoomArray;

	UPROPERTY(BlueprintAssignable)
		FGetNextUserAndRoomArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetNextUserAndRoomArrayPage OnFailure;

	/*Get the next page of entries*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetNextUserAndRoomArrayPage* GetNextUserAndRoomArrayPage(UObject* WorldContextObject, UOBP_UserAndRoomArray* UserAndRoomArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetNextUserArrayPage : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_UserArray* UserArray;

	UPROPERTY(BlueprintAssignable)
		FGetNextUserArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetNextUserArrayPage OnFailure;

	/*Get the next page of entries*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetNextUserArrayPage* GetNextUserArrayPage(UObject* WorldContextObject, UOBP_UserArray* UserArray);

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
class OCULUSPLATFORMBP_API UOBP_GetSdkAccounts : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetSdkAccounts OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetSdkAccounts OnFailure;

	/*Returns all accounts belonging to this user. Accounts are the Oculus user and x-users that are linked to this user.
	Note: This node doesn't do anything yet.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetSdkAccounts* GetSdkAccounts(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetUserProof : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	int64 UserID;

	UPROPERTY(BlueprintAssignable)
		FGetUserProof OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetUserProof OnFailure;

	/*Part of the scheme to confirm the identity of a particular user in your backend. You can pass the result of ovr_User_GetUserProof() and a user ID from ovr_User_Get() to your your backend. Your server can then use our api to verify identity. 'https://graph.oculus.com/user_nonce_validate?nonce=USER_PROOF&user_id=USER_ID&access_token=ACCESS_TOKEN'
	NOTE: The nonce is only good for one check and then it is invalidated.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetUserProof* GetUserProof(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_LaunchFriendRequestFlow : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	int64 UserID;

	UPROPERTY(BlueprintAssignable)
		FLaunchFriendRequestFlow OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FLaunchFriendRequestFlow OnFailure;

	/*Launch the flow for sending a friend request to a user.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_LaunchFriendRequestFlow* LaunchFriendRequestFlow(UObject* WorldContextObject, int64 UserID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_LaunchProfile : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	int64 UserID;

	UPROPERTY(BlueprintAssignable)
		FLaunchProfile OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FLaunchProfile OnFailure;

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

	/*Intended to be parsed and used to deeplink to parts of the app.
	Requires OculusPlatfromSDK 1.40 or later*/
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

// --------------------
// OVR_UserArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_UserArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrUserArray* ovrUserArrayHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|UserArray")
		UOBP_User* GetElement(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|UserArray")
		FString GetNextUrl();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|UserArray")
		int32 GetSize();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|UserArray")
		bool HasNextPage();
};

// --------------------
// OVR_UserAndRoom.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_UserAndRoom : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrUserAndRoom* ovrUserAndRoomHandle;

	/* Still need to implement ovr_Room.h
	This method may return null. This indicates that the value is not present or that the curent app or user is not permitted to access it.
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|UserAndRoom")
		UOBP_Room* GetRoom();
	*/

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|UserAndRoom")
		UOBP_User* GetUser();
};

// --------------------
// OVR_UserAndRoomArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_UserAndRoomArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrUserAndRoomArray* ovrUserAndRoomArrayHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|UserAndRoomArray")
		UOBP_UserAndRoom* GetElement(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|UserAndRoomArray")
		FString GetNextUrl();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|UserAndRoomArray")
		int32 GetSize();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|UserAndRoomArray")
		bool HasNextPage();
};

// --------------------
// OVR_UserOptions.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_UserOptions : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrUserOptions* ovrUserOptionsHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Options")
		UOBP_UserOptions* CreateUserOptions();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Options")
		void DestroyUserOptions();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Options")
		void SetMaxUsers(int32 MaxUsers);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Options")
		void AddServiceProvider(EOBPServiceProvider ServiceProvider);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Options")
		void ClearServiceProviders();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Options")
		void SetTimeWindow(EOBPTimeWindow TimeWindow);
};

// --------------------
// OVR_SdkAccountArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_SdkAccountArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrSdkAccountArray* ovrSdkAccountArrayHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|SdkAccount")
		UOBP_SdkAccount* GetElement(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|SdkAccount")
		int32 GetSize();
};

// --------------------
// OVR_SdkAccount.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_SdkAccount : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrSdkAccount* ovrSdkAccountHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|SdkAccount")
		EOBPSdkAccountType GetAccountType();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|SdkAccount")
		int32 GetUserId();
};