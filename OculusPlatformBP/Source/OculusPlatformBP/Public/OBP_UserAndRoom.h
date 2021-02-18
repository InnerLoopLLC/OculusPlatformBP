// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_User.h"
#include "OBP_Room.h"
#include "OBP_UserAndRoom.generated.h"

// --------------------
// OVR_UserAndRoom.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_UserAndRoom : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrUserAndRoom* ovrUserAndRoomHandle;

	/* This method may return null. This indicates that the value is not present or that the curent app or user is not permitted to access it. */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User And Room")
		UOBP_Room* GetRoom();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User And Room")
		UOBP_User* GetUser();
};