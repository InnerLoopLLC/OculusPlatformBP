// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_AchievementDefinitionArray.h"
#include "OBP_AchievementProgressArray.h"
#include "OBP_Requests_Achievements.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAchievements_AddCount, FString, AchievementName, bool, bDidJustUnlock);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAchievements_AddFields, FString, AchievementName, bool, bDidJustUnlock);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAchievements_GetAllDefinitions, const TArray<UOBP_AchievementDefinition*>&, AchievementDefinitions, UOBP_AchievementDefinitionArray*, AchievementDefinitionArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAchievements_GetAllProgress, const TArray<UOBP_AchievementProgress*>&, AchievementProgress, UOBP_AchievementProgressArray*, AchievementProgressArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAchievements_GetDefinitionsByName, const TArray<UOBP_AchievementDefinition*>&, AchievementDefinitions, UOBP_AchievementDefinitionArray*, AchievementDefinitionArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAchievements_GetNextAchievementDefinitionArrayPage, const TArray<UOBP_AchievementDefinition*>&, AchievementDefinitions, UOBP_AchievementDefinitionArray*, AchievementDefinitionArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAchievements_GetNextAchievementProgressArrayPage, const TArray<UOBP_AchievementProgress*>&, AchievementProgress, UOBP_AchievementProgressArray*, AchievementProgressArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAchievements_GetProgressByName, const TArray<UOBP_AchievementProgress*>&, AchievementProgress, UOBP_AchievementProgressArray*, AchievementProgressArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAchievements_Unlock, FString, AchievementName, bool, bDidJustUnlock);

// --------------------
// OVR_Requests_Achievements.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Achievements_AddCount : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString AchievementName;
	int32 Count;

	UPROPERTY(BlueprintAssignable)
		FAchievements_AddCount OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAchievements_AddCount OnFailure;

	/* Add 'count' to the achievement with the given name. This must be a COUNT achievement. 
	The largest number that is supported by this method is the max value of a signed 64-bit integer. 
	If the number is larger than that, it is clamped to that max value before being passed to the servers. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Achievements_AddCount* AddCount(UObject* WorldContextObject, FString AchievementName, int32 Count);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Achievements_AddFields : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString AchievementName;
	FString Fields;

	UPROPERTY(BlueprintAssignable)
		FAchievements_AddFields OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAchievements_AddFields OnFailure;

	/* Unlock fields of a BITFIELD achievement. 
	Parameters
		AchievementName - The name of the achievement to unlock
		Fields - A string containing either '0' or '1' characters. Every '1' will unlock the field in the corresponding position. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Achievements_AddFields* AddFields(UObject* WorldContextObject, FString AchievementName, FString Fields);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Achievements_GetAllDefinitions : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FAchievements_GetAllDefinitions OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAchievements_GetAllDefinitions OnFailure;

	/* Request all achievement definitions for the app. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Achievements_GetAllDefinitions* GetAllDefinitions(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Achievements_GetAllProgress : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FAchievements_GetAllProgress OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAchievements_GetAllProgress OnFailure;

	/* Request the progress for the user on all achievements in the app. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Achievements_GetAllProgress* GetAllProgress(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Achievements_GetDefinitionsByName : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	TArray<FString> Names;
	int32 Count;

	UPROPERTY(BlueprintAssignable)
		FAchievements_GetDefinitionsByName OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAchievements_GetDefinitionsByName OnFailure;

	/* Request the achievement definitions that match the specified names. 
	Note: For some reason, if count != 0 then this request will succeed but return no data. The API doesn't clearly explain what count is for. If count = 0 then it works fine, regardless of array size. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Achievements_GetDefinitionsByName* GetDefinitionsByName(UObject* WorldContextObject, TArray<FString> Names, int32 Count);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Achievements_GetNextAchievementDefinitionArrayPage : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_AchievementDefinitionArray* AchievementDefinitionArray = nullptr;

	UPROPERTY(BlueprintAssignable)
		FAchievements_GetNextAchievementDefinitionArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAchievements_GetNextAchievementDefinitionArrayPage OnFailure;

	/* Get the next page of entries. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Achievements_GetNextAchievementDefinitionArrayPage* GetNextAchievementDefinitionArrayPage(UObject* WorldContextObject, UOBP_AchievementDefinitionArray* AchievementDefinitionArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Achievements_GetNextAchievementProgressArrayPage : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_AchievementProgressArray* AchievementProgressArray = nullptr;

	UPROPERTY(BlueprintAssignable)
		FAchievements_GetNextAchievementProgressArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAchievements_GetNextAchievementProgressArrayPage OnFailure;

	/* Get the next page of entries. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Achievements_GetNextAchievementProgressArrayPage* GetNextAchievementProgressArrayPage(UObject* WorldContextObject, UOBP_AchievementProgressArray* AchievementProgressArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Achievements_GetProgressByName : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	TArray<FString> Names;
	int32 Count;

	UPROPERTY(BlueprintAssignable)
		FAchievements_GetProgressByName OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAchievements_GetProgressByName OnFailure;

	/* Request the user's progress on the specified achievements. 
	Note: For some reason, if count != 0 then this request will succeed but return no data. The API doesn't clearly explain what count is for. If count = 0 then it works fine, regardless of array size. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Achievements_GetProgressByName* GetProgressByName(UObject* WorldContextObject, TArray<FString> Names, int32 Count);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Achievements_Unlock : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString AchievementName;

	UPROPERTY(BlueprintAssignable)
		FAchievements_Unlock OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAchievements_Unlock OnFailure;

	/* Unlock the achievement with the given name. This can be of any achievement type.  */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Achievements_Unlock* UnlockAchievement(UObject* WorldContextObject, FString AchievementName);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};