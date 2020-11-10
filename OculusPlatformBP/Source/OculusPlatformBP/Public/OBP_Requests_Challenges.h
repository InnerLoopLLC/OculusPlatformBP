// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_Challenge.h"
#include "OBP_ChallengeArray.h"
#include "OBP_ChallengeEntryArray.h"
#include "OBP_ChallengeOptions.h"
#include "OBP_Requests_Challenges.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChallenges_Create, UOBP_Challenge*, Challenge);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChallenges_DeclineInvite, UOBP_Challenge*, Challenge);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FChallenges_Delete);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChallenges_Get, UOBP_Challenge*, Challenges);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChallenges_GetEntries, UOBP_ChallengeEntryArray*, ChallengeEntries);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChallenges_GetEntriesAfterRank, UOBP_ChallengeEntryArray*, ChallengeEntriesAfterRank);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChallenges_GetEntriesByIds, UOBP_ChallengeEntryArray*, ChallengeEntriesByIds);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChallenges_GetList, UOBP_ChallengeArray*, ChallengeList);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChallenges_GetNextChallenges, UOBP_ChallengeArray*, NextChallenges);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChallenges_GetNextEntries, UOBP_ChallengeEntryArray*, NextChallengeEntries);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChallenges_GetPreviousChallenges, UOBP_ChallengeArray*, PreviousChallenges);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChallenges_GetPreviousEntries, UOBP_ChallengeEntryArray*, PreviousChallengeEntries);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChallenges_Join, UOBP_Challenge*, Challenge);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChallenges_Leave, UOBP_Challenge*, Challenge);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChallenges_UpdateInfo, UOBP_Challenge*, Challenge);

