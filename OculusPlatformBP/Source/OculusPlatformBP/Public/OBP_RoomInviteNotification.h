// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_RoomInviteNotification.generated.h"

// --------------------
// ovr_RoomInviteNotification.h
// --------------------
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_RoomInviteNotification : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrRoomInviteNotification* ovrRoomInviteNotificationHandle;

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room Invite Notification")
		FString GetID();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room Invite Notification")
		FString GetRoomID();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room Invite Notification")
		FString GetSenderID();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room Invite Notification")
		int32 GetSentTime();
};