// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBPUser.h"
#include "OBPLeaderboard.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetEntries, UOBP_LeaderboardEntryArray*, LeaderboardEntryArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetEntriesAfterRank, UOBP_LeaderboardEntryArray*, LeaderboardEntryArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetNextEntries, UOBP_LeaderboardEntryArray*, LeaderboardEntryArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetPreviousEntries, UOBP_LeaderboardEntryArray*, LeaderboardEntryArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWriteEntry, bool, bDidUpdate);

// --------------------
// OVR_Requests_Leaderboard.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetEntries : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString LeaderboardName;
	int Limit;
	EOBPLeaderboardFilterType Filter;
	EOBPLeaderboardStartAt StartAt;

	UPROPERTY(BlueprintAssignable)
		FGetEntries OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetEntries OnFailure;

	/* Requests a block of Leaderboard Entries.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetEntries* GetEntries(UObject* WorldContextObject, FString LeaderboardName, int Limit, EOBPLeaderboardFilterType Filter, EOBPLeaderboardStartAt StartAt);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetEntriesAfterRank : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString LeaderboardName;
	int Limit;
	int64 AfterRank;

	UPROPERTY(BlueprintAssignable)
		FGetEntriesAfterRank OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetEntriesAfterRank OnFailure;

	/* Requests a block of leaderboard Entries.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetEntriesAfterRank* GetEntriesAfterRank(UObject* WorldContextObject, FString LeaderboardName, int Limit, int64 AfterRank);

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
	int64 Score;
	const void* ExtraData;
	int ExtraDataLength;
	bool bForceUpdate;

	UPROPERTY(BlueprintAssignable)
		FWriteEntry OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FWriteEntry OnFailure;

	/* Writes a single entry to a leaderboard. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_WriteEntry* WriteEntry(UObject* WorldContextObject, FString LeaderboardName, int64 Score, int ExtraDataLength, bool bForceUpdate);

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
		int GetExtraDataLength();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		int GetRank();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		int64 GetScore();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard")
		int64 GetTimestamp();

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
		UOBP_LeaderboardEntry* GetElement(int Index);

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
};