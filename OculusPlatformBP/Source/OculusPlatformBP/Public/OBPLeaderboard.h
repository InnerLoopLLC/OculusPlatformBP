// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
//#include "OBPLeaderboard.generated.h"

/*

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


/*
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBPLeaderboard : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	// --------------------
	// Leaderboard.h
	// --------------------
	
// not yet implemented
// requires OculusPlatfromSDK v18 (1.50) or later; default UE4 distribution = 1.40

// Leaderboard Struct
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
	// Enum Leaderboard Filter Type
	// --------------------

	//OVRPL_PUBLIC_FUNCTION(constchar*) ovrLeaderboardFilterType_ToString(ovrLeaderboardFilterType value);

	//OVRPL_PUBLIC_FUNCTION(ovrLeaderboardFilterType) ovrLeaderboardFilterType_FromString(constchar* str);


	// --------------------
	// Enum Leaderboard Start At
	// --------------------
	
	//OVRPL_PUBLIC_FUNCTION(constchar*) ovrLeaderboardStartAt_ToString(ovrLeaderboardStartAt value);
	
	//OVRPL_PUBLIC_FUNCTION(ovrLeaderboardStartAt) ovrLeaderboardStartAt_FromString(constchar* str);

	// --------------------
	// Leaderboard Update Status
	// --------------------

	OVRP_PUBLIC_FUNCTION(bool)         ovr_LeaderboardUpdateStatus_GetDidUpdate(const ovrLeaderboardUpdateStatusHandle obj);
	OVRP_PUBLIC_FUNCTION(ovrID)        ovr_LeaderboardUpdateStatus_GetUpdatedChallengeId(const ovrLeaderboardUpdateStatusHandle obj, unsignedint index);
	OVRP_PUBLIC_FUNCTION(unsignedint) ovr_LeaderboardUpdateStatus_GetUpdatedChallengeIdsSize(const ovrLeaderboardUpdateStatusHandle obj);

	// --------------------
	// Leaderboard Requests
	// --------------------

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		void GetLeaderboardEntries();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		void GetLeaderboardEntriesAfterRank();

	// not yet implemented
	// requires OculusPlatfromSDK v16 (1.48) or later; default UE4 distribution = 1.40

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		void GetLeaderboardEntriesByIds();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		void GetNextLeaderboardEntries();;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		void GetPreviousLeaderboardEntries();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		void WriteLeaderboardEntry();
};


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
};	

/*
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
};*/