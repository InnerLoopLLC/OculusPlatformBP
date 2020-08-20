// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBPRichPresence.h"

UOBPRichPresence::UOBPRichPresence(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// Rich Presense Functions
// --------------------

UOBPRichPresence* UOBPRichPresence::CreateRichPresenceOptions(UObject* WorldContextObject)
{
	return NewObject<UOBPRichPresence>();
}

void UOBPRichPresence::DestroyRichPresenseOptions()
{
	ovr_RichPresenceOptions_Destroy(OvrRichPresenceOptions);
}

void UOBPRichPresence::SetApiName(const FString RichPresenseApiName)
{
	ovr_RichPresenceOptions_SetApiName(OvrRichPresenceOptions, TCHAR_TO_ANSI(*RichPresenseApiName));
}

void UOBPRichPresence::SetArgsString(const FString RichPresenseApiKey, const FString RichPresenseApiValue)
{
	ovr_RichPresenceOptions_SetArgsString(OvrRichPresenceOptions, TCHAR_TO_ANSI(*RichPresenseApiKey), TCHAR_TO_ANSI(*RichPresenseApiValue));
}

void UOBPRichPresence::ClearArgs()
{
	ovr_RichPresenceOptions_ClearArgs(OvrRichPresenceOptions);
}

void UOBPRichPresence::SetCurrentCapacity(const int32 RichPresenseCurrentCapacity)
{
	ovr_RichPresenceOptions_SetCurrentCapacity(OvrRichPresenceOptions, RichPresenseCurrentCapacity);
}

void UOBPRichPresence::SetDeeplinkMessageOverride(const FString RichPresenseDeeplinkMessage)
{
	ovr_RichPresenceOptions_SetDeeplinkMessageOverride(OvrRichPresenceOptions, TCHAR_TO_ANSI(*RichPresenseDeeplinkMessage));
}

void UOBPRichPresence::SetEndTime(const int64 RichPresenseEndTime)
{
	ovr_RichPresenceOptions_SetEndTime(OvrRichPresenceOptions, RichPresenseEndTime);
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

void UOBPRichPresence::SetIsIdle(const bool RichPresenseIsIdle)
{
	ovr_RichPresenceOptions_SetIsIdle(OvrRichPresenceOptions, RichPresenseIsIdle);
}

void UOBPRichPresence::SetIsJoinable(const bool RichPresenseIsJoinable)
{
	ovr_RichPresenceOptions_SetIsJoinable(OvrRichPresenceOptions, RichPresenseIsJoinable);
}

void UOBPRichPresence::SetJoinableId(const FString RichPresenseJoinableId)
{
	ovr_RichPresenceOptions_SetJoinableId(OvrRichPresenceOptions, TCHAR_TO_ANSI(*RichPresenseJoinableId));
}

void UOBPRichPresence::SetMaxCapacity(const int RichPresenseMaxCapacity)
{
	ovr_RichPresenceOptions_SetMaxCapacity(OvrRichPresenceOptions, RichPresenseMaxCapacity);
}

void UOBPRichPresence::SetStartTime(const int64 RichPresenseStartTime)
{
	ovr_RichPresenceOptions_SetStartTime(OvrRichPresenceOptions, RichPresenseStartTime);
}

// --------------------
// Rich Presense Extra Context
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

// --------------------
// Rich Presense Requests
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

// requires OculusPlatfromSDK v12 (1.44) or later; default UE4 distribution = 1.40
#if PLATFORM_MINOR_VERSION >= 44
void UOBPRichPresence::GetDestinations()
{
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
}
#endif

// requires OculusPlatfromSDK v12 (1.44) or later; default UE4 distribution = 1.40
#if PLATFORM_MINOR_VERSION >= 44
void UOBPRichPresence::GetNextDestinationArrayPage()
{
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
}
#endif

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
