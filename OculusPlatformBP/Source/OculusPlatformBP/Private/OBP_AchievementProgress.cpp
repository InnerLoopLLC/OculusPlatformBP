// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_AchievementProgress.h"

// --------------------
// Initializers
// --------------------

UOBP_AchievementProgress::UOBP_AchievementProgress(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_AchievementProgress.h
// --------------------

FString UOBP_AchievementProgress::GetBitfield()
{
	return ovr_AchievementProgress_GetBitfield(ovrAchievementProgressHandle);
}

int32 UOBP_AchievementProgress::GetCount()
{
	return ovr_AchievementProgress_GetCount(ovrAchievementProgressHandle);
}

bool UOBP_AchievementProgress::GetIsUnlocked()
{
	return ovr_AchievementProgress_GetIsUnlocked(ovrAchievementProgressHandle);
}

FString UOBP_AchievementProgress::GetName()
{
	return ovr_AchievementProgress_GetName(ovrAchievementProgressHandle);
}

int32 UOBP_AchievementProgress::GetUnlockTime()
{
	return ovr_AchievementProgress_GetUnlockTime(ovrAchievementProgressHandle);
}