// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBPUser.h"

UOBPUser::UOBPUser(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_User.h
// --------------------

UOBPUser* UOBPUser::CreateUser(UObject* WorldContextObject)
{
	return NewObject<UOBPUser>();
}

// requires OculusPlatfromSDK v18 (1.50) or later
FString UOBPUser::GetDisplayName()
{
#if PLATFORM_MINOR_VERSION >= 50
	return ovr_User_GetDisplayName(ovrUserHandle);
#else
	OBPPlatformVersionError("GetDisplayName", "v18");
	return FString();
#endif
}

FString UOBPUser::GetPresence()
{
	return ovr_User_GetPresence(ovrUserHandle);
}

FString UOBPUser::GetPresenceDeeplinkMessage()
{
	return ovr_User_GetPresenceDeeplinkMessage(ovrUserHandle);
}

// requires OculusPlatfromSDK 1.41 or later
FString UOBPUser::GetPresenceDestinationApiName()
{
#if PLATFORM_MINOR_VERSION >= 41
	return ovr_User_GetPresenceDestinationApiName(ovrUserHandle);
#else
	OBPPlatformVersionError("GetPresenceDestinationApiName", "1.41");
	return FString();
#endif
}

EOBPUserPresenceStatus UOBPUser::GetPresenceStatus()
{
	switch (ovr_User_GetPresenceStatus(ovrUserHandle))
	{
	case ovrUserPresenceStatus::ovrUserPresenceStatus_Unknown:
		return EOBPUserPresenceStatus::Unknown;
		break;
	case ovrUserPresenceStatus::ovrUserPresenceStatus_Online:
		return EOBPUserPresenceStatus::Online;
		break;
	case ovrUserPresenceStatus::ovrUserPresenceStatus_Offline:
		return EOBPUserPresenceStatus::Offline;
		break;
	default:
		return EOBPUserPresenceStatus::Unknown;
		break;
	}
}

int64 UOBPUser::GetID()
{
	return ovr_User_GetID(ovrUserHandle);
}

FString UOBPUser::GetImageURL()
{
	return ovr_User_GetImageUrl(ovrUserHandle);
}

FString UOBPUser::GetInviteToken()
{
	return ovr_User_GetInviteToken(ovrUserHandle);
}

FString UOBPUser::GetOculusID()
{
	return ovr_User_GetOculusID(ovrUserHandle);
}

FString UOBPUser::GetSmallImageUrl()
{
	return ovr_User_GetSmallImageUrl(ovrUserHandle);
}