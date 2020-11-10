// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_AchievementProgress.h"
#include "OBP_AchievementProgressArray.generated.h"

// --------------------
// OVR_AchievementProgressArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_AchievementProgressArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrAchievementProgressArray* ovrAchievementProgressArrayHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Achievement Progress Array")
		UOBP_AchievementProgress* GetElement(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Achievement Progress Array")
		FString GetNextUrl();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Achievement Progress Array")
		int32 GetSize();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Achievement Progress Array")
		bool HasNextPage();
};