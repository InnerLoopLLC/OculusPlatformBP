// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBPUser.h"
#include "OBPAchievements.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAchievementsAddCount, FString, AchievementName, bool, bDidJustUnlock);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAchievementsAddFields, FString, AchievementName, bool, bDidJustUnlock);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAchievementsGetAllDefinitions, UOBP_AchievementDefinitionArray*, AchievementDefinitionArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAchievementsGetAllProgress, UOBP_AchievementProgressArray*, AchievementProgressArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAchievementsGetDefinitionsByName, UOBP_AchievementDefinitionArray*, AchievementDefinitionArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAchievementsGetNextAchievementDefinitionArrayPage, UOBP_AchievementDefinitionArray*, AchievementDefinitionArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAchievementsGetNextAchievementProgressArrayPage, UOBP_AchievementProgressArray*, AchievementProgressArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAchievementsGetProgressByName, UOBP_AchievementProgressArray*, AchievementProgressArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAchievementsUnlock, FString, AchievementName, bool, bDidJustUnlock);

// --------------------
// ovr_Requests_Achievements.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Achievements_AddCount : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString AchievementName;
	int64 Count;
	bool bDidJustUnlock;

	UPROPERTY(BlueprintAssignable)
		FAchievementsAddCount OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAchievementsAddCount OnFailure;

	/* Add 'count' to the achievement with the given name. This must be a COUNT achievement. 
	The largest number that is supported by this method is the max value of a signed 64-bit integer. 
	If the number is larger than that, it is clamped to that max value before being passed to the servers. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Achievements_AddCount* AddCount(UObject* WorldContextObject, FString AchievementName, int64 Count);

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
	bool bDidJustUnlock;

	UPROPERTY(BlueprintAssignable)
		FAchievementsAddFields OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAchievementsAddFields OnFailure;

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

	UOBP_AchievementDefinitionArray* AchievementDefinitionArray = nullptr;

	UPROPERTY(BlueprintAssignable)
		FAchievementsGetAllDefinitions OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAchievementsGetAllDefinitions OnFailure;

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

	UOBP_AchievementProgressArray* AchievementProgressArray = nullptr;

	UPROPERTY(BlueprintAssignable)
		FAchievementsGetAllProgress OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAchievementsGetAllProgress OnFailure;

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

	UOBP_AchievementDefinitionArray* AchievementDefinitionArray = nullptr;
	//TArray<FString> Names;
	FString Names;
	int Count;

	UPROPERTY(BlueprintAssignable)
		FAchievementsGetDefinitionsByName OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAchievementsGetDefinitionsByName OnFailure;

	/* Request the achievement definitions that match the specified names. 
	Note: This node is currently non-functional. Coming soon.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Achievements_GetDefinitionsByName* GetDefinitionsByName(UObject* WorldContextObject, FString Names, int Count);

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
		FAchievementsGetNextAchievementDefinitionArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAchievementsGetNextAchievementDefinitionArrayPage OnFailure;

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
		FAchievementsGetNextAchievementProgressArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAchievementsGetNextAchievementProgressArrayPage OnFailure;

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

	UOBP_AchievementProgressArray* AchievementProgressArray = nullptr;
	//TArray<FString> Names;
	FString Names;
	int Count;

	UPROPERTY(BlueprintAssignable)
		FAchievementsGetProgressByName OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAchievementsGetProgressByName OnFailure;

	/* Request the user's progress on the specified achievements. 
	Note: This node is currently non-functional. Coming soon.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Achievements_GetProgressByName* GetProgressByName(UObject* WorldContextObject, FString Names, int Count);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Achievements_Unlock : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString AchievementName;
	bool bDidJustUnlock;

	UPROPERTY(BlueprintAssignable)
		FAchievementsUnlock OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAchievementsUnlock OnFailure;

	/* Unlock the achievement with the given name. This can be of any achievement type.  */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Achievements_Unlock* UnlockAchievement(UObject* WorldContextObject, FString AchievementName);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

// --------------------
// ovr_AchievementDefinition.h
// --------------------
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_AchievementDefinition : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrAchievementDefinition* ovrAchievementDefinitionHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievement|Definition")
		FString GetName();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievement|Definition")
		int GetBitfieldLength();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievement|Definition")
		int64 GetTarget();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievement|Definition")
		EOBPAchievementType GetType();
};

// --------------------
// ovr_AchievementDefinitionArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_AchievementDefinitionArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrAchievementDefinitionArray* ovrAchievementDefinitionArrayHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Definition")
		UOBP_AchievementDefinition* GetElement(int Index);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Definition")
		FString GetNextUrl();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Definition")
		int GetSize();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Definition")
		bool HasNextPage();
};

// --------------------
// ovr_AchievementProgress.h
// --------------------
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_AchievementProgress : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrAchievementProgress* ovrAchievementProgressHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievement|Progress")
		FString GetBitfield();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievement|Progress")
		int64 GetCount();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievement|Progress")
		bool GetIsUnlocked();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievement|Progress")
		FString GetName();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievement|Progress")
		int64 GetUnlockTime();
};

// --------------------
// ovr_AchievementProgressArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_AchievementProgressArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrAchievementProgressArray* ovrAchievementProgressArrayHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Progress")
		UOBP_AchievementProgress* GetElement(int Index);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Progress")
		FString GetNextUrl();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Progress")
		int GetSize();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Achievements|Progress")
		bool HasNextPage();
};