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

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Notification::GetNextRoomInviteNotificationArrayPage", Message);
				OnFailure.Broadcast(TArray<UOBP_RoomInviteNotification*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Notification_GetNextRoomInviteNotificationArrayPage)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got next RoomInviteNotificationArray page."));
					auto NextRoomInviteNotificationArrayPage = NewObject<UOBP_RoomInviteNotificationArray>();
					NextRoomInviteNotificationArrayPage->ovrRoomInviteNotificationArrayHandle = ovr_Message_GetRoomInviteNotificationArray(Message);

					TArray<UOBP_RoomInviteNotification*> RoomInvites;

					for (size_t i = 0; i < ovr_RoomInviteNotificationArray_GetSize(NextRoomInviteNotificationArrayPage->ovrRoomInviteNotificationArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_RoomInviteNotification>();
						ThisElement->ovrRoomInviteNotificationHandle = ovr_RoomInviteNotificationArray_GetElement(NextRoomInviteNotificationArrayPage->ovrRoomInviteNotificationArrayHandle, i);
						RoomInvites.Add(ThisElement);
					}

					OnSuccess.Broadcast(RoomInvites, NextRoomInviteNotificationArrayPage);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get next RoomInviteNotificationArray page."));
					OnFailure.Broadcast(TArray<UOBP_RoomInviteNotification*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Notification::GetNextRoomInviteNotificationArrayPage");
		OnFailure.Broadcast(TArray<UOBP_RoomInviteNotification*>(), nullptr);
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

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Notification::GetRoomInvites", Message);
				OnFailure.Broadcast(TArray<UOBP_RoomInviteNotification*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Notification_GetRoomInvites)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got room invites."));
					auto RoomInviteNotificationArray = NewObject<UOBP_RoomInviteNotificationArray>();
					RoomInviteNotificationArray->ovrRoomInviteNotificationArrayHandle = ovr_Message_GetRoomInviteNotificationArray(Message);

					TArray<UOBP_RoomInviteNotification*> RoomInvites;

					for (size_t i = 0; i < ovr_RoomInviteNotificationArray_GetSize(RoomInviteNotificationArray->ovrRoomInviteNotificationArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_RoomInviteNotification>();
						ThisElement->ovrRoomInviteNotificationHandle = ovr_RoomInviteNotificationArray_GetElement(RoomInviteNotificationArray->ovrRoomInviteNotificationArrayHandle, i);
						RoomInvites.Add(ThisElement);
					}

					OnSuccess.Broadcast(RoomInvites, RoomInviteNotificationArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get room invites."));
					OnFailure.Broadcast(TArray<UOBP_RoomInviteNotification*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Notification::GetRoomInvites");
		OnFailure.Broadcast(TArray<UOBP_RoomInviteNotification*>(), nullptr);
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

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
		OBP_SubsystemError("Notification::MarkAsRead");
		OnFailure.Broadcast();
	}
}

UOBP_Notification_MarkAsRead* UOBP_Notification_MarkAsRead::MarkAsRead(UObject* WorldContextObject, FString NotificationID)
{
	auto MarkAsRead = NewObject<UOBP_Notification_MarkAsRead>();
	MarkAsRead->NotificationID = NotificationID;
	return MarkAsRead;
}