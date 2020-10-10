// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBPRichPresence.h"

// --------------------
// Initializers
// --------------------

UOBP_RichPresence::UOBP_RichPresence(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_ClearRichPresence::UOBP_ClearRichPresence(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_GetDestinations::UOBP_GetDestinations(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_GetNextDestinationArrayPage::UOBP_GetNextDestinationArrayPage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_SetRichPresence::UOBP_SetRichPresence(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_RichPresenceRequests.h
// --------------------

//---ClearRichPresence---
void UOBP_ClearRichPresence::Activate()
{
#if PLATFORM_MINOR_VERSION >= 39
	ovrRequest RequestId = ovr_RichPresence_Clear();

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("RichPresence::ClearRichPresence", Message);
			OnFailure.Broadcast();
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_RichPresence_Clear)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully cleared rich presence."));
				OnSuccess.Broadcast();
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to clear rich presence."));
				OnFailure.Broadcast();
			}
		}
	}));
#else
	OBP_PlatformVersionError("RichPresence::ClearRichPresence", "1.39");
	OnFailure.Broadcast();
#endif
}

UOBP_ClearRichPresence* UOBP_ClearRichPresence::ClearRichPresence(UObject* WorldContextObject)
{
	return NewObject<UOBP_ClearRichPresence>();
}

//---GetDestinations---
void UOBP_GetDestinations::Activate()
{
#if PLATFORM_MINOR_VERSION >= 41
	ovrRequest RequestId = ovr_RichPresence_GetDestinations();

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this, DestinationArray](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("RichPresence::GetDestinations", Message);
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_RichPresence_GetDestinations)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got destinations."));
				auto DestinationArray = NewObject<UOBP_DestinationArray>();
				DestinationArray->ovrDestinationArrayHandle = ovr_Message_GetDestinationArray(Message);
				OnSuccess.Broadcast(DestinationArray);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get destinations."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
#else
	OBP_PlatformVersionError("RichPresence::GetDestinations", "1.41");
	OnFailure.Broadcast(nullptr);
#endif
}

UOBP_GetDestinations* UOBP_GetDestinations::GetDestinations(UObject* WorldContextObject)
{
	return NewObject<UOBP_GetDestinations>();
}

//---GetNextDestinationArrayPage---
void UOBP_GetNextDestinationArrayPage::Activate()
{
#if PLATFORM_MINOR_VERSION >= 41
	ovrRequest RequestId = ovr_RichPresence_GetNextDestinationArrayPage(DestinationArray->ovrDestinationArrayHandle);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this, DestinationArray](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("RichPresence::GetNextDestinationArray", Message);
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_RichPresence_GetNextDestinationArrayPage)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got destination array page."));
				auto DestinationArray = NewObject<UOBP_DestinationArray>();
				DestinationArray->ovrDestinationArrayHandle = ovr_Message_GetDestinationArray(Message);
				OnSuccess.Broadcast(DestinationArray);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get destination array page."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
#else
	OBP_PlatformVersionError("RichPresence::GetNextDestinationArrayPage", "1.41");
	OnFailure.Broadcast(nullptr);
#endif
}

UOBP_GetNextDestinationArrayPage* UOBP_GetNextDestinationArrayPage::GetNextDestinationArrayPage(UObject* WorldContextObject, UOBP_DestinationArray* DestinationArray)
{
	auto DestinationArrayPage = NewObject<UOBP_GetNextDestinationArrayPage>();
#if PLATFORM_MINOR_VERSION >= 41
	auto DestinationArray = DestinationArray;
#endif
	return DestinationArrayPage;
}

//---SetRichPresence---
void UOBP_SetRichPresence::Activate()
{
#if PLATFORM_MINOR_VERSION >= 39
	ovrRequest RequestId = ovr_RichPresence_Set(OvrRichPresenceOptions);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("RichPresence::SetRichPresence", Message);
			OnFailure.Broadcast();
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_RichPresence_Set)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully set rich presence."));
				OnSuccess.Broadcast();
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to set rich presence."));
				OnFailure.Broadcast();
			}
		}
	}));
#else
	OBP_PlatformVersionError("RichPresence::SetRichPresence", "1.39");
	OnFailure.Broadcast();
#endif
}

UOBP_SetRichPresence* UOBP_SetRichPresence::SetRichPresence(UObject* WorldContextObject, UOBP_RichPresence* RichPresenceObject)
{
	auto SetRichPresence = NewObject<UOBP_SetRichPresence>();
#if PLATFORM_MINOR_VERSION >= 39
	SetRichPresence->OvrRichPresenceOptions = RichPresenceObject->OvrRichPresenceOptions;
#endif
	return SetRichPresence;
}

