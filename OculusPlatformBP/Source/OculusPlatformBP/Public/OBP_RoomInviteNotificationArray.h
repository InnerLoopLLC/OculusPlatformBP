// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_RoomInviteNotification.h"
#include "OBP_RoomInviteNotificationArray.generated.h"

// --------------------
// ovr_RoomInviteNotificationArray.h
// --------------------
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_RoomInviteNotificationArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrRoomInviteNotificationArray* ovrRoomInviteNotificationArrayHandle;

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room Invite Notification")
		UOBP_RoomInviteNotification* GetElement(int32 Index);

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room Invite Notification")
		FString GetNextUrl();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room Invite Notification")
		int32 GetSize();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room Invite Notification")
		bool HasNextPage();
};