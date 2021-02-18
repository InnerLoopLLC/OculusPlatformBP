// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_AchievementProgress.generated.h"

// --------------------
// OVR_AchievementProgress.h
// --------------------
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_AchievementProgress : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrAchievementProgress* ovrAchievementProgressHandle;

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Achievements|Achievement Progress")
		FString GetBitfield();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Achievements|Achievement Progress")
		int32 GetCount();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Achievements|Achievement Progress")
		bool GetIsUnlocked();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Achievements|Achievement Progress")
		FString GetName();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Achievements|Achievement Progress")
		int32 GetUnlockTime();
};