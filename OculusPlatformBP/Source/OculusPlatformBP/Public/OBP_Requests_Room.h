// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_Room.h"
#include "OBP_RoomArray.h"
#include "OBP_UserArray.h"
#include "OBP_Requests_Room.generated.h"

/* NOTE: Not all room functions have been implemented. Join and invite functionality will need additional work. */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRoom_CreateAndJoinPrivate2, UOBP_Room*, Room);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRoom_Get, UOBP_Room*, Room);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRoom_GetCurrent, UOBP_Room*, Room);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRoom_GetCurrentForUser, UOBP_Room*, Room);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRoom_GetInvitableUsers2, const TArray<UOBP_User*>&, Users, UOBP_UserArray*, UserArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRoom_GetModeratedRooms, const TArray<UOBP_Room*>&, Rooms, UOBP_RoomArray*, RoomArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRoom_GetNextRoomArrayPage, const TArray<UOBP_Room*>&, Rooms, UOBP_RoomArray*, RoomArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRoom_InviteUser, UOBP_Room*, Room);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRoom_Join2, UOBP_Room*, Room);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRoom_KickUser, UOBP_Room*, Room);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRoom_LaunchInvitableUserFlow);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRoom_Leave, UOBP_Room*, Room);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRoom_SetDescription, UOBP_Room*, Room);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRoom_UpdateDataStore, UOBP_Room*, Room);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRoom_UpdateMembershipLockStatus, UOBP_Room*, Room);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRoom_UpdateOwner);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRoom_UpdatePrivateRoomJoinPolicy, UOBP_Room*, Room);

