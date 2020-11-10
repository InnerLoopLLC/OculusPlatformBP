// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_UserArray.h"

// --------------------
// Initializers
// --------------------

UOBP_UserArray::UOBP_UserArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_UserArray.h
// --------------------

UOBP_User* UOBP_UserArray::GetElement(int32 Index)
{
	auto UserToGet = NewObject<UOBP_User>();
	UserToGet->ovrUserHandle = ovr_UserArray_GetElement(ovrUserArrayHandle, Index);
	return UserToGet;
}

FString UOBP_UserArray::GetNextUrl()
{
	return ovr_UserArray_GetNextUrl(ovrUserArrayHandle);
}

int32 UOBP_UserArray::GetSize()
{
	return ovr_UserArray_GetSize(ovrUserArrayHandle);
}

bool UOBP_UserArray::HasNextPage()
{
	return ovr_UserArray_HasNextPage(ovrUserArrayHandle);
}