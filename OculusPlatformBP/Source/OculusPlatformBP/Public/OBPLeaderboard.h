// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBPUser.h"
#include "OBPLeaderboard.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetEntries, UOBP_LeaderboardEntryArray*, LeaderboardEntryArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetEntriesAfterRank, UOBP_LeaderboardEntryArray*, LeaderboardEntryArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetEntriesByIds, UOBP_LeaderboardEntryArray*, LeaderboardEntryArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetNextEntries, UOBP_LeaderboardEntryArray*, LeaderboardEntryArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetPreviousEntries, UOBP_LeaderboardEntryArray*, LeaderboardEntryArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWriteEntry, bool, bDidUpdate);

// --------------------
// ovr_Requests_Leaderboard.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetEntries : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString LeaderboardName;
	int32 Limit;
	EOBPLeaderboardFilterType Filter;
	EOBPLeaderboardStartAt StartAt;

	UPROPERTY(BlueprintAssignable)
		FGetEntries OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetEntries OnFailure;

	/* Requests a block of Leaderboard Entries.
	Note: Filter Enum value 'UserIds' Requires OculusPlatfromSDK v15 or later.
		Otherwise, it defaults to 'None' */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetEntries* GetEntries(UObject* WorldContextObject, FString LeaderboardName, int32 Limit, EOBPLeaderboardFilterType Filter, EOBPLeaderboardStartAt StartAt);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetEntriesAfterRank : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString LeaderboardName;
	int32 Limit;
	int32 AfterRank;

	UPROPERTY(BlueprintAssignable)
		FGetEntriesAfterRank OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetEntriesAfterRank OnFailure;

	/* Requests a block of leaderboard Entries.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetEntriesAfterRank* GetEntriesAfterRank(UObject* WorldContextObject, FString LeaderboardName, int32 Limit, int32 AfterRank);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetEntriesByIds : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString LeaderboardName;
	int32 Limit;
	EOBPLeaderboardStartAt StartAt;
	TArray<int32> UserIdArray;
	int32 UserIdLength;

	UPROPERTY(BlueprintAssignable)
		FGetEntriesByIds OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetEntriesByIds OnFailure;

	/* Requests a block of leaderboard entries. Will return only entries matching the user IDs passed in.
	Note: Requires OculusPlatfromSDK v15 or later 
	Note: This node doesn't work yet. Coming sooner or later*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetEntriesByIds* GetEntriesByIds(UObject* WorldContextObject, FString LeaderboardName, int32 Limit, EOBPLeaderboardStartAt StartAt, TArray<int32> UserIdArray, int32 UserIdLength);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetNextEntries : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_LeaderboardEntryArray* NextLeaderboardEntryArray;

	UPROPERTY(BlueprintAssignable)
		FGetNextEntries OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetNextEntries OnFailure;

	/* Requests the next block of leaderboard entries.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetNextEntries* GetNextEntries(UObject* WorldContextObject, UOBP_LeaderboardEntryArray* LeaderboardEntryArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetPreviousEntries : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_LeaderboardEntryArray* PreviousLeaderboardEntryArray;

	UPROPERTY(BlueprintAssignable)
		FGetPreviousEntries OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetPreviousEntries OnFailure;

	/* Requests the previous block of leaderboard entries.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetPreviousEntries* GetPreviousEntries(UObject* WorldContextObject, UOBP_LeaderboardEntryArray* LeaderboardEntryArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_WriteEntry : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString LeaderboardName;
	int32 Score;
	FString ExtraData;
	int32 ExtraDataLength;
	bool bForceUpdate;

	UPROPERTY(BlueprintAssignable)
		FWriteEntry OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FWriteEntry OnFailure;

	/* Writes a single entry to a leaderboard. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_WriteEntry* WriteEntry(UObject* WorldContextObject, FString LeaderboardName, int32 Score, FString ExtraData, int32 ExtraDataLength, bool bForceUpdate);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

// --------------------
// ovr_LeaderboardEntry.h
// --------------------
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_LeaderboardEntry : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrLeaderboardEntry* ovrLeaderboardEntryHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		FString GetExtraData();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		int32 GetExtraDataLength();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		int32 GetRank();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		int32 GetScore();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		int32 GetTimestamp();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		UOBP_User* GetUser();
};	

// --------------------
// ovr_LeaderboardEntryArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_LeaderboardEntryArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrLeaderboardEntryArray* ovrLeaderboardEntryArrayHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		UOBP_LeaderboardEntry* GetElement(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		FString GetNextUrl();
	
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		FString GetPreviousUrl();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		int32 GetSize();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		int32 GetTotalCount();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		bool HasNextPage();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		bool HasPreviousPage();
};

// --------------------
// Leaderboard.h
// --------------------

/*
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Leaderboard : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrLeaderboard* ovrLeaderboardHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		UOBP_Leaderboard* GetApiName(UOBP_);
};*/