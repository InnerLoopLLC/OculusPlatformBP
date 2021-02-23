// OculusPlatformBP plugin by InnerLoop LLC 2020-21

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_SupplementaryMetric.generated.h"

// --------------------
// OVR_SupplementaryMetric.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_SupplementaryMetric : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

#if PLATFORM_MINOR_VERSION >= 57
	ovrSupplementaryMetric* ovrSupplementaryMetricHandle;
#endif

	/* Requires OculusPlatformSDK v25 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Misc|Supplementary Metric")
		FString GetID();

	/* Requires OculusPlatformSDK v25 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Misc|Supplementary Metric")
		int32 GetMetric();
};
