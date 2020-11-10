// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_UserAndRoomArray.h"

// --------------------
// Initializers
// --------------------

UOBP_UserAndRoomArray::UOBP_UserAndRoomArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_UserAndRoomArray.h
// --------------------

UOBP_UserAndRoom* UOBP_UserAndRoomArray::GetElement(int32 Index)
{
	auto UserAndRoomToGet = NewObject<UOBP_UserAndRoom>();
	UserAndRoomToGet->ovrUserAndRoomHandle = ovr_UserAndRoomArray_GetElement(ovrUserAndRoomArrayHandle, Index);
	return UserAndRoomToGet;
}

FString UOBP_UserAndRoomArray::GetNextUrl()
{
	return ovr_UserAndRoomArray_GetNextUrl(ovrUserAndRoomArrayHandle);
}

int32 UOBP_UserAndRoomArray::GetSize()
{
	return ovr_UserAndRoomArray_GetSize(ovrUserAndRoomArrayHandle);
}

bool UOBP_UserAndRoomArray::HasNextPage()
{
	return ovr_UserAndRoomArray_HasNextPage(ovrUserAndRoomArrayHandle);
}