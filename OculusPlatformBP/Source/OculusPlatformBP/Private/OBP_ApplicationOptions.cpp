// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_ApplicationOptions.h"

// --------------------
// Initializers
// --------------------

UOBP_ApplicationOptions::UOBP_ApplicationOptions(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_ApplicationOptions.h
// --------------------

UOBP_ApplicationOptions* UOBP_ApplicationOptions::CreateApplicationOptions(UObject* WorldContextObject)
{
	auto ApplicationOptions = NewObject<UOBP_ApplicationOptions>();
	ApplicationOptions->ovrApplicationOptionsHandle = ovr_ApplicationOptions_Create();
	return ApplicationOptions;
}

void UOBP_ApplicationOptions::DestroyApplicationOptions()
{
	ovr_ApplicationOptions_Destroy(ovrApplicationOptionsHandle);
}

void UOBP_ApplicationOptions::SetDeeplinkMessage(FString Value)
{
	ovr_ApplicationOptions_SetDeeplinkMessage(ovrApplicationOptionsHandle, TCHAR_TO_ANSI(*Value));
}