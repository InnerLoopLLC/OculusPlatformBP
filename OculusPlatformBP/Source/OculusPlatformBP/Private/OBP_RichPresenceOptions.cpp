// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_RichPresenceOptions.h"

// --------------------
// Initializers
// --------------------

UOBP_RichPresenceOptions::UOBP_RichPresenceOptions(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_RichPresenceOptions.h
// --------------------

UOBP_RichPresenceOptions* UOBP_RichPresenceOptions::CreateRichPresenceOptions(UObject* WorldContextObject)
{
#if PLATFORM_MINOR_VERSION >= 39
	auto RichPresenceOptions = NewObject<UOBP_RichPresenceOptions>();
	RichPresenceOptions->ovrRichPresenceOptionsHandle = ovr_RichPresenceOptions_Create();
	return RichPresenceOptions;
#else
	OBP_PlatformVersionError("RichPresenceOptions::CreateRichPresenceOptions", "1.39");
	return nullptr;
#endif
}

void UOBP_RichPresenceOptions::DestroyRichPresenceOptions()
{
#if PLATFORM_MINOR_VERSION >= 39
	ovr_RichPresenceOptions_Destroy(ovrRichPresenceOptionsHandle);
#else
	OBP_PlatformVersionError("RichPresenceOptions::DestroyRichPresenceOptions", "1.39");
#endif
}

void UOBP_RichPresenceOptions::SetApiName(const FString RichPresenceApiName)
{
#if PLATFORM_MINOR_VERSION >= 39
	ovr_RichPresenceOptions_SetApiName(ovrRichPresenceOptionsHandle, TCHAR_TO_ANSI(*RichPresenceApiName));
#else
	OBP_PlatformVersionError("RichPresenceOptions::SetApiName", "1.39");
#endif
}

void UOBP_RichPresenceOptions::SetArgsString(const FString RichPresenceApiKey, const FString RichPresenceApiValue)
{
#if PLATFORM_MINOR_VERSION >= 39
	ovr_RichPresenceOptions_SetArgsString(ovrRichPresenceOptionsHandle, TCHAR_TO_ANSI(*RichPresenceApiKey), TCHAR_TO_ANSI(*RichPresenceApiValue));
#else
	OBP_PlatformVersionError("RichPresenceOptions::SetArgsString", "1.39");
#endif
}

void UOBP_RichPresenceOptions::ClearArgs()
{
#if PLATFORM_MINOR_VERSION >= 39
	ovr_RichPresenceOptions_ClearArgs(ovrRichPresenceOptionsHandle);
#else
	OBP_PlatformVersionError("RichPresenceOptions::ClearArgs", "1.39");
#endif
}

void UOBP_RichPresenceOptions::SetCurrentCapacity(const int32 RichPresenceCurrentCapacity)
{
#if PLATFORM_MINOR_VERSION >= 40
	ovr_RichPresenceOptions_SetCurrentCapacity(ovrRichPresenceOptionsHandle, RichPresenceCurrentCapacity);
#else
	OBP_PlatformVersionError("RichPresenceOptions::SetCurrentCapacity", "1.40");
#endif
}

void UOBP_RichPresenceOptions::SetDeeplinkMessageOverride(const FString RichPresenceDeeplinkMessage)
{
#if PLATFORM_MINOR_VERSION >= 40
	ovr_RichPresenceOptions_SetDeeplinkMessageOverride(ovrRichPresenceOptionsHandle, TCHAR_TO_ANSI(*RichPresenceDeeplinkMessage));
#else
	OBP_PlatformVersionError("RichPresenceOptions::SetDeeplinkMessageOverride", "1.40");
#endif
}

void UOBP_RichPresenceOptions::SetEndTime(const int32 RichPresenceEndTime)
{
#if PLATFORM_MINOR_VERSION >= 39
	ovr_RichPresenceOptions_SetEndTime(ovrRichPresenceOptionsHandle, RichPresenceEndTime);
#else
	OBP_PlatformVersionError("RichPresenceOptions::SetEndTime", "1.39");
#endif
}

void UOBP_RichPresenceOptions::SetExtraContext(EOBP_RichPresenceExtraContext RichPresenceExtraContext)
{
#if PLATFORM_MINOR_VERSION >= 40
	switch (RichPresenceExtraContext)
	{
	case EOBP_RichPresenceExtraContext::Unknown:
		ovr_RichPresenceOptions_SetExtraContext(ovrRichPresenceOptionsHandle, ovrRichPresenceExtraContext_Unknown);
		break;
	case EOBP_RichPresenceExtraContext::None:
		ovr_RichPresenceOptions_SetExtraContext(ovrRichPresenceOptionsHandle, ovrRichPresenceExtraContext_None);
		break;
	case EOBP_RichPresenceExtraContext::CurrentCapacity:
		ovr_RichPresenceOptions_SetExtraContext(ovrRichPresenceOptionsHandle, ovrRichPresenceExtraContext_CurrentCapacity);
		break;
	case EOBP_RichPresenceExtraContext::StartedAgo:
		ovr_RichPresenceOptions_SetExtraContext(ovrRichPresenceOptionsHandle, ovrRichPresenceExtraContext_StartedAgo);
		break;
	case EOBP_RichPresenceExtraContext::EndingIn:
		ovr_RichPresenceOptions_SetExtraContext(ovrRichPresenceOptionsHandle, ovrRichPresenceExtraContext_EndingIn);
		break;
	case EOBP_RichPresenceExtraContext::LookingForMatch:
		ovr_RichPresenceOptions_SetExtraContext(ovrRichPresenceOptionsHandle, ovrRichPresenceExtraContext_LookingForAMatch);
		break;
	}
#else
	OBP_PlatformVersionError("RichPresenceOptions::SetExtraContext", "1.40");
#endif
}

void UOBP_RichPresenceOptions::SetInstanceId(const FString Value)
{
#if PLATFORM_MINOR_VERSION >= 55
	ovr_RichPresenceOptions_SetInstanceId(ovrRichPresenceOptionsHandle, TCHAR_TO_ANSI(*Value));
#else
	OBP_PlatformVersionError("RichPresenceOptions::SetInstanceId", "v23");
#endif
}

void UOBP_RichPresenceOptions::SetIsIdle(const bool RichPresenceIsIdle)
{
#if PLATFORM_MINOR_VERSION >= 39
	ovr_RichPresenceOptions_SetIsIdle(ovrRichPresenceOptionsHandle, RichPresenceIsIdle);
#else
	OBP_PlatformVersionError("RichPresenceOptions::SetIsIdle", "1.39");
#endif
}

void UOBP_RichPresenceOptions::SetIsJoinable(const bool RichPresenceIsJoinable)
{
#if PLATFORM_MINOR_VERSION >= 39
	ovr_RichPresenceOptions_SetIsJoinable(ovrRichPresenceOptionsHandle, RichPresenceIsJoinable);
#else
	OBP_PlatformVersionError("RichPresenceOptions::SetIsJoinable", "1.39");
#endif
}

void UOBP_RichPresenceOptions::SetJoinableId(const FString RichPresenceJoinableId)
{
#if PLATFORM_MINOR_VERSION >= 39
	ovr_RichPresenceOptions_SetJoinableId(ovrRichPresenceOptionsHandle, TCHAR_TO_ANSI(*RichPresenceJoinableId));
#else
	OBP_PlatformVersionError("RichPresenceOptions::SetJoinableId", "1.39");
#endif
}

void UOBP_RichPresenceOptions::SetMaxCapacity(const int32 RichPresenceMaxCapacity)
{
#if PLATFORM_MINOR_VERSION >= 40
	ovr_RichPresenceOptions_SetMaxCapacity(ovrRichPresenceOptionsHandle, RichPresenceMaxCapacity);
#else
	OBP_PlatformVersionError("RichPresenceOptions::SetMaxCapacity", "1.40");
#endif
}

void UOBP_RichPresenceOptions::SetStartTime(const int32 RichPresenceStartTime)
{
#if PLATFORM_MINOR_VERSION >= 40
	ovr_RichPresenceOptions_SetStartTime(ovrRichPresenceOptionsHandle, RichPresenceStartTime);
#else
	OBP_PlatformVersionError("RichPresenceOptions::SetStartTime", "1.40");
#endif
}