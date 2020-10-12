// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBPUser.h"

// --------------------
// Initializers
// --------------------

UOBP_User::UOBP_User(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_UserArray::UOBP_UserArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_UserAndRoom::UOBP_UserAndRoom(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_UserAndRoomArray::UOBP_UserAndRoomArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_UserOptions::UOBP_UserOptions(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_SdkAccountArray::UOBP_SdkAccountArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_SdkAccount::UOBP_SdkAccount(const FObjectInitializer& ObjectInitializer)
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

UOBP_GetLoggedInUserFriendsAndRooms::UOBP_GetLoggedInUserFriendsAndRooms(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_GetLoggedInUserRecentlyMetUsersAndRooms::UOBP_GetLoggedInUserRecentlyMetUsersAndRooms(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_GetNextUserAndRoomArrayPage::UOBP_GetNextUserAndRoomArrayPage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_GetNextUserArrayPage::UOBP_GetNextUserArrayPage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_GetOrgScopedID::UOBP_GetOrgScopedID(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_GetSdkAccounts::UOBP_GetSdkAccounts(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_GetUserProof::UOBP_GetUserProof(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_LaunchFriendRequestFlow::UOBP_LaunchFriendRequestFlow(const FObjectInitializer& ObjectInitializer)
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
	ovrRequest RequestId = ovr_User_Get(ovrId);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("User::GetUser", Message);
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_User_Get)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got user."));
				auto ThisUser = NewObject<UOBP_User>();
				ThisUser->ovrUserHandle = ovr_Message_GetUser(Message);
				OnSuccess.Broadcast(ThisUser);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get user."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
}

UOBP_GetUser* UOBP_GetUser::GetUser(UObject* WorldContextObject, int32 UserId)
{
	auto UserToGet = NewObject<UOBP_GetUser>();
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
			OBP_MessageError("User::GetAccessToken", Message);
			OnFailure.Broadcast("");
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_User_GetAccessToken)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got access token."));
				auto ThisAccessToken = ovr_Message_GetString(Message);
				OnSuccess.Broadcast(ThisAccessToken);
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
	ovrRequest RequestId = ovr_User_GetLoggedInUser();

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{		
		if (bIsError) 
		{
			OBP_MessageError("User::GetLoggedInUser", Message);
			OnFailure.Broadcast(nullptr);
		}
		else 
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_User_GetLoggedInUser)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got logged in user."));
				auto LoggedInUser = NewObject<UOBP_User>();
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
	ovrRequest RequestId = ovr_User_GetLoggedInUserFriends();

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("User::GetLoggedInUserFriends", Message);
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_User_GetLoggedInUserFriends)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got logged in user's friends."));
				auto LoggedInUserFriends = NewObject<UOBP_UserArray>();
				LoggedInUserFriends->ovrUserArrayHandle = ovr_Message_GetUserArray(Message);
				OnSuccess.Broadcast(LoggedInUserFriends);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get logged in user's friends."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
}

UOBP_GetLoggedInUserFriends* UOBP_GetLoggedInUserFriends::GetLoggedInUserFriends(UObject* WorldContextObject)
{
	return NewObject<UOBP_GetLoggedInUserFriends>();
}

//---GetLoggedInUserFriendsAndRooms---
void UOBP_GetLoggedInUserFriendsAndRooms::Activate()
{
	ovrRequest RequestId = ovr_User_GetLoggedInUserFriendsAndRooms();

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("User::GetLoggedInUserFriendsAndRooms", Message);
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_User_GetLoggedInUserFriendsAndRooms)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got logged in user's friends and rooms."));
				auto LoggedInUserFriendsAndRooms = NewObject<UOBP_UserAndRoomArray>();
				LoggedInUserFriendsAndRooms->ovrUserAndRoomArrayHandle = ovr_Message_GetUserAndRoomArray(Message);
				OnSuccess.Broadcast(LoggedInUserFriendsAndRooms);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get logged in user's friends and rooms."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
}

UOBP_GetLoggedInUserFriendsAndRooms* UOBP_GetLoggedInUserFriendsAndRooms::GetLoggedInUserFriendsAndRooms(UObject* WorldContextObject)
{
	return NewObject<UOBP_GetLoggedInUserFriendsAndRooms>();
}

//---GetLoggedInUserRecentlyMetUsersAndRooms---
void UOBP_GetLoggedInUserRecentlyMetUsersAndRooms::Activate()
{
	ovrRequest RequestId = ovr_User_GetLoggedInUserRecentlyMetUsersAndRooms(UserOptions->ovrUserOptionsHandle);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("User::GetLoggedInUserRecentlyMetUsersAndRooms", Message);
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_User_GetLoggedInUserRecentlyMetUsersAndRooms)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got logged in user's recently met users and rooms."));
				auto LoggedInUserRecentlyMetUsersAndRooms = NewObject<UOBP_UserAndRoomArray>();
				LoggedInUserRecentlyMetUsersAndRooms->ovrUserAndRoomArrayHandle = ovr_Message_GetUserAndRoomArray(Message);
				OnSuccess.Broadcast(LoggedInUserRecentlyMetUsersAndRooms);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get logged in user's recently met users and rooms."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
}

UOBP_GetLoggedInUserRecentlyMetUsersAndRooms* UOBP_GetLoggedInUserRecentlyMetUsersAndRooms::GetLoggedInUserRecentlyMetUsersAndRooms(UObject* WorldContextObject, UOBP_UserOptions* UserOptions)
{
	auto LoggedInUserRecentlyMetUsersAndRooms = NewObject<UOBP_GetLoggedInUserRecentlyMetUsersAndRooms>();
	LoggedInUserRecentlyMetUsersAndRooms->UserOptions = UserOptions;
	return LoggedInUserRecentlyMetUsersAndRooms;
}

//---GetNextUserAndRoomArrayPage---
void UOBP_GetNextUserAndRoomArrayPage::Activate()
{
	ovrRequest RequestId = ovr_User_GetNextUserAndRoomArrayPage(UserAndRoomArray->ovrUserAndRoomArrayHandle);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("User::GetNextUserAndRoomArrayPage", Message);
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_User_GetNextUserAndRoomArrayPage)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got next user and room array page."));
				auto NextUserAndRoomArrayPage = NewObject<UOBP_UserAndRoomArray>();
				NextUserAndRoomArrayPage->ovrUserAndRoomArrayHandle = ovr_Message_GetUserAndRoomArray(Message);
				OnSuccess.Broadcast(NextUserAndRoomArrayPage);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get next user and room array page."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
}

UOBP_GetNextUserAndRoomArrayPage* UOBP_GetNextUserAndRoomArrayPage::GetNextUserAndRoomArrayPage(UObject* WorldContextObject, UOBP_UserAndRoomArray* UserAndRoomArray)
{
	auto NextUserAndRoomArrayPage = NewObject<UOBP_GetNextUserAndRoomArrayPage>();
	NextUserAndRoomArrayPage->UserAndRoomArray = UserAndRoomArray;
	return NextUserAndRoomArrayPage;
}

//---GetNextUserArrayPage---
void UOBP_GetNextUserArrayPage::Activate()
{
	ovrRequest RequestId = ovr_User_GetNextUserArrayPage(UserArray->ovrUserArrayHandle);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("User::GetNextUserArrayPage", Message);
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_User_GetNextUserArrayPage)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got next user array page."));
				auto NextUserArrayPage = NewObject<UOBP_UserArray>();
				NextUserArrayPage->ovrUserArrayHandle = ovr_Message_GetUserArray(Message);
				OnSuccess.Broadcast(NextUserArrayPage);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get next user array page."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
}

