// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_RoomInviteNotificationArray.h"
#include "OBP_Requests_Notification.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNotification_GetNextRoomInviteNotificationArrayPage, const TArray<UOBP_RoomInviteNotification*>&, RoomInvites, UOBP_RoomInviteNotificationArray*, NextRoomInviteNotificationArrayPage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNotification_GetRoomInvites, const TArray<UOBP_RoomInviteNotification*>&, RoomInvites, UOBP_RoomInviteNotificationArray*, RoomInviteArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNotification_MarkAsRead);

// --------------------
// ovr_Requests_Notification.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Notification_GetNextRoomInviteNotificationArrayPage : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_RoomInviteNotificationArray* RoomInviteNotificationArray;

	UPROPERTY(BlueprintAssignable)
		FNotification_GetNextRoomInviteNotificationArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FNotification_GetNextRoomInviteNotificationArrayPage OnFailure;

	/* Get the next page of entries */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Notification_GetNextRoomInviteNotificationArrayPage* GetNextRoomInviteNotificationArrayPage(UObject* WorldContextObject, UOBP_RoomInviteNotificationArray* RoomInviteNotificationArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Notification_GetRoomInvites : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FNotification_GetRoomInvites OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FNotification_GetRoomInvites OnFailure;

	/* Get the next page of entries */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Notification_GetRoomInvites* GetRoomInvites(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Notification_MarkAsRead : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString NotificationID;

	UPROPERTY(BlueprintAssignable)
		FNotification_MarkAsRead OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FNotification_MarkAsRead OnFailure;

	/* Mark a notification as read. This causes it to disappear from the Universal Menu, the Oculus App, Oculus Home, and in-app retrieval. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Notification_MarkAsRead* MarkAsRead(UObject* WorldContextObject, FString NotificationID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};