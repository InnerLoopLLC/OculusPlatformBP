// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Requests_Room.h"

// --------------------
// Initializers
// --------------------

UOBP_Room_CreateAndJoinPrivate2::UOBP_Room_CreateAndJoinPrivate2(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

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

UOBP_Room_GetInvitableUsers2::UOBP_Room_GetInvitableUsers2(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Room_GetModeratedRooms::UOBP_Room_GetModeratedRooms(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Room_GetNextRoomArrayPage::UOBP_Room_GetNextRoomArrayPage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Room_InviteUser::UOBP_Room_InviteUser(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Room_Join2::UOBP_Room_Join2(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Room_KickUser::UOBP_Room_KickUser(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Room_LaunchInvitableUserFlow::UOBP_Room_LaunchInvitableUserFlow(const FObjectInitializer& ObjectInitializer)
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

UOBP_Room_UpdateDataStore::UOBP_Room_UpdateDataStore(const FObjectInitializer& ObjectInitializer)
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
void UOBP_Room_CreateAndJoinPrivate2::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRoomJoinPolicy ovrRoomJoinPolicyHandle;
		switch (JoinPolicy)
		{
		case EOBP_RoomJoinPolicy::None:
			ovrRoomJoinPolicyHandle = ovrRoom_JoinPolicyNone;
			break;
		case EOBP_RoomJoinPolicy::Everyone:
			ovrRoomJoinPolicyHandle = ovrRoom_JoinPolicyEveryone;
			break;
		case EOBP_RoomJoinPolicy::FriendsOfMembers:
			ovrRoomJoinPolicyHandle = ovrRoom_JoinPolicyFriendsOfMembers;
			break;
		case EOBP_RoomJoinPolicy::FriendsOfOwner:
			ovrRoomJoinPolicyHandle = ovrRoom_JoinPolicyFriendsOfOwner;
			break;
		case EOBP_RoomJoinPolicy::InvitedUsers:
			ovrRoomJoinPolicyHandle = ovrRoom_JoinPolicyInvitedUsers;
			break;
		case EOBP_RoomJoinPolicy::Unknown:
			ovrRoomJoinPolicyHandle = ovrRoom_JoinPolicyUnknown;
			break;
		default:
			ovrRoomJoinPolicyHandle = ovrRoom_JoinPolicyNone;
			break;
		}

		ovrRoomOptions* ovrRoomOptionsHandle = ovr_RoomOptions_Create();

		ovr_RoomOptions_SetDataStoreString(ovrRoomOptionsHandle, TCHAR_TO_ANSI(*RoomOptions.DataStoreKey), TCHAR_TO_ANSI(*RoomOptions.DataStoreValue));
		ovr_RoomOptions_SetExcludeRecentlyMet(ovrRoomOptionsHandle, RoomOptions.bExcludeRecentlyMet);
		ovr_RoomOptions_SetMaxUserResults(ovrRoomOptionsHandle, RoomOptions.MaxUserResults);
		ovr_RoomOptions_SetRoomId(ovrRoomOptionsHandle, OBP_FStringToInt64(RoomOptions.RoomId));
		ovr_RoomOptions_SetTurnOffUpdates(ovrRoomOptionsHandle, RoomOptions.bTurnOffUpdates);

		switch (RoomOptions.Ordering)
		{
		case EOBP_UserOrdering::Unknown:
			ovr_RoomOptions_SetOrdering(ovrRoomOptionsHandle, ovrUserOrdering_Unknown);
			break;
		case EOBP_UserOrdering::None:
			ovr_RoomOptions_SetOrdering(ovrRoomOptionsHandle, ovrUserOrdering_None);
			break;
		case EOBP_UserOrdering::PresenceAlphabetical:
			ovr_RoomOptions_SetOrdering(ovrRoomOptionsHandle, ovrUserOrdering_PresenceAlphabetical);
			break;
		default:
			ovr_RoomOptions_SetOrdering(ovrRoomOptionsHandle, ovrUserOrdering_Unknown);
			break;
		}

		switch (RoomOptions.TimeWindow)
		{
		case EOBP_TimeWindow::Unknown:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_Unknown);
			break;
		case EOBP_TimeWindow::OneHour:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_OneHour);
			break;
		case EOBP_TimeWindow::OneDay:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_OneDay);
			break;
		case EOBP_TimeWindow::OneWeek:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_OneWeek);
			break;
		case EOBP_TimeWindow::ThirtyDays:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_ThirtyDays);
			break;
		case EOBP_TimeWindow::NinetyDays:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_NinetyDays);
			break;
		default:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_Unknown);
			break;
		}

		ovrRequest RequestId = ovr_Room_CreateAndJoinPrivate2(ovrRoomJoinPolicyHandle, MaxUsers, ovrRoomOptionsHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
		OBP_SubsystemError("Room::CreateAndJoinPrivate2");
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_Room_CreateAndJoinPrivate2* UOBP_Room_CreateAndJoinPrivate2::CreateAndJoinPrivate2(UObject* WorldContextObject, EOBP_RoomJoinPolicy JoinPolicy, int32 MaxUsers, FOBP_RoomOptionsStruct RoomOptions)
{
	auto CreateAndJoinPrivate2 = NewObject<UOBP_Room_CreateAndJoinPrivate2>();
	CreateAndJoinPrivate2->JoinPolicy = JoinPolicy;
	CreateAndJoinPrivate2->MaxUsers = MaxUsers;
	CreateAndJoinPrivate2->RoomOptions = RoomOptions;
	return CreateAndJoinPrivate2;
}

//---GetRoom---
void UOBP_Room_Get::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Room_Get(OBP_FStringToInt64(RoomID));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
		OBP_SubsystemError("Room::GetRoom");
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

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
		OBP_SubsystemError("Room::GetCurrentRoom");
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

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
		OBP_SubsystemError("Room::GetCurrentRoomForUser");
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_Room_GetCurrentForUser* UOBP_Room_GetCurrentForUser::GetCurrentRoomForUser(UObject* WorldContextObject, FString UserID)
{
	auto GetCurrentRoomForUser = NewObject<UOBP_Room_GetCurrentForUser>();
	GetCurrentRoomForUser->UserID = UserID;
	return GetCurrentRoomForUser;
}

//---GetInvitableUsers2---
void UOBP_Room_GetInvitableUsers2::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRoomOptions* ovrRoomOptionsHandle = ovr_RoomOptions_Create();

		ovr_RoomOptions_SetDataStoreString(ovrRoomOptionsHandle, TCHAR_TO_ANSI(*RoomOptions.DataStoreKey), TCHAR_TO_ANSI(*RoomOptions.DataStoreValue));
		ovr_RoomOptions_SetExcludeRecentlyMet(ovrRoomOptionsHandle, RoomOptions.bExcludeRecentlyMet);
		ovr_RoomOptions_SetMaxUserResults(ovrRoomOptionsHandle, RoomOptions.MaxUserResults);
		ovr_RoomOptions_SetRoomId(ovrRoomOptionsHandle, OBP_FStringToInt64(RoomOptions.RoomId));
		ovr_RoomOptions_SetTurnOffUpdates(ovrRoomOptionsHandle, RoomOptions.bTurnOffUpdates);

		switch (RoomOptions.Ordering)
		{
		case EOBP_UserOrdering::Unknown:
			ovr_RoomOptions_SetOrdering(ovrRoomOptionsHandle, ovrUserOrdering_Unknown);
			break;
		case EOBP_UserOrdering::None:
			ovr_RoomOptions_SetOrdering(ovrRoomOptionsHandle, ovrUserOrdering_None);
			break;
		case EOBP_UserOrdering::PresenceAlphabetical:
			ovr_RoomOptions_SetOrdering(ovrRoomOptionsHandle, ovrUserOrdering_PresenceAlphabetical);
			break;
		default:
			ovr_RoomOptions_SetOrdering(ovrRoomOptionsHandle, ovrUserOrdering_Unknown);
			break;
		}

		switch (RoomOptions.TimeWindow)
		{
		case EOBP_TimeWindow::Unknown:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_Unknown);
			break;
		case EOBP_TimeWindow::OneHour:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_OneHour);
			break;
		case EOBP_TimeWindow::OneDay:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_OneDay);
			break;
		case EOBP_TimeWindow::OneWeek:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_OneWeek);
			break;
		case EOBP_TimeWindow::ThirtyDays:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_ThirtyDays);
			break;
		case EOBP_TimeWindow::NinetyDays:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_NinetyDays);
			break;
		default:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_Unknown);
			break;
		}

		ovrRequest RequestId = ovr_Room_GetInvitableUsers2(ovrRoomOptionsHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Room::GetInvitableUsers2", Message);
				OnFailure.Broadcast(TArray<UOBP_User*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Room_GetInvitableUsers2)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got invitable users."));
					auto InvitableUsersArray = NewObject<UOBP_UserArray>();
					InvitableUsersArray->ovrUserArrayHandle = ovr_Message_GetUserArray(Message);

					TArray<UOBP_User*> InvitableUsers;

					for (size_t i = 0; i < ovr_UserArray_GetSize(InvitableUsersArray->ovrUserArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_User>();
						ThisElement->ovrUserHandle = ovr_UserArray_GetElement(InvitableUsersArray->ovrUserArrayHandle, i);
						InvitableUsers.Add(ThisElement);
					}

					OnSuccess.Broadcast(InvitableUsers, InvitableUsersArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get invitable users."));
					OnFailure.Broadcast(TArray<UOBP_User*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Room::GetInvitableUsers2");
		OnFailure.Broadcast(TArray<UOBP_User*>(), nullptr);
	}
}

UOBP_Room_GetInvitableUsers2* UOBP_Room_GetInvitableUsers2::GetInvitableUsers2(UObject* WorldContextObject, FOBP_RoomOptionsStruct RoomOptions)
{
	auto GetInvitableUsers2 = NewObject<UOBP_Room_GetInvitableUsers2>();
	GetInvitableUsers2->RoomOptions = RoomOptions;
	return GetInvitableUsers2;
}

//---GetModeratedRooms---
void UOBP_Room_GetModeratedRooms::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Room_GetModeratedRooms();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Room::GetModeratedRooms", Message);
				OnFailure.Broadcast(TArray<UOBP_Room*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Room_GetModeratedRooms)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got moderated rooms."));
					auto ModeratedRoomsArray = NewObject<UOBP_RoomArray>();
					ModeratedRoomsArray->ovrRoomArrayHandle = ovr_Message_GetRoomArray(Message);

					TArray<UOBP_Room*> ModeratedRooms;

					for (size_t i = 0; i < ovr_RoomArray_GetSize(ModeratedRoomsArray->ovrRoomArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_Room>();
						ThisElement->ovrRoomHandle = ovr_RoomArray_GetElement(ModeratedRoomsArray->ovrRoomArrayHandle, i);
						ModeratedRooms.Add(ThisElement);
					}

					OnSuccess.Broadcast(ModeratedRooms, ModeratedRoomsArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get moderated rooms."));
					OnFailure.Broadcast(TArray<UOBP_Room*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Room::GetModeratedRooms");
		OnFailure.Broadcast(TArray<UOBP_Room*>(), nullptr);
	}
}

UOBP_Room_GetModeratedRooms* UOBP_Room_GetModeratedRooms::GetModeratedRooms(UObject* WorldContextObject)
{
	return NewObject<UOBP_Room_GetModeratedRooms>();
}

//---GetNextRoomArrayPage---
void UOBP_Room_GetNextRoomArrayPage::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Room_GetNextRoomArrayPage(RoomArray->ovrRoomArrayHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Room::GetNextRoomArrayPage", Message);
				OnFailure.Broadcast(TArray<UOBP_Room*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Room_GetNextRoomArrayPage)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got next room array page."));
					auto NextRoomArrayPage = NewObject<UOBP_RoomArray>();
					NextRoomArrayPage->ovrRoomArrayHandle = ovr_Message_GetRoomArray(Message);
					
					TArray<UOBP_Room*> NextRooms;

					for (size_t i = 0; i < ovr_RoomArray_GetSize(NextRoomArrayPage->ovrRoomArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_Room>();
						ThisElement->ovrRoomHandle = ovr_RoomArray_GetElement(NextRoomArrayPage->ovrRoomArrayHandle, i);
						NextRooms.Add(ThisElement);
					}

					OnSuccess.Broadcast(NextRooms, NextRoomArrayPage);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get next room array page."));
					OnFailure.Broadcast(TArray<UOBP_Room*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Room::GetNextRoomArrayPage");
		OnFailure.Broadcast(TArray<UOBP_Room*>(), nullptr);
	}
}

UOBP_Room_GetNextRoomArrayPage* UOBP_Room_GetNextRoomArrayPage::GetNextRoomArrayPage(UObject* WorldContextObject, UOBP_RoomArray* RoomArray)
{
	auto GetNextRoomArrayPage = NewObject<UOBP_Room_GetNextRoomArrayPage>();
	GetNextRoomArrayPage->RoomArray = RoomArray;
	return GetNextRoomArrayPage;
}


//---InviteUser---
void UOBP_Room_InviteUser::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Room_InviteUser(OBP_FStringToInt64(RoomID), TCHAR_TO_ANSI(*InviteToken));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Room::InviteUser", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Room_InviteUser)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully invited user to room."));
					auto Room = NewObject<UOBP_Room>();
					Room->ovrRoomHandle = ovr_Message_GetRoom(Message);
					OnSuccess.Broadcast(Room);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to invite user to room."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Room::InviteUser");
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_Room_InviteUser* UOBP_Room_InviteUser::InviteUser(UObject* WorldContextObject, FString RoomID, FString InviteToken)
{
	auto InviteUser = NewObject<UOBP_Room_InviteUser>();
	InviteUser->RoomID = RoomID;
	InviteUser->InviteToken = InviteToken;
	return InviteUser;
}

//---Join2---
void UOBP_Room_Join2::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRoomOptions* ovrRoomOptionsHandle = ovr_RoomOptions_Create();

		ovr_RoomOptions_SetDataStoreString(ovrRoomOptionsHandle, TCHAR_TO_ANSI(*RoomOptions.DataStoreKey), TCHAR_TO_ANSI(*RoomOptions.DataStoreValue));
		ovr_RoomOptions_SetExcludeRecentlyMet(ovrRoomOptionsHandle, RoomOptions.bExcludeRecentlyMet);
		ovr_RoomOptions_SetMaxUserResults(ovrRoomOptionsHandle, RoomOptions.MaxUserResults);
		ovr_RoomOptions_SetRoomId(ovrRoomOptionsHandle, OBP_FStringToInt64(RoomOptions.RoomId));
		ovr_RoomOptions_SetTurnOffUpdates(ovrRoomOptionsHandle, RoomOptions.bTurnOffUpdates);

		switch (RoomOptions.Ordering)
		{
		case EOBP_UserOrdering::Unknown:
			ovr_RoomOptions_SetOrdering(ovrRoomOptionsHandle, ovrUserOrdering_Unknown);
			break;
		case EOBP_UserOrdering::None:
			ovr_RoomOptions_SetOrdering(ovrRoomOptionsHandle, ovrUserOrdering_None);
			break;
		case EOBP_UserOrdering::PresenceAlphabetical:
			ovr_RoomOptions_SetOrdering(ovrRoomOptionsHandle, ovrUserOrdering_PresenceAlphabetical);
			break;
		default:
			ovr_RoomOptions_SetOrdering(ovrRoomOptionsHandle, ovrUserOrdering_Unknown);
			break;
		}

		switch (RoomOptions.TimeWindow)
		{
		case EOBP_TimeWindow::Unknown:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_Unknown);
			break;
		case EOBP_TimeWindow::OneHour:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_OneHour);
			break;
		case EOBP_TimeWindow::OneDay:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_OneDay);
			break;
		case EOBP_TimeWindow::OneWeek:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_OneWeek);
			break;
		case EOBP_TimeWindow::ThirtyDays:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_ThirtyDays);
			break;
		case EOBP_TimeWindow::NinetyDays:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_NinetyDays);
			break;
		default:
			ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_Unknown);
			break;
		}

		ovrRequest RequestId = ovr_Room_Join2(OBP_FStringToInt64(RoomID), ovrRoomOptionsHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Room::Join2", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Room_Join2)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully joined room."));
					auto Room = NewObject<UOBP_Room>();
					Room->ovrRoomHandle = ovr_Message_GetRoom(Message);
					OnSuccess.Broadcast(Room);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to join room."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Room::Join2");
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_Room_Join2* UOBP_Room_Join2::Join2(UObject* WorldContextObject, FString RoomID, FOBP_RoomOptionsStruct RoomOptions)
{
	auto Join2 = NewObject<UOBP_Room_Join2>();
	Join2->RoomID = RoomID;
	Join2->RoomOptions = RoomOptions;
	return Join2;
}

