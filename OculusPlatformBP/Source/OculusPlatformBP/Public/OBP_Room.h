// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_DataStore.h"
#include "OBP_User.h"
#include "OBP_UserArray.h"
#include "OBP_TeamArray.h"
#include "OBP_Room.generated.h"

// --------------------
// ovr_Room.h
// --------------------
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Room : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrRoom* ovrRoomHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room")
		UOBP_DataStore* GetDataStore();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room")
		UOBP_UserArray* GetInvitedUsers();

	/* ovr_MatchmakingEnqueuedUserArray.h needed
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room")
		UOBP_MatchmakingEnqueuedUserArray* GetMatchedUsers(); */

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room")
		UOBP_User* GetOwner();

	/* Requires OculusPlatfromSDK 1.40 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room")
		UOBP_TeamArray* GetTeams();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room")
		UOBP_UserArray* GetUsers();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room")
		FString GetApplicationID();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room")
		FString GetDescription();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room")
		FString GetID();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room")
		bool GetIsMembershipLocked();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room")
		EOBP_RoomJoinPolicy GetJoinPolicy();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room")
		EOBP_RoomJoinability GetJoinability();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room")
		int32 GetMaxUsers();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room")
		FString GetName();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room")
		EOBP_RoomType GetType();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room")
		int32 GetVersion();
};