UOBP_GetNextUserArrayPage* UOBP_GetNextUserArrayPage::GetNextUserArrayPage(UObject* WorldContextObject, UOBP_UserArray* UserArray)
{
	auto NextUserArrayPage = NewObject<UOBP_GetNextUserArrayPage>();
	NextUserArrayPage->UserArray = UserArray;
	return NextUserArrayPage;
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
			OBP_MessageError("User::GetOrgScopedID", Message);
			OnFailure.Broadcast(0);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_User_GetOrgScopedID)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got org scoped ID."));
				// message returns an org scoped ID handle, but it doesn't contain anything other than an ID, so we're skipping a step and just returning the ID directly
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

UOBP_GetOrgScopedID* UOBP_GetOrgScopedID::GetOrgScopedID(UObject* WorldContextObject, int32 UserID)
{
	auto UserIDToGet = NewObject<UOBP_GetOrgScopedID>();
	UserIDToGet->UserID = UserID;
	return UserIDToGet;
}

//---GetSdkAccounts---
void UOBP_GetSdkAccounts::Activate()
{
	ovrRequest RequestId = ovr_User_GetSdkAccounts();

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("User::GetSdkAccounts", Message);
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_User_GetSdkAccounts)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got org scoped ID."));
				auto SdkAccountsArray = NewObject<UOBP_SdkAccountArray>();
				SdkAccountsArray->ovrSdkAccountArrayHandle = ovr_Message_GetSdkAccountArray(Message);
				OnSuccess.Broadcast(SdkAccountsArray);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get org scoped ID."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
}

