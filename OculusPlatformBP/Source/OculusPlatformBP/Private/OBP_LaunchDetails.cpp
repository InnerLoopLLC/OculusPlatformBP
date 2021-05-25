// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_LaunchDetails.h"

// --------------------
// Initializers
// --------------------

UOBP_LaunchDetails::UOBP_LaunchDetails(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_LaunchDetails.h
// --------------------

FString UOBP_LaunchDetails::GetDeeplinkMessage()
{
	return ovr_LaunchDetails_GetDeeplinkMessage(ovrLaunchDetailsHandle);
}

FString UOBP_LaunchDetails::GetDestinationApiName()
{
#if PLATFORM_MINOR_VERSION >= 41
	return ovr_LaunchDetails_GetDestinationApiName(ovrLaunchDetailsHandle);
#else
	OBP_PlatformVersionError("LaunchDetails::GetDestinationApiName", "1.41");
	return FString();
#endif
}

FString UOBP_LaunchDetails::GetLobbySessionID()
{
#if PLATFORM_MINOR_VERSION >= 60
	return ovr_LaunchDetails_GetLobbySessionID(ovrLaunchDetailsHandle);
#else
	OBP_PlatformVersionError("LaunchDetails::GetLobbySessionID", "v28");
	return FString();
#endif
}

FString UOBP_LaunchDetails::GetMatchSessionID()
{
#if PLATFORM_MINOR_VERSION >= 60
	return ovr_LaunchDetails_GetMatchSessionID(ovrLaunchDetailsHandle);
#else
	OBP_PlatformVersionError("LaunchDetails::GetMatchSessionID", "v28");
	return FString();
#endif
}

FString UOBP_LaunchDetails::GetLaunchSource()
{
	return ovr_LaunchDetails_GetLaunchSource(ovrLaunchDetailsHandle);
}

FString UOBP_LaunchDetails::GetRoomID()
{
	return OBP_Int64ToFString(ovr_LaunchDetails_GetRoomID(ovrLaunchDetailsHandle));
}

FString UOBP_LaunchDetails::GetTrackingID()
{
#if PLATFORM_MINOR_VERSION >= 55
	return ovr_LaunchDetails_GetTrackingID(ovrLaunchDetailsHandle);
#else
	OBP_PlatformVersionError("LaunchDetails::GetTrackingID", "v23");
	return FString();
#endif
}

UOBP_UserArray* UOBP_LaunchDetails::GetUsers()
{
	auto UserArrayToGet = NewObject<UOBP_UserArray>();
	UserArrayToGet->ovrUserArrayHandle = ovr_LaunchDetails_GetUsers(ovrLaunchDetailsHandle);
	return UserArrayToGet;
}

EOBP_LaunchType UOBP_LaunchDetails::GetLaunchType()
{
	auto LaunchType = ovr_LaunchDetails_GetLaunchType(ovrLaunchDetailsHandle);
	switch (LaunchType)
	{
	case ovrLaunchType_Unknown:
		return EOBP_LaunchType::Unknown;
	case ovrLaunchType_Normal:
		return EOBP_LaunchType::Invite;
	case ovrLaunchType_Coordinated:
		return EOBP_LaunchType::Coordinated;
	case ovrLaunchType_Deeplink:
		return EOBP_LaunchType::Deeplink;
	default:
		return EOBP_LaunchType::Unknown;
	}
}