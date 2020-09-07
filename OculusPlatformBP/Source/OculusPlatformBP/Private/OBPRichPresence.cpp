// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBPRichPresence.h"

UOBP_RichPresence::UOBP_RichPresence(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// Rich Presence Functions
// --------------------

UOBP_RichPresence* UOBP_RichPresence::CreateRichPresenceOptions(UObject* WorldContextObject)
{
	return NewObject<UOBP_RichPresence>();
}

void UOBP_RichPresence::DestroyRichPresenceOptions()
{
	ovr_RichPresenceOptions_Destroy(OvrRichPresenceOptions);
}

void UOBP_RichPresence::SetApiName(const FString RichPresenceApiName)
{
	ovr_RichPresenceOptions_SetApiName(OvrRichPresenceOptions, TCHAR_TO_ANSI(*RichPresenceApiName));
}

void UOBP_RichPresence::SetArgsString(const FString RichPresenceApiKey, const FString RichPresenceApiValue)
{
	ovr_RichPresenceOptions_SetArgsString(OvrRichPresenceOptions, TCHAR_TO_ANSI(*RichPresenceApiKey), TCHAR_TO_ANSI(*RichPresenceApiValue));
}

void UOBP_RichPresence::ClearArgs()
{
	ovr_RichPresenceOptions_ClearArgs(OvrRichPresenceOptions);
}

void UOBP_RichPresence::SetCurrentCapacity(const int32 RichPresenceCurrentCapacity)
{
	ovr_RichPresenceOptions_SetCurrentCapacity(OvrRichPresenceOptions, RichPresenceCurrentCapacity);
}

void UOBP_RichPresence::SetDeeplinkMessageOverride(const FString RichPresenceDeeplinkMessage)
{
	ovr_RichPresenceOptions_SetDeeplinkMessageOverride(OvrRichPresenceOptions, TCHAR_TO_ANSI(*RichPresenceDeeplinkMessage));
}

void UOBP_RichPresence::SetEndTime(const int64 RichPresenceEndTime)
{
	ovr_RichPresenceOptions_SetEndTime(OvrRichPresenceOptions, RichPresenceEndTime);
}

void UOBP_RichPresence::SetExtraContext(EOBP_RichPresenceExtraContext RichPresenceExtraContext)
{
	switch (RichPresenceExtraContext)
	{
	case EOBP_RichPresenceExtraContext::Unknown:
		ovr_RichPresenceOptions_SetExtraContext(OvrRichPresenceOptions, ovrRichPresenceExtraContext_Unknown);
		break;
	case EOBP_RichPresenceExtraContext::None:
		ovr_RichPresenceOptions_SetExtraContext(OvrRichPresenceOptions, ovrRichPresenceExtraContext_None);
		break;
	case EOBP_RichPresenceExtraContext::CurrentCapacity:
		ovr_RichPresenceOptions_SetExtraContext(OvrRichPresenceOptions, ovrRichPresenceExtraContext_CurrentCapacity);
		break;
	case EOBP_RichPresenceExtraContext::StartedAgo:
		ovr_RichPresenceOptions_SetExtraContext(OvrRichPresenceOptions, ovrRichPresenceExtraContext_StartedAgo);
		break;
	case EOBP_RichPresenceExtraContext::EndingIn:
		ovr_RichPresenceOptions_SetExtraContext(OvrRichPresenceOptions, ovrRichPresenceExtraContext_EndingIn);
		break;
	case EOBP_RichPresenceExtraContext::LookingForMatch:
		ovr_RichPresenceOptions_SetExtraContext(OvrRichPresenceOptions, ovrRichPresenceExtraContext_LookingForAMatch);
		break;
	}
}

void UOBP_RichPresence::SetIsIdle(const bool RichPresenceIsIdle)
{
	ovr_RichPresenceOptions_SetIsIdle(OvrRichPresenceOptions, RichPresenceIsIdle);
}

void UOBP_RichPresence::SetIsJoinable(const bool RichPresenceIsJoinable)
{
	ovr_RichPresenceOptions_SetIsJoinable(OvrRichPresenceOptions, RichPresenceIsJoinable);
}

void UOBP_RichPresence::SetJoinableId(const FString RichPresenceJoinableId)
{
	ovr_RichPresenceOptions_SetJoinableId(OvrRichPresenceOptions, TCHAR_TO_ANSI(*RichPresenceJoinableId));
}

void UOBP_RichPresence::SetMaxCapacity(const int RichPresenceMaxCapacity)
{
	ovr_RichPresenceOptions_SetMaxCapacity(OvrRichPresenceOptions, RichPresenceMaxCapacity);
}

void UOBP_RichPresence::SetStartTime(const int64 RichPresenceStartTime)
{
	ovr_RichPresenceOptions_SetStartTime(OvrRichPresenceOptions, RichPresenceStartTime);
}

/*/ --------------------
// Rich Presence Extra Context
// --------------------

FString UOBP_RichPresence::ExtraContext_ToString(EOBP_RichPresenceExtraContext RichPresenceExtraContext)
{
	switch (RichPresenceExtraContext)
	{
	case EOBP_RichPresenceExtraContext::Unknown:
		return ovrRichPresenceExtraContext_ToString(ovrRichPresenceExtraContext_Unknown);
		break;
	case EOBP_RichPresenceExtraContext::None:
		return ovrRichPresenceExtraContext_ToString(ovrRichPresenceExtraContext_None);
		break;
	case EOBP_RichPresenceExtraContext::CurrentCapacity:
		return ovrRichPresenceExtraContext_ToString(ovrRichPresenceExtraContext_CurrentCapacity);
		break;
	case EOBP_RichPresenceExtraContext::StartedAgo:
		return ovrRichPresenceExtraContext_ToString(ovrRichPresenceExtraContext_StartedAgo);
		break;
	case EOBP_RichPresenceExtraContext::EndingIn:
		return ovrRichPresenceExtraContext_ToString(ovrRichPresenceExtraContext_EndingIn);
		break;
	case EOBP_RichPresenceExtraContext::LookingForMatch:
		return ovrRichPresenceExtraContext_ToString(ovrRichPresenceExtraContext_LookingForAMatch);
		break;
	default:
		return ovrRichPresenceExtraContext_ToString(ovrRichPresenceExtraContext_Unknown);
		break;
	}
}

EOBP_RichPresenceExtraContext UOBP_RichPresence::ExtraContext_FromString(FString RichPresenceExtraContextString)
{
	ovrRichPresenceExtraContext RichPresenceExtraContextObject = ovrRichPresenceExtraContext_FromString(TCHAR_TO_ANSI(*RichPresenceExtraContextString));
	
	switch (RichPresenceExtraContextObject)
	{
	case 0:
		return EOBP_RichPresenceExtraContext::Unknown;
		break;
	case 1:
		return EOBP_RichPresenceExtraContext::None;
		break;
	case 2:
		return EOBP_RichPresenceExtraContext::CurrentCapacity;
		break;
	case 3:
		return EOBP_RichPresenceExtraContext::StartedAgo;
		break;
	case 4:
		return EOBP_RichPresenceExtraContext::EndingIn;
		break;
	case 5:
		return EOBP_RichPresenceExtraContext::LookingForMatch;
		break;
	default:
		return EOBP_RichPresenceExtraContext::Unknown;
		break;
	}
}
*/

// --------------------
// OVR_RichPresenceRequests.h
// --------------------

void UOBP_RichPresence::ClearRichPresence()
{
	ovrRequest RequestId = ovr_RichPresence_Clear();

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError) {
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Error clearing Rich Presence"));
		}
		else {
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully cleared Rich Presence"));
		}
	}));
}