UOBP_GetSdkAccounts* UOBP_GetSdkAccounts::GetSdkAccounts(UObject* WorldContextObject)
{
	return NewObject<UOBP_GetSdkAccounts>();
}

//---GetUserProof---
void UOBP_GetUserProof::Activate()
{
	ovrRequest RequestId = ovr_User_GetUserProof();

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("User::GetUserProof", Message);
			OnFailure.Broadcast("");
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_User_GetUserProof)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got org scoped ID."));
				// message returns an ovrUserProofHandle, but it doesn't contain anything other than a nonce, so we're skipping a step and just returning the nonce directly
				OnSuccess.Broadcast(ovr_UserProof_GetNonce(ovr_Message_GetUserProof(Message)));
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get org scoped ID."));
				OnFailure.Broadcast("");
			}
		}
	}));
}

UOBP_GetUserProof* UOBP_GetUserProof::GetUserProof(UObject* WorldContextObject)
{
	return NewObject<UOBP_GetUserProof>();
}

//---LaunchFriendRequestFlow---
void UOBP_LaunchFriendRequestFlow::Activate()
{
#if PLATFORM_MINOR_VERSION >= 28
	ovrRequest RequestId = ovr_User_LaunchFriendRequestFlow(UserID);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("User::LaunchFriendRequestFlow", Message);
			OnFailure.Broadcast(false, false);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_User_LaunchFriendRequestFlow)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully launched friend request flow."));
				auto FriendRequestFlowResult = ovr_Message_GetLaunchFriendRequestFlowResult(Message);
				auto bDidCancel = ovr_LaunchFriendRequestFlowResult_GetDidCancel(FriendRequestFlowResult);
				auto bDidSendRequest = ovr_LaunchFriendRequestFlowResult_GetDidSendRequest(FriendRequestFlowResult);
				OnSuccess.Broadcast(bDidCancel, bDidSendRequest);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to launch friend request flow."));
				OnFailure.Broadcast(false, false);
			}
		}
	}));
#else
	OBP_PlatformVersionError("User::LaunchFriendRequestFlow", "1.28");
	OnFailure.Broadcast(false, false);
#endif
}

UOBP_LaunchFriendRequestFlow* UOBP_LaunchFriendRequestFlow::LaunchFriendRequestFlow(UObject* WorldContextObject, int32 UserID)
{
	auto FriendRequestFlowToLaunch = NewObject<UOBP_LaunchFriendRequestFlow>();
	FriendRequestFlowToLaunch->UserID = UserID;
	return FriendRequestFlowToLaunch;
}

