// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_AchievementProgressArray.h"

// --------------------
// Initializers
// --------------------

UOBP_AchievementProgressArray::UOBP_AchievementProgressArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_AchievementProgressArray.h
// --------------------

UOBP_AchievementProgress* UOBP_AchievementProgressArray::GetElement(int32 Index)
{
	auto AchievementProgressToGet = NewObject<UOBP_AchievementProgress>();
	AchievementProgressToGet->ovrAchievementProgressHandle = ovr_AchievementProgressArray_GetElement(ovrAchievementProgressArrayHandle, Index);
	return AchievementProgressToGet;
}

FString UOBP_AchievementProgressArray::GetNextUrl()
{
	return ovr_AchievementProgressArray_GetNextUrl(ovrAchievementProgressArrayHandle);
}

int32 UOBP_AchievementProgressArray::GetSize()
{
	return ovr_AchievementProgressArray_GetSize(ovrAchievementProgressArrayHandle);
}

bool UOBP_AchievementProgressArray::HasNextPage()
{
	return ovr_AchievementProgressArray_HasNextPage(ovrAchievementProgressArrayHandle);
}