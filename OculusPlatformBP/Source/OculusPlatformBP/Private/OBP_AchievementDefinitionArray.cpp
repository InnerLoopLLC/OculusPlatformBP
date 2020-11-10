// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_AchievementDefinitionArray.h"

// --------------------
// Initializers
// --------------------

UOBP_AchievementDefinitionArray::UOBP_AchievementDefinitionArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_AchievementDefinitionArray.h
// --------------------

UOBP_AchievementDefinition* UOBP_AchievementDefinitionArray::GetElement(int32 Index)
{
	auto AchievementDefinitionToGet = NewObject<UOBP_AchievementDefinition>();
	AchievementDefinitionToGet->ovrAchievementDefinitionHandle = ovr_AchievementDefinitionArray_GetElement(ovrAchievementDefinitionArrayHandle, Index);
	return AchievementDefinitionToGet;
}

FString UOBP_AchievementDefinitionArray::GetNextUrl()
{
	return ovr_AchievementDefinitionArray_GetNextUrl(ovrAchievementDefinitionArrayHandle);
}

int32 UOBP_AchievementDefinitionArray::GetSize()
{
	return ovr_AchievementDefinitionArray_GetSize(ovrAchievementDefinitionArrayHandle);
}

bool UOBP_AchievementDefinitionArray::HasNextPage()
{
	return ovr_AchievementDefinitionArray_HasNextPage(ovrAchievementDefinitionArrayHandle);
}