//---LaunchProfile---
void UOBP_LaunchProfile::Activate()
{
	ovrRequest RequestId = ovr_User_LaunchProfile(UserID);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("User::LaunchProfile", Message);
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

UOBP_LaunchProfile* UOBP_LaunchProfile::LaunchProfile(UObject* WorldContextObject, int32 UserID)
{
	auto ProfileToLaunch = NewObject<UOBP_LaunchProfile>();
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

// requires OculusPlatfromSDK 1.40 or later
FString UOBP_User::GetPresenceDeeplinkMessage()
{
#if PLATFORM_MINOR_VERSION >= 50
	return ovr_User_GetPresenceDeeplinkMessage(ovrUserHandle);
#else
	OBP_PlatformVersionError("GetPresenceDeeplinkMessage", "1.40");
	return FString();
#endif
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

int32 UOBP_User::GetID()
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

// --------------------
// OVR_UserArray.h
// --------------------

UOBP_User* UOBP_UserArray::GetElement(int32 Index)
{
	auto UserToGet = NewObject<UOBP_User>();
	UserToGet->ovrUserHandle = ovr_UserArray_GetElement(ovrUserArrayHandle, Index);
	return UserToGet;
}

FString UOBP_UserArray::GetNextUrl()
{
	return ovr_UserArray_GetNextUrl(ovrUserArrayHandle);
}

int32 UOBP_UserArray::GetSize()
{
	return ovr_UserArray_GetSize(ovrUserArrayHandle);
}

bool UOBP_UserArray::HasNextPage()
{
	return ovr_UserArray_HasNextPage(ovrUserArrayHandle);
}

// --------------------
// OVR_UserAndRoom.h
// --------------------

/* Still need to implement ovr_Room.h

UOBP_Room* UOBP_UserAndRoom::GetRoom()
{
	auto RoomToGet = NewObject<UOBP_Room>();
	RoomToGet->ovrUserHandle = ovr_UserAndRoom_GetRoom(ovrUserAndRoomHandle);
	return RoomToGet;
}
*/

UOBP_User* UOBP_UserAndRoom::GetUser()
{
	auto UserToGet = NewObject<UOBP_User>();
	UserToGet->ovrUserHandle = ovr_UserAndRoom_GetUser(ovrUserAndRoomHandle);
	return UserToGet;
}

// --------------------
// OVR_UserAndRoomArray.h
// --------------------

UOBP_UserAndRoom* UOBP_UserAndRoomArray::GetElement(int32 Index)
{
	auto UserAndRoomToGet = NewObject<UOBP_UserAndRoom>();
	UserAndRoomToGet->ovrUserAndRoomHandle = ovr_UserAndRoomArray_GetElement(ovrUserAndRoomArrayHandle, Index);
	return UserAndRoomToGet;
}

FString UOBP_UserAndRoomArray::GetNextUrl()
{
	return ovr_UserAndRoomArray_GetNextUrl(ovrUserAndRoomArrayHandle);
}

int32 UOBP_UserAndRoomArray::GetSize()
{
	return ovr_UserAndRoomArray_GetSize(ovrUserAndRoomArrayHandle);
}

bool UOBP_UserAndRoomArray::HasNextPage()
{
	return ovr_UserAndRoomArray_HasNextPage(ovrUserAndRoomArrayHandle);
}

// --------------------
// OVR_UserOptions.h
// --------------------

UOBP_UserOptions* UOBP_UserOptions::CreateUserOptions()
{
	auto UserOptions = NewObject<UOBP_UserOptions>();
	UserOptions->ovrUserOptionsHandle = ovr_UserOptions_Create();
	return UserOptions;
}

void UOBP_UserOptions::DestroyUserOptions()
{
	ovr_UserOptions_Destroy(ovrUserOptionsHandle);
}

void UOBP_UserOptions::SetMaxUsers(int32 MaxUsers)
{
	ovr_UserOptions_SetMaxUsers(ovrUserOptionsHandle, MaxUsers);
}

void UOBP_UserOptions::AddServiceProvider(EOBPServiceProvider ServiceProvider)
{
	switch (ServiceProvider)
	{
	case EOBPServiceProvider::Unknown:
		ovr_UserOptions_AddServiceProvider(ovrUserOptionsHandle, ovrServiceProvider_Unknown);
		break;
	case EOBPServiceProvider::Dropbox:
		ovr_UserOptions_AddServiceProvider(ovrUserOptionsHandle, ovrServiceProvider_Dropbox);
		break;
	case EOBPServiceProvider::Facebook:
		ovr_UserOptions_AddServiceProvider(ovrUserOptionsHandle, ovrServiceProvider_Facebook);
		break;
	case EOBPServiceProvider::Google:
		ovr_UserOptions_AddServiceProvider(ovrUserOptionsHandle, ovrServiceProvider_Google);
		break;
	case EOBPServiceProvider::Instagram:
		ovr_UserOptions_AddServiceProvider(ovrUserOptionsHandle, ovrServiceProvider_Instagram);
		break;
	case EOBPServiceProvider::RemoteMedia:
		ovr_UserOptions_AddServiceProvider(ovrUserOptionsHandle, ovrServiceProvider_RemoteMedia);
		break;
	}
}

void UOBP_UserOptions::ClearServiceProviders()
{
	ovr_UserOptions_ClearServiceProviders(ovrUserOptionsHandle);
}

void UOBP_UserOptions::SetTimeWindow(EOBPTimeWindow TimeWindow)
{
	switch (TimeWindow)
	{
	case EOBPTimeWindow::Unknown:
		ovr_UserOptions_SetTimeWindow(ovrUserOptionsHandle, ovrTimeWindow_Unknown);
		break;
	case EOBPTimeWindow::OneHour:
		ovr_UserOptions_SetTimeWindow(ovrUserOptionsHandle, ovrTimeWindow_OneHour);
		break;
	case EOBPTimeWindow::OneDay:
		ovr_UserOptions_SetTimeWindow(ovrUserOptionsHandle, ovrTimeWindow_OneDay);
		break;
	case EOBPTimeWindow::OneWeek:
		ovr_UserOptions_SetTimeWindow(ovrUserOptionsHandle, ovrTimeWindow_OneWeek);
		break;
	case EOBPTimeWindow::ThirtyDays:
		ovr_UserOptions_SetTimeWindow(ovrUserOptionsHandle, ovrTimeWindow_ThirtyDays);
		break;
	case EOBPTimeWindow::NinetyDays:
		ovr_UserOptions_SetTimeWindow(ovrUserOptionsHandle, ovrTimeWindow_NinetyDays);
		break;
	}
}

// --------------------
// OVR_SdkAccountArray.h
// --------------------

UOBP_SdkAccount* UOBP_SdkAccountArray::GetElement(int32 Index)
{
	auto SdkAccount = NewObject<UOBP_SdkAccount>();
	SdkAccount->ovrSdkAccountHandle = ovr_SdkAccountArray_GetElement(ovrSdkAccountArrayHandle, Index);
	return SdkAccount;
}

int32 UOBP_SdkAccountArray::GetSize()
{
	return ovr_SdkAccountArray_GetSize(ovrSdkAccountArrayHandle);
}

// --------------------
// OVR_SdkAccount.h
// --------------------

EOBPSdkAccountType UOBP_SdkAccount::GetAccountType()
{
	switch (ovr_SdkAccount_GetAccountType(ovrSdkAccountHandle))
	{
	case ovrSdkAccountType_Unknown:
		return EOBPSdkAccountType::Unknown;
		break;
	case ovrSdkAccountType_Oculus:
		return EOBPSdkAccountType::Oculus;
		break;
	case ovrSdkAccountType_FacebookGameroom:
		return EOBPSdkAccountType::FacebookGameroom;
		break;
	default:
		return EOBPSdkAccountType::Unknown;
		break;
	}
}

int32 UOBP_SdkAccount::GetUserId()
{
	return ovr_SdkAccount_GetUserId(ovrSdkAccountHandle);
}