// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBPUser.h"

UOBP_User::UOBP_User(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_GetUser::UOBP_GetUser(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_LoggedInUser::UOBP_LoggedInUser(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UOBP_GetUser::Activate()
{
	UOBP_User* User = NewObject<UOBP_User>();

	ovrRequest RequestId = ovr_User_Get(ovrId);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this, User](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Error getting user."));
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_User_Get)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got user."));
				User->ovrUserHandle = ovr_Message_GetUser(Message);
				OnSuccess.Broadcast(User);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get user."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
}

UOBP_GetUser* UOBP_GetUser::GetUser(UObject* WorldContextObject, int64 UserId)
{
	UOBP_GetUser* UserToGet = NewObject<UOBP_GetUser>();
	UserToGet->ovrId = UserId;
	return UserToGet;
}

void UOBP_LoggedInUser::Activate()
{
	UOBP_User* LoggedInUser = NewObject<UOBP_User>();

	ovrRequest RequestId = ovr_User_GetLoggedInUser();

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this, LoggedInUser](ovrMessageHandle Message, bool bIsError)
	{		
		if (bIsError) 
		{
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Error getting logged in user."));
			OnFailure.Broadcast(nullptr);
		}
		else 
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_User_GetLoggedInUser)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got logged in user."));
				LoggedInUser->ovrUserHandle = ovr_Message_GetUser(Message);
				OnSuccess.Broadcast(LoggedInUser);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get logged in user."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
}

UOBP_LoggedInUser* UOBP_LoggedInUser::GetLoggedInUser(UObject* WorldContextObject)
{
	return NewObject<UOBP_LoggedInUser>();
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
	OBP_PlatformVersionError("GetDisplayName", "v18");
	return FString();
#endif
}


FString UOBP_User::GetPresence()
{
	return ovr_User_GetPresence(ovrUserHandle);
}

FString UOBP_User::GetPresenceDeeplinkMessage()
{
	return ovr_User_GetPresenceDeeplinkMessage(ovrUserHandle);
}

// requires OculusPlatfromSDK 1.41 or later
FString UOBP_User::GetPresenceDestinationApiName()
{
#if PLATFORM_MINOR_VERSION >= 41
	return ovr_User_GetPresenceDestinationApiName(ovrUserHandle);
#else
	OBP_PlatformVersionError("GetPresenceDestinationApiName", "1.41");
	return FString();
#endif
}

EOBP_UserPresenceStatus UOBP_User::GetPresenceStatus()
{
	switch (ovr_User_GetPresenceStatus(ovrUserHandle))
	{
	case ovrUserPresenceStatus::ovrUserPresenceStatus_Unknown:
		return EOBP_UserPresenceStatus::Unknown;
		break;
	case ovrUserPresenceStatus::ovrUserPresenceStatus_Online:
		return EOBP_UserPresenceStatus::Online;
		break;
	case ovrUserPresenceStatus::ovrUserPresenceStatus_Offline:
		return EOBP_UserPresenceStatus::Offline;
		break;
	default:
		return EOBP_UserPresenceStatus::Unknown;
		break;
	}
}

int64 UOBP_User::GetID()
{
	return ovr_User_GetID(ovrUserHandle);
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