// --------------------
// OVR_RichPresence.h
// --------------------

UOBP_RichPresence* UOBP_RichPresence::CreateRichPresenceOptions(UObject* WorldContextObject)
{
#if PLATFORM_MINOR_VERSION >= 39
	return NewObject<UOBP_RichPresence>();
#else
	return nullptr;
#endif
}

void UOBP_RichPresence::DestroyRichPresenceOptions()
{
#if PLATFORM_MINOR_VERSION >= 39
	ovr_RichPresenceOptions_Destroy(OvrRichPresenceOptions);
#endif
}

void UOBP_RichPresence::SetApiName(const FString RichPresenceApiName)
{
#if PLATFORM_MINOR_VERSION >= 39
	ovr_RichPresenceOptions_SetApiName(OvrRichPresenceOptions, TCHAR_TO_ANSI(*RichPresenceApiName));
#endif
}

void UOBP_RichPresence::SetArgsString(const FString RichPresenceApiKey, const FString RichPresenceApiValue)
{
#if PLATFORM_MINOR_VERSION >= 39
	ovr_RichPresenceOptions_SetArgsString(OvrRichPresenceOptions, TCHAR_TO_ANSI(*RichPresenceApiKey), TCHAR_TO_ANSI(*RichPresenceApiValue));
#endif
}

void UOBP_RichPresence::ClearArgs()
{
#if PLATFORM_MINOR_VERSION >= 39
	ovr_RichPresenceOptions_ClearArgs(OvrRichPresenceOptions);
#endif
}

void UOBP_RichPresence::SetCurrentCapacity(const int32 RichPresenceCurrentCapacity)
{
#if PLATFORM_MINOR_VERSION >= 40
	ovr_RichPresenceOptions_SetCurrentCapacity(OvrRichPresenceOptions, RichPresenceCurrentCapacity);
#endif
}

void UOBP_RichPresence::SetDeeplinkMessageOverride(const FString RichPresenceDeeplinkMessage)
{
#if PLATFORM_MINOR_VERSION >= 40
	ovr_RichPresenceOptions_SetDeeplinkMessageOverride(OvrRichPresenceOptions, TCHAR_TO_ANSI(*RichPresenceDeeplinkMessage));
#endif
}

void UOBP_RichPresence::SetEndTime(const int64 RichPresenceEndTime)
{
#if PLATFORM_MINOR_VERSION >= 39
	ovr_RichPresenceOptions_SetEndTime(OvrRichPresenceOptions, RichPresenceEndTime);
#endif
}

void UOBP_RichPresence::SetExtraContext(EOBP_RichPresenceExtraContext RichPresenceExtraContext)
{
#if PLATFORM_MINOR_VERSION >= 40
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
#endif
}

void UOBP_RichPresence::SetIsIdle(const bool RichPresenceIsIdle)
{
#if PLATFORM_MINOR_VERSION >= 39
	ovr_RichPresenceOptions_SetIsIdle(OvrRichPresenceOptions, RichPresenceIsIdle);
#endif
}

void UOBP_RichPresence::SetIsJoinable(const bool RichPresenceIsJoinable)
{
#if PLATFORM_MINOR_VERSION >= 39
	ovr_RichPresenceOptions_SetIsJoinable(OvrRichPresenceOptions, RichPresenceIsJoinable);
#endif
}

void UOBP_RichPresence::SetJoinableId(const FString RichPresenceJoinableId)
{
#if PLATFORM_MINOR_VERSION >= 39
	ovr_RichPresenceOptions_SetJoinableId(OvrRichPresenceOptions, TCHAR_TO_ANSI(*RichPresenceJoinableId));
#endif
}

void UOBP_RichPresence::SetMaxCapacity(const int32 RichPresenceMaxCapacity)
{
#if PLATFORM_MINOR_VERSION >= 40
	ovr_RichPresenceOptions_SetMaxCapacity(OvrRichPresenceOptions, RichPresenceMaxCapacity);
#endif
}

void UOBP_RichPresence::SetStartTime(const int64 RichPresenceStartTime)
{
#if PLATFORM_MINOR_VERSION >= 40
	ovr_RichPresenceOptions_SetStartTime(OvrRichPresenceOptions, RichPresenceStartTime);
#endif
}