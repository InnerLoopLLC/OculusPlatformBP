// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_RoomInviteNotification.h"

// --------------------
// Initializers
// --------------------

UOBP_RoomInviteNotification::UOBP_RoomInviteNotification(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// ovr_RoomInviteNotification.h
// --------------------

FString UOBP_RoomInviteNotification::GetID()
{
	return OBP_Int64ToFString(ovr_RoomInviteNotification_GetID(ovrRoomInviteNotificationHandle));
}

FString UOBP_RoomInviteNotification::GetRoomID()
{
	return OBP_Int64ToFString(ovr_RoomInviteNotification_GetRoomID(ovrRoomInviteNotificationHandle));
}

FString UOBP_RoomInviteNotification::GetSenderID()
{
	return OBP_Int64ToFString(ovr_RoomInviteNotification_GetSenderID(ovrRoomInviteNotificationHandle));
}

int32 UOBP_RoomInviteNotification::GetSentTime()
{
	return ovr_RoomInviteNotification_GetSentTime(ovrRoomInviteNotificationHandle);
}