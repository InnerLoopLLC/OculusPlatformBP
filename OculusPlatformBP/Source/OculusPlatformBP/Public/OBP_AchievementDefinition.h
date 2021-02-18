// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_AchievementDefinition.generated.h"

// --------------------
// OVR_AchievementDefinition.h
// --------------------
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_AchievementDefinition : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrAchievementDefinition* ovrAchievementDefinitionHandle;

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Achievements|Achievement Definition")
		FString GetName();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Achievements|Achievement Definition")
		int32 GetBitfieldLength();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Achievements|Achievement Definition")
		int32 GetTarget();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Achievements|Achievement Definition")
		EOBP_AchievementType GetType();
};