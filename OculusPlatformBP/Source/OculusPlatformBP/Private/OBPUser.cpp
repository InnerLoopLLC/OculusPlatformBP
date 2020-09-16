// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBPUser.h"

// --------------------
// Initializers
// --------------------

UOBP_User::UOBP_User(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_GetUser::UOBP_GetUser(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_GetAccessToken::UOBP_GetAccessToken(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_GetLoggedInUser::UOBP_GetLoggedInUser(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_GetLoggedInUserFriends::UOBP_GetLoggedInUserFriends(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_GetOrgScopedID::UOBP_GetOrgScopedID(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_LaunchProfile::UOBP_LaunchProfile(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_Requests_User.h
// --------------------

//---GetUser---

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

//---GetAccessToken---

void UOBP_GetAccessToken::Activate()
{
	ovrRequest RequestId = ovr_User_GetAccessToken();

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Error getting access token."));
			OnFailure.Broadcast("");
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_User_GetAccessToken)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got access token."));
				AccessToken = ovr_Message_GetString(Message);
				OnSuccess.Broadcast(AccessToken);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get acess token."));
				OnFailure.Broadcast("");
			}
		}
	}));
}

UOBP_GetAccessToken* UOBP_GetAccessToken::GetAccessToken(UObject* WorldContextObject)
{
	return NewObject<UOBP_GetAccessToken>();
}

//---GetLoggedInUser---

void UOBP_GetLoggedInUser::Activate()
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

UOBP_GetLoggedInUser* UOBP_GetLoggedInUser::GetLoggedInUser(UObject* WorldContextObject)
{
	return NewObject<UOBP_GetLoggedInUser>();
}

//---GetLoggedInUserFriends---

void UOBP_GetLoggedInUserFriends::Activate()
{
	//should be UOBP_UserArrayHandle
	UOBP_User* LoggedInUserFriends = NewObject<UOBP_User>();

	ovrRequest RequestId = ovr_User_GetLoggedInUserFriends();

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this, LoggedInUserFriends](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Error getting logged in user friends."));
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_User_GetLoggedInUserFriends)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got logged in user friends."));
				//need to implement UOBP_UserArrayHandle
				//LoggedInUserFriends->ovrUserHandle = ovr_Message_GetUserArray(Message);
				OnSuccess.Broadcast(LoggedInUserFriends);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get logged in user friends."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
}

UOBP_GetLoggedInUserFriends* UOBP_GetLoggedInUserFriends::GetLoggedInUserFriends(UObject* WorldContextObject)
{
	return NewObject<UOBP_GetLoggedInUserFriends>();
}

//---GetOrgScopedID---

void UOBP_GetOrgScopedID::Activate()
{
	ovrRequest RequestId = ovr_User_GetOrgScopedID(UserID);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Error getting org scoped ID."));
			OnFailure.Broadcast(0);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_User_GetOrgScopedID)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got org scoped ID."));
				// message returns and org scoped ID handle, but it doesn't contain anything other than an ID, so we're skipping a step and just returning the ID directly
				OnSuccess.Broadcast(ovr_OrgScopedID_GetID(ovr_Message_GetOrgScopedID(Message)));
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get org scoped ID."));
				OnFailure.Broadcast(0);
			}
		}
	}));
}

UOBP_GetOrgScopedID* UOBP_GetOrgScopedID::GetOrgScopedID(UObject* WorldContextObject, int64 UserID)
{
	UOBP_GetOrgScopedID* UserIDToGet = NewObject<UOBP_GetOrgScopedID>();
	UserIDToGet->UserID = UserID;
	return UserIDToGet;
}

//---GetOrgScopedID---

void UOBP_LaunchProfile::Activate()
{
	ovrRequest RequestId = ovr_User_LaunchProfile(UserID);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Error launching profile."));
			OnFailure.Broadcast();
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_User_LaunchProfile)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully launched profile."));
				OnSuccess.Broadcast();
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to launch profile."));
				OnFailure.Broadcast();
			}
		}
	}));
}

UOBP_LaunchProfile* UOBP_LaunchProfile::LaunchProfile(UObject* WorldContextObject, int64 UserID)
{
	UOBP_LaunchProfile* ProfileToLaunch = NewObject<UOBP_LaunchProfile>();
	ProfileToLaunch->UserID = UserID;
	return ProfileToLaunch;
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