// --------------------
// ovr_Requests_Room.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Room_CreateAndJoinPrivate2 : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	EOBP_RoomJoinPolicy JoinPolicy;
	int32 MaxUsers;
	FOBP_RoomOptionsStruct RoomOptions;

	UPROPERTY(BlueprintAssignable)
		FRoom_CreateAndJoinPrivate2 OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRoom_CreateAndJoinPrivate2 OnFailure;

	/* Creates a new private (client controlled) room and adds the caller to it.
	This type of room is good for matches where the user wants to play with friends, as they're primarially discoverable by examining which rooms your friends are in.
	NOTE: This function probably won't work as expected until OSS-Oculus is directly supported */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Room_CreateAndJoinPrivate2* CreateAndJoinPrivate2(UObject* WorldContextObject, EOBP_RoomJoinPolicy JoinPolicy, int32 MaxUsers, FOBP_RoomOptionsStruct RoomOptions);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Room_Get : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString RoomID;

	UPROPERTY(BlueprintAssignable)
		FRoom_Get OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRoom_Get OnFailure;

	/* Allows arbitrary rooms for the application to be loaded. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Room_Get* GetRoom(UObject* WorldContextObject, FString RoomID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Room_GetCurrent : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FRoom_GetCurrent OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRoom_GetCurrent OnFailure;

	/* Easy loading of the room you're currently in. If you don't want live updates on your current room (by using subscribeToUpdates), you can use this to refresh the data. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Room_GetCurrent* GetCurrentRoom(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Room_GetCurrentForUser : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString UserID;

	UPROPERTY(BlueprintAssignable)
		FRoom_GetCurrentForUser OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRoom_GetCurrentForUser OnFailure;

	/* Allows the current room for a given user to be loaded. Remember that the user's privacy settings may not allow their room to be loaded. 
	Because of this, it's often possible to load the users in a room, but not to take those users and load their room. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Room_GetCurrentForUser* GetCurrentRoomForUser(UObject* WorldContextObject, FString UserID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Room_GetInvitableUsers2 : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FOBP_RoomOptionsStruct RoomOptions;

	UPROPERTY(BlueprintAssignable)
		FRoom_GetInvitableUsers2 OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRoom_GetInvitableUsers2 OnFailure;

	/* Loads a list of users you can invite to a room. These are pulled from your friends list and recently met lists and filtered for relevance and interest.
	If the room cannot be joined, this list will be empty. By default, the invitable users returned will be for the user's current room.
	If your application grouping was created after September 9 2017, recently met users will be included by default.
	If your application grouping was created before then, you can go to edit the setting in the "Rooms and Matchmaking" section of Platform Services at dashboard.oculus.com
	NOTE: This function probably won't work as expected until OSS-Oculus is directly supported */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Room_GetInvitableUsers2* GetInvitableUsers2(UObject* WorldContextObject, FOBP_RoomOptionsStruct RoomOptions);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Room_GetModeratedRooms : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FRoom_GetModeratedRooms OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRoom_GetModeratedRooms OnFailure;

	/* Fetches the list of moderated rooms created for the application.
	NOTE: This function probably won't work as expected until OSS-Oculus is directly supported */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Room_GetModeratedRooms* GetModeratedRooms(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Room_GetNextRoomArrayPage : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_RoomArray* RoomArray;

	UPROPERTY(BlueprintAssignable)
		FRoom_GetNextRoomArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRoom_GetNextRoomArrayPage OnFailure;

	/* Get the next page of entries */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Room_GetNextRoomArrayPage* GetNextRoomArrayPage(UObject* WorldContextObject, UOBP_RoomArray* RoomArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Room_InviteUser : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString RoomID;
	FString InviteToken;

	UPROPERTY(BlueprintAssignable)
		FRoom_InviteUser OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRoom_InviteUser OnFailure;

	/* Invites a user to the specified room. 
	They will receive a notification via ovrNotification_Room_InviteReceived if they are in your game, and/or they can poll for room invites using ovr_Notification_GetRoomInvites(). */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Room_InviteUser* InviteUser(UObject* WorldContextObject, FString RoomID, FString InviteToken);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Room_Join2 : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString RoomID;
	FOBP_RoomOptionsStruct RoomOptions;

	UPROPERTY(BlueprintAssignable)
		FRoom_Join2 OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRoom_Join2 OnFailure;

	/* Joins the target room (leaving the one you're currently in). */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Room_Join2* Join2(UObject* WorldContextObject, FString RoomID, FOBP_RoomOptionsStruct RoomOptions);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Room_KickUser : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString RoomID;
	FString UserID;
	int32 KickDurationSeconds;

	UPROPERTY(BlueprintAssignable)
		FRoom_KickUser OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRoom_KickUser OnFailure;

	/* Easy loading of the room you're currently in. If you don't want live updates on your current room (by using subscribeToUpdates), you can use this to refresh the data. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Room_KickUser* KickUser(UObject* WorldContextObject, FString RoomID, FString UserID, int32 KickDurationSeconds);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Room_LaunchInvitableUserFlow : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString RoomID;

	UPROPERTY(BlueprintAssignable)
		FRoom_LaunchInvitableUserFlow OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRoom_LaunchInvitableUserFlow OnFailure;

	/* Launch the invitable user flow to invite to the logged in user's current room. 
	This is intended to be a nice shortcut for developers not wanting to build out their own Invite UI although it has the same rules as if you build it yourself. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Room_LaunchInvitableUserFlow* LaunchInvitableUserFlow(UObject* WorldContextObject, FString RoomID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Room_Leave : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString RoomID;

	UPROPERTY(BlueprintAssignable)
		FRoom_Leave OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRoom_Leave OnFailure;

	/* Removes you from your current room. Returns the solo room you are now in if it succeeds */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Room_Leave* Leave(UObject* WorldContextObject, FString RoomID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Room_SetDescription : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString RoomID;
	FString Description;

	UPROPERTY(BlueprintAssignable)
		FRoom_SetDescription OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRoom_SetDescription OnFailure;

	/* Allows the room owner to set the description of their room. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Room_SetDescription* SetDescription(UObject* WorldContextObject, FString RoomID, FString Description);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Room_UpdateDataStore : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString RoomID;

	UPROPERTY(BlueprintAssignable)
		FRoom_UpdateDataStore OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRoom_UpdateDataStore OnFailure;

	/* Allows the room owner to update the data store (set of key value pairs) of their room.
	NOTE: Room datastores only allow string values. If you provide int or double values, this returns an error. 
	THIS NODE IS NOT YET FUNCTIONAL */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Room_UpdateDataStore* UpdateDataStore(UObject* WorldContextObject, FString RoomID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Room_UpdateMembershipLockStatus : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString RoomID;
	EOBP_RoomMembershipLockStatus MembershipLockStatus;

	UPROPERTY(BlueprintAssignable)
		FRoom_UpdateMembershipLockStatus OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRoom_UpdateMembershipLockStatus OnFailure;

	/* Disallow new members from being able to join the room. 
	This will prevent joins from ovr_Room_Join(), invites, 'Join From Home', etc. 
	Users that are in the room at the time of lockdown WILL be able to rejoin. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Room_UpdateMembershipLockStatus* UpdateRoomMembershipLockStatus(UObject* WorldContextObject, FString RoomID, EOBP_RoomMembershipLockStatus MembershipLockStatus);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Room_UpdateOwner : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString RoomID;
	FString UserID;

	UPROPERTY(BlueprintAssignable)
		FRoom_UpdateOwner OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRoom_UpdateOwner OnFailure;

	/* Allows the room owner to transfer ownership to someone else. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Room_UpdateOwner* UpdateOwner(UObject* WorldContextObject, FString RoomID, FString UserID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Room_UpdatePrivateRoomJoinPolicy : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString RoomID;
	EOBP_RoomJoinPolicy JoinPolicy;

	UPROPERTY(BlueprintAssignable)
		FRoom_UpdatePrivateRoomJoinPolicy OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRoom_UpdatePrivateRoomJoinPolicy OnFailure;

	/* Sets the join policy of the user's private room. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Room_UpdatePrivateRoomJoinPolicy* UpdatePrivateRoomJoinPolicy(UObject* WorldContextObject, FString RoomID, EOBP_RoomJoinPolicy JoinPolicy);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};