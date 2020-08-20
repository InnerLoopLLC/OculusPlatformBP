// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"

#include "CoreGlobals.h"
#include "CoreMinimal.h"
#include "EngineGlobals.h"
#include "Engine/Engine.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/ObjectMacros.h"

#include "Online.h"
#include "OnlineSubsystem.h"
#include "OnlineSubsystemOculus.h"

#include <ThirdParty\Oculus\LibOVRPlatform\LibOVRPlatform\include\OVR_Platform.h>

#include "OBPLeaderboard.generated.h"

UENUM(BlueprintType)
enum class EOBPLeaderboardFilterType : uint8
{
	None,
	Friends,
	Unknown,
	UserIds
};

UENUM(BlueprintType)
enum class EOBPLeaderboardStartAt : uint8
{
	Top,
	CenteredOnViewer,
	CenteredOnViewerOrTop,
	Unknown
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBPLeaderboard : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	// --------------------
	// Leaderboard Object Properties
	// --------------------
	
	// Leaderboard
	ovrLeaderboard* ovrLeaderboardHandle;

	// Leaderboard Update Status
	ovrLeaderboardUpdateStatus* ovrLeaderboardUpdateStatusHandle;

	// --------------------
	// Leaderboard (https://developer.oculus.com/reference/platform/1.40/o_v_r_rich_presence_options_8h)
	// --------------------

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Leaderboard", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBPLeaderboard* CreateLeaderboard(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		FString GetApiName();

	// --------------------
	// Enum Leaderboard Filter Type (https://developer.oculus.com/reference/platform/1.40/o_v_r_rich_presence_options_8h)
	// --------------------

	//OVRPL_PUBLIC_FUNCTION(constchar*) ovrLeaderboardFilterType_ToString(ovrLeaderboardFilterType value);

	//OVRPL_PUBLIC_FUNCTION(ovrLeaderboardFilterType) ovrLeaderboardFilterType_FromString(constchar* str);


	// --------------------
	// Enum Leaderboard Start At (https://developer.oculus.com/reference/platform/1.40/o_v_r_rich_presence_options_8h)
	// --------------------
	
	//OVRPL_PUBLIC_FUNCTION(constchar*) ovrLeaderboardStartAt_ToString(ovrLeaderboardStartAt value);
	
	//OVRPL_PUBLIC_FUNCTION(ovrLeaderboardStartAt) ovrLeaderboardStartAt_FromString(constchar* str);

	// --------------------
	// Leaderboard Update Status (https://developer.oculus.com/reference/platform/v19/o_v_r_leaderboard_update_status_8h)
	// --------------------

	OVRP_PUBLIC_FUNCTION(bool)         ovr_LeaderboardUpdateStatus_GetDidUpdate(const ovrLeaderboardUpdateStatusHandle obj);
	OVRP_PUBLIC_FUNCTION(ovrID)        ovr_LeaderboardUpdateStatus_GetUpdatedChallengeId(const ovrLeaderboardUpdateStatusHandle obj, unsignedint index);
	OVRP_PUBLIC_FUNCTION(unsignedint) ovr_LeaderboardUpdateStatus_GetUpdatedChallengeIdsSize(const ovrLeaderboardUpdateStatusHandle obj);

	// --------------------
	// Leaderboard Requests (https://developer.oculus.com/reference/platform/v19/o_v_r_requests_leaderboard_8h/)
	// --------------------

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		void GetLeaderboardEntries();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		void GetLeaderboardEntriesAfterRank();

	// requires OculusPlatfromSDK v16 (1.48) or later; default UE4 distribution = 1.40
#if PLATFORM_MINOR_VERSION >= 48
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		void GetLeaderboardEntriesByIds();
#endif

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		void GetNextLeaderboardEntries();;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		void GetPreviousLeaderboardEntries();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		void WriteLeaderboardEntry();
};

/*
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBPLeaderboardEntry : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	// --------------------
	// Leaderboard Entry Object Properties
	// --------------------

	ovrLeaderboardEntry* ovrLeaderboardEntryHandle;

	// --------------------
	// Leaderboard Entry (https://developer.oculus.com/reference/platform/v19/o_v_r_leaderboard_entry_8h)
	// --------------------

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Leaderboard", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBPLeaderboardEntry* CreateLeaderboardEntry(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		FString GetExtraData();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		int GetExtraDataLength();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		int GetRank();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		int64 GetScore();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		int64 GetTimestamp();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		void GetUser();

	OVRP_PUBLIC_FUNCTION(constchar*)       ovr_LeaderboardEntry_GetExtraData(const ovrLeaderboardEntryHandle obj);
	OVRP_PUBLIC_FUNCTION(unsignedint)       ovr_LeaderboardEntry_GetExtraDataLength(const ovrLeaderboardEntryHandle obj);
	OVRP_PUBLIC_FUNCTION(int)                ovr_LeaderboardEntry_GetRank(const ovrLeaderboardEntryHandle obj);
	OVRP_PUBLIC_FUNCTION(longlong)          ovr_LeaderboardEntry_GetScore(const ovrLeaderboardEntryHandle obj);
	OVRP_PUBLIC_FUNCTION(unsignedlonglong) ovr_LeaderboardEntry_GetTimestamp(const ovrLeaderboardEntryHandle obj);
	OVRP_PUBLIC_FUNCTION(ovrUserHandle)      ovr_LeaderboardEntry_GetUser(const ovrLeaderboardEntryHandle obj);
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBPLeaderboardEntryArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	// --------------------
	// Leaderboard Entry Array Object Properties
	// --------------------

	ovrLeaderboardEntryArray* ovrLeaderboardEntryArrayHandle;

	// --------------------
	// Leaderboard Entry Array (https://developer.oculus.com/reference/platform/v19/o_v_r_leaderboard_entry_array_8h)
	// --------------------

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Leaderboard", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBPLeaderboardEntry* CreateLeaderboardEntryArray(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		void UOBPLeaderboardEntry* GetElement();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		FString GetNextUrl();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		FString GetPreviousUrl();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		int GetSize();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		int64 GetTotalCount();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		bool HasNextPage();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		bool HasPreviousPage();

	OVRP_PUBLIC_FUNCTION(ovrLeaderboardEntryHandle) ovr_LeaderboardEntryArray_GetElement(const ovrLeaderboardEntryArrayHandle obj, size_t index);
	OVRP_PUBLIC_FUNCTION(constchar*)              ovr_LeaderboardEntryArray_GetNextUrl(const ovrLeaderboardEntryArrayHandle obj);
	OVRP_PUBLIC_FUNCTION(constchar*)              ovr_LeaderboardEntryArray_GetPreviousUrl(const ovrLeaderboardEntryArrayHandle obj);
	OVRP_PUBLIC_FUNCTION(size_t)                    ovr_LeaderboardEntryArray_GetSize(const ovrLeaderboardEntryArrayHandle obj);
	OVRP_PUBLIC_FUNCTION(unsignedlonglong)        ovr_LeaderboardEntryArray_GetTotalCount(const ovrLeaderboardEntryArrayHandle obj);
	OVRP_PUBLIC_FUNCTION(bool)                      ovr_LeaderboardEntryArray_HasNextPage(const ovrLeaderboardEntryArrayHandle obj);
	OVRP_PUBLIC_FUNCTION(bool)                      ovr_LeaderboardEntryArray_HasPreviousPage(const ovrLeaderboardEntryArrayHandle obj);
};

*/