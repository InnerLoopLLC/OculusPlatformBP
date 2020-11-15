// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_Requests_Voip.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FVoip_SetSystemVoipSuppressed, EOBP_VoipMuteState, VoipMuteState, EOBP_SystemVoipStatus, SystemVoipStatus);

// --------------------
// ovr_Requests_Voip.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Voip_SetSystemVoipSuppressed : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	bool Suppressed;

	UPROPERTY(BlueprintAssignable)
		FVoip_SetSystemVoipSuppressed OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FVoip_SetSystemVoipSuppressed OnFailure;

	/* Sets whether SystemVoip (PartyVoip) should be suppressed so that this app's Voip can use the mic and play incoming Voip audio. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Voip|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Voip_SetSystemVoipSuppressed* SetSystemVoipSuppressed(UObject* WorldContextObject, bool Suppressed);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};