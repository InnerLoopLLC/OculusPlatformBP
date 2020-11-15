// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Requests_Notification.h"

// --------------------
// Initializers
// --------------------

UOBP_Notification_GetNextRoomInviteNotificationArrayPage::UOBP_Notification_GetNextRoomInviteNotificationArrayPage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Notification_GetRoomInvites::UOBP_Notification_GetRoomInvites(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Notification_MarkAsRead::UOBP_Notification_MarkAsRead(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// ovr_Requests_Room.h
// --------------------

//---GetNextRoomInviteNotificationArrayPage---
void UOBP_Notification_GetNextRoomInviteNotificationArrayPage::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Notification_GetNextRoomInviteNotificationArrayPage(RoomInviteNotificationArray->ovrRoomInviteNotificationArrayHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Notification::GetNextRoomInviteNotificationArrayPage", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Notification_GetNextRoomInviteNotificationArrayPage)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got next RoomInviteNotificationArray page."));
					auto NextRoomInviteNotificationArrayPage = NewObject<UOBP_RoomInviteNotificationArray>();
					NextRoomInviteNotificationArrayPage->ovrRoomInviteNotificationArrayHandle = ovr_Message_GetRoomInviteNotificationArray(Message);
					OnSuccess.Broadcast(NextRoomInviteNotificationArrayPage);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get next RoomInviteNotificationArray page."));
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

UOBP_Notification_GetNextRoomInviteNotificationArrayPage* UOBP_Notification_GetNextRoomInviteNotificationArrayPage::GetNextRoomInviteNotificationArrayPage(UObject* WorldContextObject, UOBP_RoomInviteNotificationArray* RoomInviteNotificationArray)
{
	auto GetNextRoomInviteNotifcationArrayPage = NewObject<UOBP_Notification_GetNextRoomInviteNotificationArrayPage>();
	GetNextRoomInviteNotifcationArrayPage->RoomInviteNotificationArray = RoomInviteNotificationArray;
	return GetNextRoomInviteNotifcationArrayPage;
}

//---GetRoomInvites---
void UOBP_Notification_GetRoomInvites::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Notification_GetRoomInvites();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Notification::GetRoomInvites", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Notification_GetRoomInvites)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got room invites."));
					auto RoomInvites = NewObject<UOBP_RoomInviteNotificationArray>();
					RoomInvites->ovrRoomInviteNotificationArrayHandle = ovr_Message_GetRoomInviteNotificationArray(Message);
					OnSuccess.Broadcast(RoomInvites);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get room invites."));
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

UOBP_Notification_GetRoomInvites* UOBP_Notification_GetRoomInvites::GetRoomInvites(UObject* WorldContextObject)
{
	return NewObject<UOBP_Notification_GetRoomInvites>();
}

//---MarkAsRead---
void UOBP_Notification_MarkAsRead::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Notification_MarkAsRead(OBP_FStringToInt64(NotificationID));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Notification::MarkAsRead", Message);
				OnFailure.Broadcast();
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Notification_MarkAsRead)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully marked notification as read."));
					OnSuccess.Broadcast();
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to mark notification as read."));
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

UOBP_Notification_MarkAsRead* UOBP_Notification_MarkAsRead::MarkAsRead(UObject* WorldContextObject, FString NotificationID)
{
	auto MarkAsRead = NewObject<UOBP_Notification_MarkAsRead>();
	MarkAsRead->NotificationID = NotificationID;
	return MarkAsRead;
}