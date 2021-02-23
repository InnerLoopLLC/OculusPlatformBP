// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_SupplementaryMetric.h"

// --------------------
// Initializers
// --------------------

UOBP_SupplementaryMetric::UOBP_SupplementaryMetric(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_SupplementaryMetric.h
// --------------------

FString UOBP_SupplementaryMetric::GetID()
{
#if PLATFORM_MINOR_VERSION >= 57
	int64 ovrID = ovr_SupplementaryMetric_GetID(ovrSupplementaryMetricHandle);
	return OBP_Int64ToFString(ovrID);
#else
	OBP_PlatformVersionError("SupplementaryMetric::GetID", "v25");
	return FString();
#endif
}

int32 UOBP_SupplementaryMetric::GetMetric()
{
#if PLATFORM_MINOR_VERSION >= 57
	return ovr_SupplementaryMetric_GetMetric(ovrSupplementaryMetricHandle);
#else
	OBP_PlatformVersionError("SupplementaryMetric::GetMetric", "v25");
	return 0;
#endif
}