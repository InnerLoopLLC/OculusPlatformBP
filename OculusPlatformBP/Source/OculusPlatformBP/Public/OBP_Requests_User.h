// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_User.h"
#include "OBP_UserArray.h"
#include "OBP_UserAndRoomArray.h"
#include "OBP_SdkAccountArray.h"
#include "OBP_Requests_User.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUser_GetUser, UOBP_User*, User);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUser_GetAccessToken, FString, AccessToken);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUser_GetLoggedInUser, UOBP_User*, LoggedInUser);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUser_GetLoggedInUserFriends, const TArray<UOBP_User*>&, Users, UOBP_UserArray*, UserArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUser_GetLoggedInUserFriendsAndRooms, const TArray<UOBP_UserAndRoom*>&, UsersAndRooms, UOBP_UserAndRoomArray*, UserAndRoomArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUser_GetLoggedInUserRecentlyMetUsersAndRooms, const TArray<UOBP_UserAndRoom*>&, UsersAndRooms, UOBP_UserAndRoomArray*, UserAndRoomArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUser_GetNextUserAndRoomArrayPage, const TArray<UOBP_UserAndRoom*>&, UsersAndRooms, UOBP_UserAndRoomArray*, UserAndRoomArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUser_GetNextUserArrayPage, const TArray<UOBP_User*>&, Users, UOBP_UserArray*, UserArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUser_GetOrgScopedID, FString, OrgScopedID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUser_GetSdkAccounts, const TArray<UOBP_SdkAccount*>&, SdkAccounts, UOBP_SdkAccountArray*, SdkAccountArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUser_GetUserProof, FString, UserProof);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUser_LaunchFriendRequestFlow, bool, bDidCancel, bool, bDidSendRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUser_LaunchProfile);

// --------------------
// OVR_Requests_User.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_User_GetUser : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString ovrId;

	UPROPERTY(BlueprintAssignable)
		FUser_GetUser OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FUser_GetUser OnFailure;

	/* Retrieve the user with the given ID. This might fail if the ID is invalid or the user is blocked.
	NOTE: Users will have a unique ID per application.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_User_GetUser* GetUser(UObject* WorldContextObject, FString UserId);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_User_GetAccessToken : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FUser_GetAccessToken OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FUser_GetAccessToken OnFailure;

	/*Return an access token for this user, suitable for making REST calls against graph.oculus.com.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_User_GetAccessToken* GetAccessToken(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_User_GetLoggedInUser : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FUser_GetLoggedInUser OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FUser_GetLoggedInUser OnFailure;

	/*Retrieve the currently signed in user. This call is available offline.
	NOTE: This will not return the user's presence as it should always be 'online' in your application.
	NOTE: Users will have a unique ID per application.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_User_GetLoggedInUser* GetLoggedInUser(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_User_GetLoggedInUserFriends : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FUser_GetLoggedInUserFriends OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FUser_GetLoggedInUserFriends OnFailure;

	/*Retrieve a list of the logged in user's friends.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_User_GetLoggedInUserFriends* GetLoggedInUserFriends(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_User_GetLoggedInUserFriendsAndRooms : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FUser_GetLoggedInUserFriendsAndRooms OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FUser_GetLoggedInUserFriendsAndRooms OnFailure;

	/*Retrieve a list of the logged in user's friends and any rooms they might be in.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_User_GetLoggedInUserFriendsAndRooms* GetLoggedInUserFriendsAndRooms(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_User_GetLoggedInUserRecentlyMetUsersAndRooms : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FOBP_UserOptionsStruct UserOptions;

	UPROPERTY(BlueprintAssignable)
		FUser_GetLoggedInUserRecentlyMetUsersAndRooms OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FUser_GetLoggedInUserRecentlyMetUsersAndRooms OnFailure;

	/*Returns a list of users that the logged in user was in a room with recently, sorted by relevance, along with any rooms they might be in. 
	All you need to do to use this method is to use our Rooms API, and we will track the number of times users are together, their most recent encounter, and the amount of time they spend together.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_User_GetLoggedInUserRecentlyMetUsersAndRooms* GetLoggedInUserRecentlyMetUsersAndRooms(UObject* WorldContextObject, FOBP_UserOptionsStruct UserOptions);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_User_GetNextUserAndRoomArrayPage : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_UserAndRoomArray* UserAndRoomArray;

	UPROPERTY(BlueprintAssignable)
		FUser_GetNextUserAndRoomArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FUser_GetNextUserAndRoomArrayPage OnFailure;

	/*Get the next page of entries*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_User_GetNextUserAndRoomArrayPage* GetNextUserAndRoomArrayPage(UObject* WorldContextObject, UOBP_UserAndRoomArray* UserAndRoomArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_User_GetNextUserArrayPage : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_UserArray* UserArray;

	UPROPERTY(BlueprintAssignable)
		FUser_GetNextUserArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FUser_GetNextUserArrayPage OnFailure;

	/*Get the next page of entries*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_User_GetNextUserArrayPage* GetNextUserArrayPage(UObject* WorldContextObject, UOBP_UserArray* UserArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_User_GetOrgScopedID : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString UserID;

	UPROPERTY(BlueprintAssignable)
		FUser_GetOrgScopedID OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FUser_GetOrgScopedID OnFailure;

	/*returns an ovrID which is unique per org. allows different apps within the same org to identify the user.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_User_GetOrgScopedID* GetOrgScopedID(UObject* WorldContextObject, FString UserID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_User_GetSdkAccounts : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FUser_GetSdkAccounts OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FUser_GetSdkAccounts OnFailure;

	/*Returns all accounts belonging to this user. Accounts are the Oculus user and x-users that are linked to this user.
	Note: This node doesn't do anything yet.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_User_GetSdkAccounts* GetSdkAccounts(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_User_GetUserProof : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString UserID;

	UPROPERTY(BlueprintAssignable)
		FUser_GetUserProof OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FUser_GetUserProof OnFailure;

	/*Part of the scheme to confirm the identity of a particular user in your backend. You can pass the result of ovr_User_GetUserProof() and a user ID from ovr_User_Get() to your your backend. Your server can then use our api to verify identity. 'https://graph.oculus.com/user_nonce_validate?nonce=USER_PROOF&user_id=USER_ID&access_token=ACCESS_TOKEN'
	NOTE: The nonce is only good for one check and then it is invalidated.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_User_GetUserProof* GetUserProof(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_User_LaunchFriendRequestFlow : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString UserID;

	UPROPERTY(BlueprintAssignable)
		FUser_LaunchFriendRequestFlow OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FUser_LaunchFriendRequestFlow OnFailure;

	/*Launch the flow for sending a friend request to a user.
	Requires OculusPlatfromSDK 1.28 or later*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_User_LaunchFriendRequestFlow* LaunchFriendRequestFlow(UObject* WorldContextObject, FString UserID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_User_LaunchProfile : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString UserID;

	UPROPERTY(BlueprintAssignable)
		FUser_LaunchProfile OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FUser_LaunchProfile OnFailure;

	/*Launch the profile of the given user. The profile surfaces information about the user and supports relevant actions that the viewer may take on that user, e.g. sending a friend request.
	Note: Only works on mobile.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_User_LaunchProfile* LaunchProfile(UObject* WorldContextObject, FString UserID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};