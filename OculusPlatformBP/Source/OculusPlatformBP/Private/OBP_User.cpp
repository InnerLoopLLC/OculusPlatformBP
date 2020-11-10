// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_User.h"

// --------------------
// Initializers
// --------------------

UOBP_User::UOBP_User(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_User.h
// --------------------

// requires OculusPlatfromSDK v18 (1.50) or later
FString UOBP_User::GetDisplayName()
{
#if PLATFORM_MINOR_VERSION >= 50
	return ovr_User_GetDisplayName(ovrUserHandle);
#else
	OBP_PlatformVersionError("User::GetDisplayName", "v18");
	return FString();
#endif
}

FString UOBP_User::GetPresence()
{
	return ovr_User_GetPresence(ovrUserHandle);
}

// requires OculusPlatfromSDK 1.40 or later
FString UOBP_User::GetPresenceDeeplinkMessage()
{
#if PLATFORM_MINOR_VERSION >= 50
	return ovr_User_GetPresenceDeeplinkMessage(ovrUserHandle);
#else
	OBP_PlatformVersionError("User::GetPresenceDeeplinkMessage", "1.40");
	return FString();
#endif
}

// requires OculusPlatfromSDK 1.41 or later
FString UOBP_User::GetPresenceDestinationApiName()
{
#if PLATFORM_MINOR_VERSION >= 41
	return ovr_User_GetPresenceDestinationApiName(ovrUserHandle);
#else
	OBP_PlatformVersionError("User::GetPresenceDestinationApiName", "1.41");
	return FString();
#endif
}

EOBP_UserPresenceStatus UOBP_User::GetPresenceStatus()
{
	switch (ovr_User_GetPresenceStatus(ovrUserHandle))
	{
	case ovrUserPresenceStatus::ovrUserPresenceStatus_Unknown:
		return EOBP_UserPresenceStatus::Unknown;
	case ovrUserPresenceStatus::ovrUserPresenceStatus_Online:
		return EOBP_UserPresenceStatus::Online;
	case ovrUserPresenceStatus::ovrUserPresenceStatus_Offline:
		return EOBP_UserPresenceStatus::Offline;
	default:
		return EOBP_UserPresenceStatus::Unknown;
	}
}

FString UOBP_User::GetID()
{
	int64 ovrID = ovr_User_GetID(ovrUserHandle);
	return OBP_Int64ToFString(ovrID);
}

FString UOBP_User::GetImageURL()
{
	return ovr_User_GetImageUrl(ovrUserHandle);
}

FString UOBP_User::GetInviteToken()
{
	return ovr_User_GetInviteToken(ovrUserHandle);
}

FString UOBP_User::GetOculusID()
{
	return ovr_User_GetOculusID(ovrUserHandle);
}

FString UOBP_User::GetSmallImageUrl()
{
	return ovr_User_GetSmallImageUrl(ovrUserHandle);
}