// Requires OculusPlatfromSDK v12 (1.44) or later
void UOBP_RichPresence::GetDestinations()
{
#if PLATFORM_MINOR_VERSION >= 44
	ovrRequest RequestId = ovr_RichPresence_GetDestinations();

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError) {
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Error getting Destinations"));
		}
		else {
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got Destinations"));
		}
	}));
#else
	OBP_PlatformVersionError("GetDestinations", "v12");
#endif
}

// Requires OculusPlatfromSDK v12 (1.44) or later
void UOBP_RichPresence::GetNextDestinationArrayPage()
{
#if PLATFORM_MINOR_VERSION >= 44
	ovrRequest RequestId = ovr_RichPresence_GetNextDestinationArrayPage(OvrRichPresenceStruct);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError) {
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Error getting Next Destination Array Page"));
		}
		else {
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got Next Destination Array Page"));
		}
	}));
#else
	OBP_PlatformVersionError("GetNextDestinationArrayPage", "v12");
#endif
}

void UOBP_RichPresence::SetRichPresence()
{
	ovrRequest RequestId = ovr_RichPresence_Set(OvrRichPresenceOptions);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError) {
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Error setting Rich Presence")); //, *FString(ovr_Message_GetString(Message))
		}
		else {
			UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully set Rich Presence"));
		}
	}));
}
