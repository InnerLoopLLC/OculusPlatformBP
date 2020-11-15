// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_RoomInviteNotificationArray.h"

// --------------------
// Initializers
// --------------------

UOBP_RoomInviteNotificationArray::UOBP_RoomInviteNotificationArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_RoomInviteNotificationArray.h
// --------------------

UOBP_RoomInviteNotification* UOBP_RoomInviteNotificationArray::GetElement(int32 Index)
{
	auto RoomInviteNotification = NewObject<UOBP_RoomInviteNotification>();
	RoomInviteNotification->ovrRoomInviteNotificationHandle = ovr_RoomInviteNotificationArray_GetElement(ovrRoomInviteNotificationArrayHandle, Index);
	return RoomInviteNotification;
}

FString UOBP_RoomInviteNotificationArray::GetNextUrl()
{
	return ovr_RoomInviteNotificationArray_GetNextUrl(ovrRoomInviteNotificationArrayHandle);
}

int32 UOBP_RoomInviteNotificationArray::GetSize()
{
	return ovr_RoomInviteNotificationArray_GetSize(ovrRoomInviteNotificationArrayHandle);
}

bool UOBP_RoomInviteNotificationArray::HasNextPage()
{
	return ovr_RoomInviteNotificationArray_HasNextPage(ovrRoomInviteNotificationArrayHandle);
}