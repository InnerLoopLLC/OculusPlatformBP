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

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room")
		UOBP_DataStore* GetDataStore();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room")
		UOBP_UserArray* GetInvitedUsers();

	/* ovr_MatchmakingEnqueuedUserArray.h needed
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room")
		UOBP_MatchmakingEnqueuedUserArray* GetMatchedUsers(); */

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room")
		UOBP_User* GetOwner();

	/* Requires OculusPlatfromSDK 1.40 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room")
		UOBP_TeamArray* GetTeams();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room")
		UOBP_UserArray* GetUsers();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room")
		FString GetApplicationID();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room")
		FString GetDescription();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room")
		FString GetID();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room")
		bool GetIsMembershipLocked();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room")
		EOBP_RoomJoinPolicy GetJoinPolicy();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room")
		EOBP_RoomJoinability GetJoinability();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room")
		int32 GetMaxUsers();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room")
		FString GetName();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room")
		EOBP_RoomType GetType();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room")
		int32 GetVersion();
};