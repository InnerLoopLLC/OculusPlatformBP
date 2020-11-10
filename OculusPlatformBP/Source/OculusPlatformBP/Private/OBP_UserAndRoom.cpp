// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_UserAndRoom.h"

// --------------------
// Initializers
// --------------------

UOBP_UserAndRoom::UOBP_UserAndRoom(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_UserAndRoom.h
// --------------------

UOBP_Room* UOBP_UserAndRoom::GetRoom()
{
	auto RoomToGet = NewObject<UOBP_Room>();
	RoomToGet->ovrRoomHandle = ovr_UserAndRoom_GetRoom(ovrUserAndRoomHandle);
	return RoomToGet;
}

UOBP_User* UOBP_UserAndRoom::GetUser()
{
	auto UserToGet = NewObject<UOBP_User>();
	UserToGet->ovrUserHandle = ovr_UserAndRoom_GetUser(ovrUserAndRoomHandle);
	return UserToGet;
}