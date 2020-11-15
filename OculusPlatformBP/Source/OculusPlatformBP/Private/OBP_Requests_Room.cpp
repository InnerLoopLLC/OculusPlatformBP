// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Requests_Room.h"

// --------------------
// Initializers
// --------------------

/*
UOBP_Room_CreateAndJoinPrivate2::UOBP_Room_CreateAndJoinPrivate2(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}*/

UOBP_Room_Get::UOBP_Room_Get(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Room_GetCurrent::UOBP_Room_GetCurrent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Room_GetCurrentForUser::UOBP_Room_GetCurrentForUser(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Room_KickUser::UOBP_Room_KickUser(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Room_Leave::UOBP_Room_Leave(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Room_SetDescription::UOBP_Room_SetDescription(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Room_UpdateMembershipLockStatus::UOBP_Room_UpdateMembershipLockStatus(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Room_UpdateOwner::UOBP_Room_UpdateOwner(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Room_UpdatePrivateRoomJoinPolicy::UOBP_Room_UpdatePrivateRoomJoinPolicy(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// ovr_Requests_Room.h
// --------------------

//---CreateAndJoinPrivate2--- 
/*
void UOBP_Room_CreateAndJoinPrivate2::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Room_CreateAndJoinPrivate2();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Room::CreateAndJoinPrivate2", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Room_CreateAndJoinPrivate2)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully created and joined private room."));
					auto Room = NewObject<UOBP_Room>();
					Room->ovrRoomHandle = ovr_Message_GetRoom(Message);
					OnSuccess.Broadcast(Room);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to create and join private room."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(nullptr);
	}
}


UOBP_Room_CreateAndJoinPrivate2* UOBP_Room_CreateAndJoinPrivate2::CreateAndJoinPrivate2(UObject* WorldContextObject, EOBP_RoomJoinPolicy JoinPolicy, int32 MaxUsers, UOBP_RoomOptions* RoomOptions)
{
	auto CreateAndJoinPrivate2 = NewObject<UOBP_Room_CreateAndJoinPrivate2>();
	CreateAndJoinPrivate2->JoinPolicy = JoinPolicy;
	CreateAndJoinPrivate2->MaxUsers = MaxUsers;
	CreateAndJoinPrivate2->RoomOptions = RoomOptions;
	return CreateAndJoinPrivate2;
} */

//---GetRoom---
void UOBP_Room_Get::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Room_Get(OBP_FStringToInt64(RoomID));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Room::GetRoom", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Room_Get)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got room."));
					auto Room = NewObject<UOBP_Room>();
					Room->ovrRoomHandle = ovr_Message_GetRoom(Message);
					OnSuccess.Broadcast(Room);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get room."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_Room_Get* UOBP_Room_Get::GetRoom(UObject* WorldContextObject, FString RoomID)
{
	auto RoomToGet = NewObject<UOBP_Room_Get>();
	RoomToGet->RoomID = RoomID;
	return RoomToGet;
}

//---GetCurrentRoom---
void UOBP_Room_GetCurrent::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Room_GetCurrent();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Room::GetCurrentRoom", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Room_GetCurrent)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got current room."));
					auto Room = NewObject<UOBP_Room>();
					Room->ovrRoomHandle = ovr_Message_GetRoom(Message);
					OnSuccess.Broadcast(Room);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get current room."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_Room_GetCurrent* UOBP_Room_GetCurrent::GetCurrentRoom(UObject* WorldContextObject)
{
	return NewObject<UOBP_Room_GetCurrent>();
}

//---GetCurrentRoomForUser---
void UOBP_Room_GetCurrentForUser::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Room_GetCurrentForUser(OBP_FStringToInt64(UserID));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Room::GetCurrentRoomForUser", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Room_GetCurrentForUser)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got current room for user."));
					auto Room = NewObject<UOBP_Room>();
					Room->ovrRoomHandle = ovr_Message_GetRoom(Message);
					OnSuccess.Broadcast(Room);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get current room for user."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_Room_GetCurrentForUser* UOBP_Room_GetCurrentForUser::GetCurrentRoomForUser(UObject* WorldContextObject, FString UserID)
{
	auto GetCurrentRoomForUser = NewObject<UOBP_Room_GetCurrentForUser>();
	GetCurrentRoomForUser->UserID = UserID;
	return GetCurrentRoomForUser;
}

//---KickUser---
void UOBP_Room_KickUser::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Room_KickUser(OBP_FStringToInt64(RoomID), OBP_FStringToInt64(UserID), KickDurationSeconds);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Room::KickUser", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Room_KickUser)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully kicked user from room."));
					auto Room = NewObject<UOBP_Room>();
					Room->ovrRoomHandle = ovr_Message_GetRoom(Message);
					OnSuccess.Broadcast(Room);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to kick user from room."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_Room_KickUser* UOBP_Room_KickUser::KickUser(UObject* WorldContextObject, FString RoomID, FString UserID, int32 KickDurationSeconds)
{
	auto KickUser = NewObject<UOBP_Room_KickUser>();
	KickUser->RoomID = RoomID;
	KickUser->UserID = UserID;
	KickUser->KickDurationSeconds = KickDurationSeconds;
	return KickUser;
}

