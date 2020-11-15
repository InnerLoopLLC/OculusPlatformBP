// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_LivestreamingStatus.h"

// --------------------
// Initializers
// --------------------

UOBP_LivestreamingStatus::UOBP_LivestreamingStatus(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_LivestreamingStatus.h
// --------------------

bool UOBP_LivestreamingStatus::GetCommentsVisible()
{
	return ovr_LivestreamingStatus_GetCommentsVisible(ovrLivestreamingStatusHandle);
}

bool UOBP_LivestreamingStatus::GetIsPaused()
{
	return ovr_LivestreamingStatus_GetIsPaused(ovrLivestreamingStatusHandle);
}

bool UOBP_LivestreamingStatus::GetLivestreamingEnabled()
{
	return ovr_LivestreamingStatus_GetLivestreamingEnabled(ovrLivestreamingStatusHandle);
}

int32 UOBP_LivestreamingStatus::GetLivestreamingType()
{
	return ovr_LivestreamingStatus_GetLivestreamingType(ovrLivestreamingStatusHandle);
}

bool UOBP_LivestreamingStatus::GetMicEnabled()
{
	return ovr_LivestreamingStatus_GetMicEnabled(ovrLivestreamingStatusHandle);
}