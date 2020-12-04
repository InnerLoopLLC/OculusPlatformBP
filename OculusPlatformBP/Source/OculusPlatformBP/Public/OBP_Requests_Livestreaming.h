// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_LivestreamingStatus.h"
#include "OBP_Requests_Livestreaming.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLivestreaming_GetStatus, UOBP_LivestreamingStatus*, LivestreamingStatus);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLivestreaming_LaunchLivestreamingFlow);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLivestreaming_PauseStream, UOBP_LivestreamingStatus*, LivestreamingStatus);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLivestreaming_ResumeStream, UOBP_LivestreamingStatus*, LivestreamingStatus);

// --------------------
// ovr_Requests_Livestreaming.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Livestreaming_GetStatus : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FLivestreaming_GetStatus OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FLivestreaming_GetStatus OnFailure;

	/* Return the status of the current livestreaming session if there is one. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Livestreaming|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Livestreaming_GetStatus* GetStatus(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Livestreaming_LaunchLivestreamingFlow : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FLivestreaming_LaunchLivestreamingFlow OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FLivestreaming_LaunchLivestreamingFlow OnFailure;

	/* Launch the Livestreaming Flow.
	Requires OculusPlatfromSDK v23 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Livestreaming|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Livestreaming_LaunchLivestreamingFlow* LaunchLivestreamingFlow(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Livestreaming_PauseStream : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FLivestreaming_PauseStream OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FLivestreaming_PauseStream OnFailure;

	/* Pauses the livestreaming session if there is one. NOTE: this function is safe to call if no session is active. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Livestreaming|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Livestreaming_PauseStream* PauseStream(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Livestreaming_ResumeStream : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FLivestreaming_ResumeStream OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FLivestreaming_ResumeStream OnFailure;

	/* Resumes the livestreaming session if there is one. NOTE: this function is safe to call if no session is active. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Livestreaming|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Livestreaming_ResumeStream* ResumeStream(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};