// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Functions_Voip.h"

// --------------------
// Initializers
// --------------------

UOBP_Functions_Voip::UOBP_Functions_Voip(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_Functions_Voip.h
// --------------------

EOBP_VoipMuteState UOBP_Functions_Voip::GetSystemVoipMicrophoneMuted(UObject* WorldContextObject)
{
	auto ovrVoipMuteStateHandle = ovr_Voip_GetSystemVoipMicrophoneMuted();
	switch (ovrVoipMuteStateHandle)
	{
	case ovrVoipMuteState_Unknown:
		return EOBP_VoipMuteState::Unknown;
	case ovrVoipMuteState_Muted:
		return EOBP_VoipMuteState::Muted;
	case ovrVoipMuteState_Unmuted:
		return EOBP_VoipMuteState::Unmuted;
	default:
		return EOBP_VoipMuteState::Unknown;
	}
}

EOBP_SystemVoipStatus UOBP_Functions_Voip::GetSystemVoipStatus(UObject* WorldContextObject)
{
	auto ovrSystemVoipStatusHandle = ovr_Voip_GetSystemVoipStatus();
	switch (ovrSystemVoipStatusHandle)
	{
	case ovrSystemVoipStatus_Unknown:
		return EOBP_SystemVoipStatus::Unknown;
	case ovrSystemVoipStatus_Unavailable:
		return EOBP_SystemVoipStatus::Unavailable;
	case ovrSystemVoipStatus_Suppressed:
		return EOBP_SystemVoipStatus::Suppressed;
	case ovrSystemVoipStatus_Active:
		return EOBP_SystemVoipStatus::Active;
	default:
		return EOBP_SystemVoipStatus::Unknown;
	}
}

void UOBP_Functions_Voip::SetMicrophoneMuted(UObject* WorldContextObject, EOBP_VoipMuteState MuteState)
{
	switch (MuteState)
	{
	case EOBP_VoipMuteState::Unknown:
		ovr_Voip_SetMicrophoneMuted(ovrVoipMuteState_Unknown);
		break;
	case EOBP_VoipMuteState::Muted:
		ovr_Voip_SetMicrophoneMuted(ovrVoipMuteState_Muted);
		break;
	case EOBP_VoipMuteState::Unmuted:
		ovr_Voip_SetMicrophoneMuted(ovrVoipMuteState_Unmuted);
		break;
	default:
		ovr_Voip_SetMicrophoneMuted(ovrVoipMuteState_Unmuted);
		break;
	}
}
