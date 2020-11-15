// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_UserArray.h"
#include "OBP_User.h"
#include "OBP_Room.h"
#include "OBP_Party.generated.h"

// --------------------
// OVR_Party.h
// --------------------
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Party : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrParty* ovrPartyHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Party|Party")
		UOBP_UserArray* GetInvitedUsers();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Party|Party")
		UOBP_User* GetLeader();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Party|Party")
		UOBP_Room* GetRoom();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Party|Party")
		UOBP_UserArray* GetUsers();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Party|Party")
		FString GetID();
};