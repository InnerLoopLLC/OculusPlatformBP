// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBPRichPresence.h"

UOBPRichPresence::UOBPRichPresence(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// Rich Presence Functions
// --------------------

UOBPRichPresence* UOBPRichPresence::CreateRichPresenceOptions(UObject* WorldContextObject)
{
	return NewObject<UOBPRichPresence>();
}

void UOBPRichPresence::DestroyRichPresenceOptions()
{
	ovr_RichPresenceOptions_Destroy(OvrRichPresenceOptions);
}

void UOBPRichPresence::SetApiName(const FString RichPresenceApiName)
{
	ovr_RichPresenceOptions_SetApiName(OvrRichPresenceOptions, TCHAR_TO_ANSI(*RichPresenceApiName));
}

void UOBPRichPresence::SetArgsString(const FString RichPresenceApiKey, const FString RichPresenceApiValue)
{
	ovr_RichPresenceOptions_SetArgsString(OvrRichPresenceOptions, TCHAR_TO_ANSI(*RichPresenceApiKey), TCHAR_TO_ANSI(*RichPresenceApiValue));
}

void UOBPRichPresence::ClearArgs()
{
	ovr_RichPresenceOptions_ClearArgs(OvrRichPresenceOptions);
}

void UOBPRichPresence::SetCurrentCapacity(const int32 RichPresenceCurrentCapacity)
{
	ovr_RichPresenceOptions_SetCurrentCapacity(OvrRichPresenceOptions, RichPresenceCurrentCapacity);
}

void UOBPRichPresence::SetDeeplinkMessageOverride(const FString RichPresenceDeeplinkMessage)
{
	ovr_RichPresenceOptions_SetDeeplinkMessageOverride(OvrRichPresenceOptions, TCHAR_TO_ANSI(*RichPresenceDeeplinkMessage));
}

void UOBPRichPresence::SetEndTime(const int64 RichPresenceEndTime)
{
	ovr_RichPresenceOptions_SetEndTime(OvrRichPresenceOptions, RichPresenceEndTime);
}

void UOBPRichPresence::SetExtraContext(EOBPRichPresenceExtraContext RichPresenceExtraContext)
{
	switch (RichPresenceExtraContext)
	{
	case EOBPRichPresenceExtraContext::Unknown:
		ovr_RichPresenceOptions_SetExtraContext(OvrRichPresenceOptions, ovrRichPresenceExtraContext_Unknown);
		break;
	case EOBPRichPresenceExtraContext::None:
		ovr_RichPresenceOptions_SetExtraContext(OvrRichPresenceOptions, ovrRichPresenceExtraContext_None);
		break;
	case EOBPRichPresenceExtraContext::CurrentCapacity:
		ovr_RichPresenceOptions_SetExtraContext(OvrRichPresenceOptions, ovrRichPresenceExtraContext_CurrentCapacity);
		break;
	case EOBPRichPresenceExtraContext::StartedAgo:
		ovr_RichPresenceOptions_SetExtraContext(OvrRichPresenceOptions, ovrRichPresenceExtraContext_StartedAgo);
		break;
	case EOBPRichPresenceExtraContext::EndingIn:
		ovr_RichPresenceOptions_SetExtraContext(OvrRichPresenceOptions, ovrRichPresenceExtraContext_EndingIn);
		break;
	case EOBPRichPresenceExtraContext::LookingForMatch:
		ovr_RichPresenceOptions_SetExtraContext(OvrRichPresenceOptions, ovrRichPresenceExtraContext_LookingForAMatch);
		break;
	}
}

void UOBPRichPresence::SetIsIdle(const bool RichPresenceIsIdle)
{
	ovr_RichPresenceOptions_SetIsIdle(OvrRichPresenceOptions, RichPresenceIsIdle);
}

void UOBPRichPresence::SetIsJoinable(const bool RichPresenceIsJoinable)
{
	ovr_RichPresenceOptions_SetIsJoinable(OvrRichPresenceOptions, RichPresenceIsJoinable);
}

void UOBPRichPresence::SetJoinableId(const FString RichPresenceJoinableId)
{
	ovr_RichPresenceOptions_SetJoinableId(OvrRichPresenceOptions, TCHAR_TO_ANSI(*RichPresenceJoinableId));
}

void UOBPRichPresence::SetMaxCapacity(const int RichPresenceMaxCapacity)
{
	ovr_RichPresenceOptions_SetMaxCapacity(OvrRichPresenceOptions, RichPresenceMaxCapacity);
}

void UOBPRichPresence::SetStartTime(const int64 RichPresenceStartTime)
{
	ovr_RichPresenceOptions_SetStartTime(OvrRichPresenceOptions, RichPresenceStartTime);
}

/*/ --------------------
// Rich Presence Extra Context
// --------------------

FString UOBPRichPresence::ExtraContext_ToString(EOBPRichPresenceExtraContext RichPresenceExtraContext)
{
	switch (RichPresenceExtraContext)
	{
	case EOBPRichPresenceExtraContext::Unknown:
		return ovrRichPresenceExtraContext_ToString(ovrRichPresenceExtraContext_Unknown);
		break;
	case EOBPRichPresenceExtraContext::None:
		return ovrRichPresenceExtraContext_ToString(ovrRichPresenceExtraContext_None);
		break;
	case EOBPRichPresenceExtraContext::CurrentCapacity:
		return ovrRichPresenceExtraContext_ToString(ovrRichPresenceExtraContext_CurrentCapacity);
		break;
	case EOBPRichPresenceExtraContext::StartedAgo:
		return ovrRichPresenceExtraContext_ToString(ovrRichPresenceExtraContext_StartedAgo);
		break;
	case EOBPRichPresenceExtraContext::EndingIn:
		return ovrRichPresenceExtraContext_ToString(ovrRichPresenceExtraContext_EndingIn);
		break;
	case EOBPRichPresenceExtraContext::LookingForMatch:
		return ovrRichPresenceExtraContext_ToString(ovrRichPresenceExtraContext_LookingForAMatch);
		break;
	default:
		return ovrRichPresenceExtraContext_ToString(ovrRichPresenceExtraContext_Unknown);
		break;
	}
}

EOBPRichPresenceExtraContext UOBPRichPresence::ExtraContext_FromString(FString RichPresenceExtraContextString)
{
	ovrRichPresenceExtraContext RichPresenceExtraContextObject = ovrRichPresenceExtraContext_FromString(TCHAR_TO_ANSI(*RichPresenceExtraContextString));
	
	switch (RichPresenceExtraContextObject)
	{
	case 0:
		return EOBPRichPresenceExtraContext::Unknown;
		break;
	case 1:
		return EOBPRichPresenceExtraContext::None;
		break;
	case 2:
		return EOBPRichPresenceExtraContext::CurrentCapacity;
		break;
	case 3:
		return EOBPRichPresenceExtraContext::StartedAgo;
		break;
	case 4:
		return EOBPRichPresenceExtraContext::EndingIn;
		break;
	case 5:
		return EOBPRichPresenceExtraContext::LookingForMatch;
		break;
	default:
		return EOBPRichPresenceExtraContext::Unknown;
		break;
	}
}
*/

// --------------------
// OVR_RichPresenceRequests.h
// --------------------

void UOBPRichPresence::ClearRichPresence()
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

// requires OculusPlatfromSDK v12 (1.44) or later
void UOBPRichPresence::GetDestinations()
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
	OBPPlatformVersionError("GetDestinations", "v12");
#endif
}

// requires OculusPlatfromSDK v12 (1.44) or later
void UOBPRichPresence::GetNextDestinationArrayPage()
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
	OBPPlatformVersionError("GetNextDestinationArrayPage", "v12");
#endif
}

void UOBPRichPresence::SetRichPresence()
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