//---KickUser---
void UOBP_Room_KickUser::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Room_KickUser(OBP_FStringToInt64(RoomID), OBP_FStringToInt64(UserID), KickDurationSeconds);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
		OBP_SubsystemError("Room::KickUser");
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

//---LaunchInvitableUserFlow---
void UOBP_Room_LaunchInvitableUserFlow::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Room_LaunchInvitableUserFlow(OBP_FStringToInt64(RoomID));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Room::LaunchInvitableUserFlow", Message);
				OnFailure.Broadcast();
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Room_LaunchInvitableUserFlow)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully launched invitable user flow."));
					OnSuccess.Broadcast();
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to launch invitable user flow."));
					OnFailure.Broadcast();
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Room::LaunchInvitableUserFlow");
		OnFailure.Broadcast();
	}
}

UOBP_Room_LaunchInvitableUserFlow* UOBP_Room_LaunchInvitableUserFlow::LaunchInvitableUserFlow(UObject* WorldContextObject, FString RoomID)
{
	auto LaunchInvitableUserFlow = NewObject<UOBP_Room_LaunchInvitableUserFlow>();
	LaunchInvitableUserFlow->RoomID = RoomID;
	return LaunchInvitableUserFlow;
}

//---Leave---
void UOBP_Room_Leave::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Room_Leave(OBP_FStringToInt64(RoomID));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
		OBP_SubsystemError("Room::Leave");
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

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
		OBP_SubsystemError("Room::SetDescription");
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

//---UpdateDataStore---
void UOBP_Room_UpdateDataStore::Activate()
{
	OBP_NotImplementedError("Room::UpdateDataStore");
}

UOBP_Room_UpdateDataStore* UOBP_Room_UpdateDataStore::UpdateDataStore(UObject* WorldContextObject, FString RoomID)
{
	return NewObject<UOBP_Room_UpdateDataStore>();
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

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
		OBP_SubsystemError("Room::UpdateRoomMembershipLockStatus");
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

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
		OBP_SubsystemError("Room::UpdateOwner");
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

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
		OBP_SubsystemError("Room::UpdatePrivateRoomJoinPolicy");
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