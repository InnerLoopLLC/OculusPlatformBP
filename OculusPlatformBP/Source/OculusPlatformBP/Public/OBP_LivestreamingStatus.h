// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_LivestreamingStatus.generated.h"

// --------------------
// OVR_LivestreamingStatus.h
// --------------------
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_LivestreamingStatus : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrLivestreamingStatus* ovrLivestreamingStatusHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Livestreaming|Livestreaming Status")
		bool GetCommentsVisible();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Livestreaming|Livestreaming Status")
		bool GetIsPaused();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Livestreaming|Livestreaming Status")
		bool GetLivestreamingEnabled();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Livestreaming|Livestreaming Status")
		int32 GetLivestreamingType();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Livestreaming|Livestreaming Status")
		bool GetMicEnabled();
};