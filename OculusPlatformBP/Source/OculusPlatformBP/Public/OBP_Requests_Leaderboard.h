// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_LeaderboardArray.h"
#include "OBP_LeaderboardEntry.h"
#include "OBP_LeaderboardEntryArray.h"
#include "OBP_Requests_Leaderboard.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLeaderboard_Get, UOBP_Leaderboard*, Leaderboard);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLeaderboard_GetEntries, const TArray<UOBP_LeaderboardEntry*>&, LeaderboardEntries, UOBP_LeaderboardEntryArray*, LeaderboardEntryArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLeaderboard_GetEntriesAfterRank, const TArray<UOBP_LeaderboardEntry*>&, LeaderboardEntries, UOBP_LeaderboardEntryArray*, LeaderboardEntryArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLeaderboard_GetEntriesByIds, const TArray<UOBP_LeaderboardEntry*>&, LeaderboardEntries, UOBP_LeaderboardEntryArray*, LeaderboardEntryArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLeaderboard_GetNextEntries, const TArray<UOBP_LeaderboardEntry*>&, LeaderboardEntries, UOBP_LeaderboardEntryArray*, LeaderboardEntryArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLeaderboard_GetNextLeaderboardArrayPage, const TArray<UOBP_Leaderboard*>&, Leaderboards, UOBP_LeaderboardArray*, LeaderboardArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLeaderboard_GetPreviousEntries, const TArray<UOBP_LeaderboardEntry*>&, LeaderboardEntries, UOBP_LeaderboardEntryArray*, LeaderboardEntryArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FLeaderboard_WriteEntry, bool, bDidUpdate, FString, UpdatedChallengeId, int32, UpdatedChallengeIdSize);

// --------------------
// OVR_Requests_Leaderboard.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Leaderboard_Get : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString LeaderboardName;

	UPROPERTY(BlueprintAssignable)
		FLeaderboard_Get OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FLeaderboard_Get OnFailure;

	/* Gets the information for a single leaderboard
	Note: Requires OculusPlatfromSDK v27 or later. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Leaderboard_Get* Get(UObject* WorldContextObject, FString LeaderboardName);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Leaderboard_GetEntries : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString LeaderboardName;
	int32 Limit;
	EOBP_LeaderboardFilterType Filter;
	EOBP_LeaderboardStartAt StartAt;

	UPROPERTY(BlueprintAssignable)
		FLeaderboard_GetEntries OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FLeaderboard_GetEntries OnFailure;

	/* Requests a block of Leaderboard Entries.
	Note: Filter Enum value 'UserIds' Requires OculusPlatfromSDK v15 or later.
		Otherwise, it defaults to 'None' */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Leaderboard_GetEntries* GetEntries(UObject* WorldContextObject, FString LeaderboardName, int32 Limit, EOBP_LeaderboardFilterType Filter, EOBP_LeaderboardStartAt StartAt);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Leaderboard_GetEntriesAfterRank : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString LeaderboardName;
	int32 Limit;
	int32 AfterRank;

	UPROPERTY(BlueprintAssignable)
		FLeaderboard_GetEntriesAfterRank OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FLeaderboard_GetEntriesAfterRank OnFailure;

	/* Requests a block of leaderboard Entries.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Leaderboard_GetEntriesAfterRank* GetEntriesAfterRank(UObject* WorldContextObject, FString LeaderboardName, int32 Limit, int32 AfterRank);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Leaderboard_GetEntriesByIds : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString LeaderboardName;
	int32 Limit;
	EOBP_LeaderboardStartAt StartAt;
	TArray<FString> UserIds;
	int32 UserIdLength;

	UPROPERTY(BlueprintAssignable)
		FLeaderboard_GetEntriesByIds OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FLeaderboard_GetEntriesByIds OnFailure;

	/* Requests a block of leaderboard entries. Will return only entries matching the user IDs passed in.
	Note: Requires OculusPlatfromSDK v15 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Leaderboard_GetEntriesByIds* GetEntriesByIds(UObject* WorldContextObject, FString LeaderboardName, int32 Limit, EOBP_LeaderboardStartAt StartAt, TArray<FString> UserIds, int32 UserIdLength);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Leaderboard_GetNextEntries : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_LeaderboardEntryArray* LeaderboardEntryArray;

	UPROPERTY(BlueprintAssignable)
		FLeaderboard_GetNextEntries OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FLeaderboard_GetNextEntries OnFailure;

	/* Requests the next block of leaderboard entries.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Leaderboard_GetNextEntries* GetNextEntries(UObject* WorldContextObject, UOBP_LeaderboardEntryArray* LeaderboardEntryArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Leaderboard_GetNextLeaderboardArrayPage : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_LeaderboardArray* LeaderboardArray;

	UPROPERTY(BlueprintAssignable)
		FLeaderboard_GetNextLeaderboardArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FLeaderboard_GetNextLeaderboardArrayPage OnFailure;

	/* Get the next page of entries.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Leaderboard_GetNextLeaderboardArrayPage* GetNextLeaderboardArrayPage(UObject* WorldContextObject, UOBP_LeaderboardArray* LeaderboardArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Leaderboard_GetPreviousEntries : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_LeaderboardEntryArray* LeaderboardEntryArray;

	UPROPERTY(BlueprintAssignable)
		FLeaderboard_GetPreviousEntries OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FLeaderboard_GetPreviousEntries OnFailure;

	/* Requests the previous block of leaderboard entries.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Leaderboard_GetPreviousEntries* GetPreviousEntries(UObject* WorldContextObject, UOBP_LeaderboardEntryArray* LeaderboardEntryArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Leaderboard_WriteEntry : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString LeaderboardName;
	int32 Score;
	FString ExtraData;
	int32 ExtraDataLength;
	bool bForceUpdate;

	UPROPERTY(BlueprintAssignable)
		FLeaderboard_WriteEntry OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FLeaderboard_WriteEntry OnFailure;

	/* Writes a single entry to a leaderboard.
	Note: Responses including UpdatedChallengeId and UpdatedChallengeIdsSize require Oculus Platform SDK v19 or later.*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Leaderboard_WriteEntry* WriteEntry(UObject* WorldContextObject, FString LeaderboardName, int32 Score, FString ExtraData, int32 ExtraDataLength, bool bForceUpdate);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Leaderboard_WriteEntryWithSupplementaryMetric : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString LeaderboardName;
	int32 Score;
	int32 SupplementaryMetric;
	FString ExtraData;
	int32 ExtraDataLength;
	bool bForceUpdate;

	UPROPERTY(BlueprintAssignable)
		FLeaderboard_WriteEntry OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FLeaderboard_WriteEntry OnFailure;

	/* Writes a single entry to a leaderboard, can include supplementary metrics
	Note: Responses including UpdatedChallengeId and UpdatedChallengeIdsSize require Oculus Platform SDK v19 or later.
	Requires OculusPlatformSDK v25 or later. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Leaderboard_WriteEntryWithSupplementaryMetric* WriteEntryWithSupplementaryMetric(UObject* WorldContextObject, FString LeaderboardName, int32 Score, int32 SupplementaryMetric, FString ExtraData, int32 ExtraDataLength, bool bForceUpdate);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};