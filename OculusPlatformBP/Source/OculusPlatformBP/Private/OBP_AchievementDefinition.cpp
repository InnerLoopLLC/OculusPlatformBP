// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_AchievementDefinition.h"

// --------------------
// Initializers
// --------------------

UOBP_AchievementDefinition::UOBP_AchievementDefinition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_AchievementDefinition.h
// --------------------

FString UOBP_AchievementDefinition::GetName()
{
	return ovr_AchievementDefinition_GetName(ovrAchievementDefinitionHandle);
}

int32 UOBP_AchievementDefinition::GetBitfieldLength()
{
	return ovr_AchievementDefinition_GetBitfieldLength(ovrAchievementDefinitionHandle);
}

int32 UOBP_AchievementDefinition::GetTarget()
{
	return ovr_AchievementDefinition_GetTarget(ovrAchievementDefinitionHandle);
}

EOBP_AchievementType UOBP_AchievementDefinition::GetType()
{
	switch (ovr_AchievementDefinition_GetType(ovrAchievementDefinitionHandle))
	{
	case ovrAchievement_TypeUnknown:
		return EOBP_AchievementType::Unknown;
	case ovrAchievement_TypeSimple:
		return EOBP_AchievementType::Simple;
	case ovrAchievement_TypeBitfield:
		return EOBP_AchievementType::Bitfield;
	case ovrAchievement_TypeCount:
		return EOBP_AchievementType::Count;
	default:
		return EOBP_AchievementType::Unknown;
	}
}