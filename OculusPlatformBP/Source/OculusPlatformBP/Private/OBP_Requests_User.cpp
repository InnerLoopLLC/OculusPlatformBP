// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Requests_User.h"

// --------------------
// Initializers
// --------------------

UOBP_User_GetUser::UOBP_User_GetUser(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_User_GetAccessToken::UOBP_User_GetAccessToken(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_User_GetLoggedInUser::UOBP_User_GetLoggedInUser(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_User_GetLoggedInUserFriends::UOBP_User_GetLoggedInUserFriends(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_User_GetLoggedInUserFriendsAndRooms::UOBP_User_GetLoggedInUserFriendsAndRooms(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_User_GetLoggedInUserRecentlyMetUsersAndRooms::UOBP_User_GetLoggedInUserRecentlyMetUsersAndRooms(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_User_GetNextUserAndRoomArrayPage::UOBP_User_GetNextUserAndRoomArrayPage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_User_GetNextUserArrayPage::UOBP_User_GetNextUserArrayPage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_User_GetOrgScopedID::UOBP_User_GetOrgScopedID(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_User_GetSdkAccounts::UOBP_User_GetSdkAccounts(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_User_GetUserProof::UOBP_User_GetUserProof(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_User_LaunchFriendRequestFlow::UOBP_User_LaunchFriendRequestFlow(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_User_LaunchProfile::UOBP_User_LaunchProfile(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// --------------------
// OVR_Requests_User.h
// --------------------

//---GetUser---
void UOBP_User_GetUser::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_User_Get(OBP_FStringToInt64(ovrId));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure OnlineSubsystemOculus is enabled and DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_User_GetUser* UOBP_User_GetUser::GetUser(UObject* WorldContextObject, FString UserId)
{
	auto UserToGet = NewObject<UOBP_User_GetUser>();
	UserToGet->ovrId = UserId;
	return UserToGet;
}

//---GetAccessToken---
void UOBP_User_GetAccessToken::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_User_GetAccessToken();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure OnlineSubsystemOculus is enabled and DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast("");
	}
}

UOBP_User_GetAccessToken* UOBP_User_GetAccessToken::GetAccessToken(UObject* WorldContextObject)
{
	return NewObject<UOBP_User_GetAccessToken>();
}

//---GetLoggedInUser---
void UOBP_User_GetLoggedInUser::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_User_GetLoggedInUser();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure OnlineSubsystemOculus is enabled and DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_User_GetLoggedInUser* UOBP_User_GetLoggedInUser::GetLoggedInUser(UObject* WorldContextObject)
{
	return NewObject<UOBP_User_GetLoggedInUser>();
}

//---GetLoggedInUserFriends---
void UOBP_User_GetLoggedInUserFriends::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_User_GetLoggedInUserFriends();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure OnlineSubsystemOculus is enabled and DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_User_GetLoggedInUserFriends* UOBP_User_GetLoggedInUserFriends::GetLoggedInUserFriends(UObject* WorldContextObject)
{
	return NewObject<UOBP_User_GetLoggedInUserFriends>();
}

//---GetLoggedInUserFriendsAndRooms---
void UOBP_User_GetLoggedInUserFriendsAndRooms::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_User_GetLoggedInUserFriendsAndRooms();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure OnlineSubsystemOculus is enabled and DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_User_GetLoggedInUserFriendsAndRooms* UOBP_User_GetLoggedInUserFriendsAndRooms::GetLoggedInUserFriendsAndRooms(UObject* WorldContextObject)
{
	return NewObject<UOBP_User_GetLoggedInUserFriendsAndRooms>();
}

//---GetLoggedInUserRecentlyMetUsersAndRooms---
void UOBP_User_GetLoggedInUserRecentlyMetUsersAndRooms::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_User_GetLoggedInUserRecentlyMetUsersAndRooms(UserOptions->ovrUserOptionsHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure OnlineSubsystemOculus is enabled and DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_User_GetLoggedInUserRecentlyMetUsersAndRooms* UOBP_User_GetLoggedInUserRecentlyMetUsersAndRooms::GetLoggedInUserRecentlyMetUsersAndRooms(UObject* WorldContextObject, UOBP_UserOptions* UserOptions)
{
	auto LoggedInUserRecentlyMetUsersAndRooms = NewObject<UOBP_User_GetLoggedInUserRecentlyMetUsersAndRooms>();
	LoggedInUserRecentlyMetUsersAndRooms->UserOptions = UserOptions;
	return LoggedInUserRecentlyMetUsersAndRooms;
}

//---GetNextUserAndRoomArrayPage---
void UOBP_User_GetNextUserAndRoomArrayPage::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_User_GetNextUserAndRoomArrayPage(UserAndRoomArray->ovrUserAndRoomArrayHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure OnlineSubsystemOculus is enabled and DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_User_GetNextUserAndRoomArrayPage* UOBP_User_GetNextUserAndRoomArrayPage::GetNextUserAndRoomArrayPage(UObject* WorldContextObject, UOBP_UserAndRoomArray* UserAndRoomArray)
{
	auto NextUserAndRoomArrayPage = NewObject<UOBP_User_GetNextUserAndRoomArrayPage>();
	NextUserAndRoomArrayPage->UserAndRoomArray = UserAndRoomArray;
	return NextUserAndRoomArrayPage;
}

//---GetNextUserArrayPage---
void UOBP_User_GetNextUserArrayPage::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_User_GetNextUserArrayPage(UserArray->ovrUserArrayHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure OnlineSubsystemOculus is enabled and DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_User_GetNextUserArrayPage* UOBP_User_GetNextUserArrayPage::GetNextUserArrayPage(UObject* WorldContextObject, UOBP_UserArray* UserArray)
{
	auto NextUserArrayPage = NewObject<UOBP_User_GetNextUserArrayPage>();
	NextUserArrayPage->UserArray = UserArray;
	return NextUserArrayPage;
}

//---GetOrgScopedID---
void UOBP_User_GetOrgScopedID::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_User_GetOrgScopedID(OBP_FStringToInt64(UserID));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("User::GetOrgScopedID", Message);
				OnFailure.Broadcast("");
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_User_GetOrgScopedID)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got org scoped ID."));
					// message returns an org scoped ID handle, but it doesn't contain anything other than an ID, so we're skipping a step and just returning the ID directly
					int64 OrgScopedId = ovr_OrgScopedID_GetID(ovr_Message_GetOrgScopedID(Message));
					FString OrgScopedIdString = OBP_Int64ToFString(OrgScopedId);
					OnSuccess.Broadcast(OrgScopedIdString);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get org scoped ID."));
					OnFailure.Broadcast("");
				}
			}
		}));
	}
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure OnlineSubsystemOculus is enabled and DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast("");
	}
}

UOBP_User_GetOrgScopedID* UOBP_User_GetOrgScopedID::GetOrgScopedID(UObject* WorldContextObject, FString UserID)
{
	auto UserIDToGet = NewObject<UOBP_User_GetOrgScopedID>();
	UserIDToGet->UserID = UserID;
	return UserIDToGet;
}

//---GetSdkAccounts---
void UOBP_User_GetSdkAccounts::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_User_GetSdkAccounts();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure OnlineSubsystemOculus is enabled and DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_User_GetSdkAccounts* UOBP_User_GetSdkAccounts::GetSdkAccounts(UObject* WorldContextObject)
{
	return NewObject<UOBP_User_GetSdkAccounts>();
}

//---GetUserProof---
void UOBP_User_GetUserProof::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_User_GetUserProof();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure OnlineSubsystemOculus is enabled and DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast("");
	}
}

UOBP_User_GetUserProof* UOBP_User_GetUserProof::GetUserProof(UObject* WorldContextObject)
{
	return NewObject<UOBP_User_GetUserProof>();
}

//---LaunchFriendRequestFlow---
void UOBP_User_LaunchFriendRequestFlow::Activate()
{
#if PLATFORM_MINOR_VERSION >= 28
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_User_LaunchFriendRequestFlow(OBP_FStringToInt64(UserID));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
	}
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure OnlineSubsystemOculus is enabled and DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(false, false);
	}
#else
	OBP_PlatformVersionError("User::LaunchFriendRequestFlow", "1.28");
	OnFailure.Broadcast(false, false);
#endif
}

UOBP_User_LaunchFriendRequestFlow* UOBP_User_LaunchFriendRequestFlow::LaunchFriendRequestFlow(UObject* WorldContextObject, FString UserID)
{
	auto FriendRequestFlowToLaunch = NewObject<UOBP_User_LaunchFriendRequestFlow>();
	FriendRequestFlowToLaunch->UserID = UserID;
	return FriendRequestFlowToLaunch;
}

//---LaunchProfile---
void UOBP_User_LaunchProfile::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_User_LaunchProfile(OBP_FStringToInt64(UserID));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure OnlineSubsystemOculus is enabled and DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast();
	}
}

UOBP_User_LaunchProfile* UOBP_User_LaunchProfile::LaunchProfile(UObject* WorldContextObject, FString UserID)
{
	auto ProfileToLaunch = NewObject<UOBP_User_LaunchProfile>();
	ProfileToLaunch->UserID = UserID;
	return ProfileToLaunch;
}