//---Leave---
void UOBP_Room_Leave::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Room_Leave(OBP_FStringToInt64(RoomID));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Room::Leave", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Room_Leave)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully left room."));
					auto Room = NewObject<UOBP_Room>();
					Room->ovrRoomHandle = ovr_Message_GetRoom(Message);
					OnSuccess.Broadcast(Room);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to leave room."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_Room_Leave* UOBP_Room_Leave::Leave(UObject* WorldContextObject, FString RoomID)
{
	auto Leave = NewObject<UOBP_Room_Leave>();
	Leave->RoomID = RoomID;
	return Leave;
}

//---SetDescription---
void UOBP_Room_SetDescription::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Room_SetDescription(OBP_FStringToInt64(RoomID), TCHAR_TO_ANSI(*Description));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Room::SetDescription", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Room_SetDescription)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully set room description."));
					auto Room = NewObject<UOBP_Room>();
					Room->ovrRoomHandle = ovr_Message_GetRoom(Message);
					OnSuccess.Broadcast(Room);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to set room description."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_Room_SetDescription* UOBP_Room_SetDescription::SetDescription(UObject* WorldContextObject, FString RoomID, FString Description)
{
	auto SetDescription = NewObject<UOBP_Room_SetDescription>();
	SetDescription->RoomID = RoomID;
	SetDescription->Description = Description;
	return SetDescription;
}

//---UpdateRoomMembershipLockStatus---
void UOBP_Room_UpdateMembershipLockStatus::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRoomMembershipLockStatus RoomMembershipLockStatus;

		switch (MembershipLockStatus)
		{
		case EOBP_RoomMembershipLockStatus::Unknown:
			RoomMembershipLockStatus = ovrRoomMembershipLockStatus_Unknown;
			break;
		case EOBP_RoomMembershipLockStatus::Lock:
			RoomMembershipLockStatus = ovrRoomMembershipLockStatus_Lock;
			break;
		case EOBP_RoomMembershipLockStatus::Unlock:
			RoomMembershipLockStatus = ovrRoomMembershipLockStatus_Unlock;
			break;
		default:
			RoomMembershipLockStatus = ovrRoomMembershipLockStatus_Unknown;
			break;
		}

		ovrRequest RequestId = ovr_Room_UpdateMembershipLockStatus(OBP_FStringToInt64(RoomID), RoomMembershipLockStatus);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Room::UpdateRoomMembershipLockStatus", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Room_UpdateMembershipLockStatus)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully update room membership lock status."));
					auto Room = NewObject<UOBP_Room>();
					Room->ovrRoomHandle = ovr_Message_GetRoom(Message);
					OnSuccess.Broadcast(Room);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to update room membership lock status."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_Room_UpdateMembershipLockStatus* UOBP_Room_UpdateMembershipLockStatus::UpdateRoomMembershipLockStatus(UObject* WorldContextObject, FString RoomID, EOBP_RoomMembershipLockStatus MembershipLockStatus)
{
	auto UpdateRoomMembershipLockStatus = NewObject<UOBP_Room_UpdateMembershipLockStatus>();
	UpdateRoomMembershipLockStatus->RoomID = RoomID;
	UpdateRoomMembershipLockStatus->MembershipLockStatus = MembershipLockStatus;
	return UpdateRoomMembershipLockStatus;
}

