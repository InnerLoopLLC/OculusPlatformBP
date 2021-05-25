// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Requests_Party.h"

// --------------------
// Initializers
// --------------------

UOBP_Party_GetCurrent::UOBP_Party_GetCurrent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// ovr_Requests_Party.h
// --------------------

//---GetCurrentParty---
void UOBP_Party_GetCurrent::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Party_GetCurrent();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Party::GetCurrentParty", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Party_GetCurrent)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got current party."));
					auto CurrentParty = NewObject<UOBP_Party>();
					CurrentParty->ovrPartyHandle = ovr_Message_GetParty(Message);
					OnSuccess.Broadcast(CurrentParty);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get current party."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Party::GetCurrentParty");
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_Party_GetCurrent* UOBP_Party_GetCurrent::GetCurrentParty(UObject* WorldContextObject)
{
	return NewObject<UOBP_Party_GetCurrent>();
}