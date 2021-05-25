// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Requests_Voip.h"

// --------------------
// Initializers
// --------------------

UOBP_Voip_SetSystemVoipSuppressed::UOBP_Voip_SetSystemVoipSuppressed(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// ovr_Requests_Voip.h
// --------------------

void UOBP_Voip_SetSystemVoipSuppressed::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Voip_SetSystemVoipSuppressed(Suppressed);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Voip::SetSystemVoipSuppressed", Message);
				OnFailure.Broadcast(EOBP_VoipMuteState::Unknown, EOBP_SystemVoipStatus::Unknown);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Voip_SetSystemVoipSuppressed)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully set system voip suppressed state."));
					
					auto ovrSystemVoipStateHandle = ovr_Message_GetSystemVoipState(Message);
					auto ovrVoipMuteState = ovr_SystemVoipState_GetMicrophoneMuted(ovrSystemVoipStateHandle);
					auto ovrSystemVoipStatus = ovr_SystemVoipState_GetStatus(ovrSystemVoipStateHandle);
					EOBP_VoipMuteState VoipMuteState;
					EOBP_SystemVoipStatus SystemVoipStatus;
					
					switch (ovrVoipMuteState)
					{
					case ovrVoipMuteState_Unknown:
						VoipMuteState = EOBP_VoipMuteState::Unknown;
						break;
					case ovrVoipMuteState_Muted:
						VoipMuteState = EOBP_VoipMuteState::Muted;
						break;
					case ovrVoipMuteState_Unmuted:
						VoipMuteState = EOBP_VoipMuteState::Unmuted;
						break;
					default:
						VoipMuteState = EOBP_VoipMuteState::Unknown;
						break;
					}

					switch (ovrSystemVoipStatus)
					{
					case ovrSystemVoipStatus_Unknown:
						SystemVoipStatus = EOBP_SystemVoipStatus::Unknown;
					case ovrSystemVoipStatus_Unavailable:
						SystemVoipStatus = EOBP_SystemVoipStatus::Unavailable;
					case ovrSystemVoipStatus_Suppressed:
						SystemVoipStatus = EOBP_SystemVoipStatus::Suppressed;
					case ovrSystemVoipStatus_Active:
						SystemVoipStatus = EOBP_SystemVoipStatus::Active;
					default:
						SystemVoipStatus = EOBP_SystemVoipStatus::Unknown;
						break;
					}
					
					OnSuccess.Broadcast(VoipMuteState, SystemVoipStatus);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to set system voip suppressed state."));
					OnFailure.Broadcast(EOBP_VoipMuteState::Unknown, EOBP_SystemVoipStatus::Unknown);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Voip::SetSystemVoipSuppressed");
		OnFailure.Broadcast(EOBP_VoipMuteState::Unknown, EOBP_SystemVoipStatus::Unknown);
	}
}

UOBP_Voip_SetSystemVoipSuppressed* UOBP_Voip_SetSystemVoipSuppressed::SetSystemVoipSuppressed(UObject* WorldContextObject, bool Suppressed)
{
	auto SetSystemVoipSuppressed = NewObject<UOBP_Voip_SetSystemVoipSuppressed>();
	SetSystemVoipSuppressed->Suppressed = Suppressed;
	return SetSystemVoipSuppressed;
}