//---UpdateOwner---
void UOBP_Room_UpdateOwner::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Room_UpdateOwner(OBP_FStringToInt64(RoomID), OBP_FStringToInt64(UserID));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Room::UpdateOwner", Message);
				OnFailure.Broadcast();
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Room_UpdateOwner)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully updated owner."));
					OnSuccess.Broadcast();
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to update owner."));
					OnFailure.Broadcast();
				}
			}
		}));
	}
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast();
	}
}

UOBP_Room_UpdateOwner* UOBP_Room_UpdateOwner::UpdateOwner(UObject* WorldContextObject, FString RoomID, FString UserID)
{
	auto UpdateOwner = NewObject<UOBP_Room_UpdateOwner>();
	UpdateOwner->RoomID = RoomID;
	UpdateOwner->UserID = UserID;
	return UpdateOwner;
}

//---UpdatePrivateRoomJoinPolicy---
void UOBP_Room_UpdatePrivateRoomJoinPolicy::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRoomJoinPolicy RoomJoinPolicy;
		switch (JoinPolicy)
		{
		case EOBP_RoomJoinPolicy::None:
			RoomJoinPolicy = ovrRoom_JoinPolicyNone;
			break;
		case EOBP_RoomJoinPolicy::Everyone:
			RoomJoinPolicy = ovrRoom_JoinPolicyEveryone;
			break;
		case EOBP_RoomJoinPolicy::FriendsOfMembers:
			RoomJoinPolicy = ovrRoom_JoinPolicyFriendsOfMembers;
			break;
		case EOBP_RoomJoinPolicy::FriendsOfOwner:
			RoomJoinPolicy = ovrRoom_JoinPolicyFriendsOfOwner;
			break;
		case EOBP_RoomJoinPolicy::InvitedUsers:
			RoomJoinPolicy = ovrRoom_JoinPolicyInvitedUsers;
			break;
		case EOBP_RoomJoinPolicy::Unknown:
			RoomJoinPolicy = ovrRoom_JoinPolicyUnknown;
			break;
		default:
			RoomJoinPolicy = ovrRoom_JoinPolicyNone;
			break;
		}

		ovrRequest RequestId = ovr_Room_UpdatePrivateRoomJoinPolicy(OBP_FStringToInt64(RoomID), RoomJoinPolicy);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Room::UpdatePrivateRoomJoinPolicy", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Room_UpdatePrivateRoomJoinPolicy)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully updated private room join policy."));
					auto Room = NewObject<UOBP_Room>();
					Room->ovrRoomHandle = ovr_Message_GetRoom(Message);
					OnSuccess.Broadcast(Room);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to update private room join policy."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_Room_UpdatePrivateRoomJoinPolicy* UOBP_Room_UpdatePrivateRoomJoinPolicy::UpdatePrivateRoomJoinPolicy(UObject* WorldContextObject, FString RoomID, EOBP_RoomJoinPolicy JoinPolicy)
{
	auto UpdatePrivateRoomJoinPolicy = NewObject<UOBP_Room_UpdatePrivateRoomJoinPolicy>();
	UpdatePrivateRoomJoinPolicy->RoomID = RoomID;
	UpdatePrivateRoomJoinPolicy->JoinPolicy = JoinPolicy;
	return UpdatePrivateRoomJoinPolicy;
}