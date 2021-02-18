// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_Functions_Voip.generated.h"

/* Most Oculus Platform SDK Voip functions have not been implemented here. They're already integrated into the voice interface, so just use that. 
	Check out Mordentral's AdvancedSessions plugin to make use of the AdvancedVoiceLibray blueprints. */

// --------------------
// OVR_Function_Voip.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Functions_Voip : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	/* Returns SystemVoip microphone's mute state. */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Voip|Voip", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static EOBP_VoipMuteState GetSystemVoipMicrophoneMuted(UObject* WorldContextObject);

	/* Returns SystemVoip status. */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Voip|Voip", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static EOBP_SystemVoipStatus GetSystemVoipStatus(UObject* WorldContextObject);

	/* This function is used to enable or disable the local microphone. When muted, the microphone will not transmit any audio. 
	Voip connections are unaffected by this state. New connections can be established or closed whether the microphone is muted or not. 
	This can be used to implement push- to-talk, or a local mute button. The default state is unmuted.
	This function can be safely called from any thread. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Voip|Voip", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static void SetMicrophoneMuted(UObject* WorldContextObject, EOBP_VoipMuteState MuteState);


};