// --------------------
// OVR_Requests_Challenges.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Challenges_Create : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString LeaderboardName;
	UOBP_ChallengeOptions* ChallengeOptions;

	UPROPERTY(BlueprintAssignable)
		FChallenges_Create OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FChallenges_Create OnFailure;

	/* Creates a new user challenge 
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Challenges_Create* Create(UObject* WorldContextObject, FString LeaderboardName, UOBP_ChallengeOptions* ChallengeOptions);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Challenges_DeclineInvite : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString ChallengeID;

	UPROPERTY(BlueprintAssignable)
		FChallenges_DeclineInvite OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FChallenges_DeclineInvite OnFailure;

	/* If the current user has an invite to the challenge, decline the invite
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Challenges_DeclineInvite* DeclineInvite(UObject* WorldContextObject, FString ChallengeID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Challenges_Delete : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString ChallengeID;

	UPROPERTY(BlueprintAssignable)
		FChallenges_Delete OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FChallenges_Delete OnFailure;

	/* If the current user has permission, deletes a challenge
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Challenges_Delete* Delete(UObject* WorldContextObject, FString ChallengeID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Challenges_Get: public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString ChallengeID;

	UPROPERTY(BlueprintAssignable)
		FChallenges_Get OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FChallenges_Get OnFailure;

	/* Gets the information for a single challenge
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Challenges_Get* Get(UObject* WorldContextObject, FString ChallengeID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Challenges_GetEntries : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString ChallengeID;
	int32 Limit;
	EOBP_LeaderboardFilterType Filter;
	EOBP_LeaderboardStartAt StartAt;

	UPROPERTY(BlueprintAssignable)
		FChallenges_GetEntries OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FChallenges_GetEntries OnFailure;

	/* Requests a block of challenge entries.
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Challenges_GetEntries* GetEntries(UObject* WorldContextObject, FString ChallengeID, int32 Limit, EOBP_LeaderboardFilterType Filter, EOBP_LeaderboardStartAt StartAt);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Challenges_GetEntriesAfterRank : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString ChallengeID;
	int32 Limit;
	int32 AfterRank;

	UPROPERTY(BlueprintAssignable)
		FChallenges_GetEntriesAfterRank OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FChallenges_GetEntriesAfterRank OnFailure;

	/* Requests a block of challenge entries.
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Challenges_GetEntriesAfterRank* GetEntriesAfterRank(UObject* WorldContextObject, FString ChallengeID, int32 Limit, int32 AfterRank);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Challenges_GetEntriesByIds : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString ChallengeID;
	int32 Limit;
	EOBP_LeaderboardStartAt StartAt;
	TArray<FString> UserIds;
	int32 UserIdLength;

	UPROPERTY(BlueprintAssignable)
		FChallenges_GetEntriesByIds OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FChallenges_GetEntriesByIds OnFailure;

	/* Requests a block of challenge entries. Will return only entries matching the user IDs passed in.
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Challenges_GetEntriesByIds* GetEntriesByIds(UObject* WorldContextObject, FString ChallengeID, int32 Limit, EOBP_LeaderboardStartAt StartAt, TArray<FString> UserIds, int32 UserIdLength);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Challenges_GetList : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_ChallengeOptions* ChallengeOptions;
	int32 Limit;

	UPROPERTY(BlueprintAssignable)
		FChallenges_GetList OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FChallenges_GetList OnFailure;

	/* Requests for a list of challenge
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Challenges_GetList* GetList(UObject* WorldContextObject, UOBP_ChallengeOptions* ChallengeOptions, int32 Limit);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Challenges_GetNextChallenges : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_ChallengeArray* ChallengeArray;

	UPROPERTY(BlueprintAssignable)
		FChallenges_GetNextChallenges OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FChallenges_GetNextChallenges OnFailure;

	/* Requests for a list of challenge
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Challenges_GetNextChallenges* GetNextChallenges(UObject* WorldContextObject, UOBP_ChallengeArray* ChallengeArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Challenges_GetNextEntries : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_ChallengeEntryArray* ChallengeEntryArray;

	UPROPERTY(BlueprintAssignable)
		FChallenges_GetNextEntries OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FChallenges_GetNextEntries OnFailure;

	/* Requests the next block of challenge entries.
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Challenges_GetNextEntries* GetNextEntries(UObject* WorldContextObject, UOBP_ChallengeEntryArray* ChallengeEntryArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Challenges_GetPreviousChallenges : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_ChallengeArray* ChallengeArray;

	UPROPERTY(BlueprintAssignable)
		FChallenges_GetPreviousChallenges OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FChallenges_GetPreviousChallenges OnFailure;

	/* Requests the previous block of challenges.
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Challenges_GetPreviousChallenges* GetPreviousChallenges(UObject* WorldContextObject, UOBP_ChallengeArray* ChallengeArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Challenges_GetPreviousEntries : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_ChallengeEntryArray* ChallengeEntryArray;

	UPROPERTY(BlueprintAssignable)
		FChallenges_GetPreviousEntries OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FChallenges_GetPreviousEntries OnFailure;

	/* Requests the previous block of challenge entries.
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Challenges_GetPreviousEntries* GetPreviousEntries(UObject* WorldContextObject, UOBP_ChallengeEntryArray* ChallengeEntryArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Challenges_Join : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString ChallengeId;

	UPROPERTY(BlueprintAssignable)
		FChallenges_Join OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FChallenges_Join OnFailure;

	/* If the current user has permission, join the challenge
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Challenges_Join* Join(UObject* WorldContextObject, FString ChallengeId);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Challenges_Leave : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString ChallengeId;

	UPROPERTY(BlueprintAssignable)
		FChallenges_Leave OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FChallenges_Leave OnFailure;

	/* If the current user has permission, leave the challenge
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Challenges_Leave* Leave(UObject* WorldContextObject, FString ChallengeId);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Challenges_UpdateInfo : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString ChallengeId;
	UOBP_ChallengeOptions* ChallengeOptions;

	UPROPERTY(BlueprintAssignable)
		FChallenges_UpdateInfo OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FChallenges_UpdateInfo OnFailure;

	/* If the current user has permission, updates a challenge information
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Challenges_UpdateInfo* UpdateInfo(UObject* WorldContextObject, FString ChallengeId, UOBP_ChallengeOptions* ChallengeOptions);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};