// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Functions_ApplicationLifecycle.h"

// --------------------
// Initializers
// --------------------

UOBP_Functions_ApplicationLifecycle::UOBP_Functions_ApplicationLifecycle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_Functions_ApplicationLifecycle.h
// --------------------

UOBP_LaunchDetails* UOBP_Functions_ApplicationLifecycle::GetLaunchDetails(UObject* WorldContextObject)
{
	auto LaunchDetails = NewObject<UOBP_LaunchDetails>();
	LaunchDetails->ovrLaunchDetailsHandle = ovr_ApplicationLifecycle_GetLaunchDetails();
	return LaunchDetails;
}

void UOBP_Functions_ApplicationLifecycle::LogDeeplinkResult(UObject* WorldContextObject, FString TrackingID, EOBP_LaunchResult LaunchResult)
{
#if PLATFORM_MINOR_VERSION >= 55
	switch (LaunchResult)
	{
	case EOBP_LaunchResult::Unknown:
		ovr_ApplicationLifecycle_LogDeeplinkResult(TCHAR_TO_ANSI(*TrackingID), ovrLaunchResult_Unknown);
		break;
	case EOBP_LaunchResult::Success:
		ovr_ApplicationLifecycle_LogDeeplinkResult(TCHAR_TO_ANSI(*TrackingID), ovrLaunchResult_Success);
		break;
	case EOBP_LaunchResult::FailedRoomFull:
		ovr_ApplicationLifecycle_LogDeeplinkResult(TCHAR_TO_ANSI(*TrackingID), ovrLaunchResult_FailedRoomFull);
		break;
	case EOBP_LaunchResult::FailedGameAlreadyStarted:
		ovr_ApplicationLifecycle_LogDeeplinkResult(TCHAR_TO_ANSI(*TrackingID), ovrLaunchResult_FailedGameAlreadyStarted);
		break;
	case EOBP_LaunchResult::FailedRoomNotFound:
		ovr_ApplicationLifecycle_LogDeeplinkResult(TCHAR_TO_ANSI(*TrackingID), ovrLaunchResult_FailedRoomNotFound);
		break;
	case EOBP_LaunchResult::FailedUserDeclined:
		ovr_ApplicationLifecycle_LogDeeplinkResult(TCHAR_TO_ANSI(*TrackingID), ovrLaunchResult_FailedUserDeclined);
		break;
	case EOBP_LaunchResult::FailedOtherReason:
		ovr_ApplicationLifecycle_LogDeeplinkResult(TCHAR_TO_ANSI(*TrackingID), ovrLaunchResult_FailedOtherReason);
		break;
	default:
		ovr_ApplicationLifecycle_LogDeeplinkResult(TCHAR_TO_ANSI(*TrackingID), ovrLaunchResult_Unknown);
		break;
	}
#else
	OBP_PlatformVersionError("ApplicationLifecycle::LogDeeplinkResult", "v23");
#endif
}