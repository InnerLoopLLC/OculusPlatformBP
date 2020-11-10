// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Requests_Room.h"

// --------------------
// Initializers
// --------------------

UOBP_Room_Get::UOBP_Room_Get(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// ovr_Requests_Room.h
// --------------------

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