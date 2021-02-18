// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_AchievementDefinition.h"
#include "OBP_AchievementDefinitionArray.generated.h"

// --------------------
// OVR_AchievementDefinitionArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_AchievementDefinitionArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrAchievementDefinitionArray* ovrAchievementDefinitionArrayHandle;

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Achievements|Achievement Definition Array")
		UOBP_AchievementDefinition* GetElement(int32 Index);

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Achievements|Achievement Definition Array")
		FString GetNextUrl();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Achievements|Achievement Definition Array")
		int32 GetSize();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Achievements|Achievement Definition Array")
		bool HasNextPage();
};