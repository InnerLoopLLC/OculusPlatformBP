// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_RoomArray.h"

// --------------------
// Initializers
// --------------------

UOBP_RoomArray::UOBP_RoomArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_RoomArray.h
// --------------------

UOBP_Room* UOBP_RoomArray::GetElement(int32 Index)
{
	auto RoomToGet = NewObject<UOBP_Room>();
	RoomToGet->ovrRoomHandle = ovr_RoomArray_GetElement(ovrRoomArrayHandle, Index);
	return RoomToGet;
}

FString UOBP_RoomArray::GetNextUrl()
{
	return ovr_RoomArray_GetNextUrl(ovrRoomArrayHandle);
}

int32 UOBP_RoomArray::GetSize()
{
	return ovr_RoomArray_GetSize(ovrRoomArrayHandle);
}

bool UOBP_RoomArray::HasNextPage()
{
	return ovr_RoomArray_HasNextPage(ovrRoomArrayHandle);
}