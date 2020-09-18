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
}

UOBP_ClearRichPresence* UOBP_ClearRichPresence::ClearRichPresence(UObject* WorldContextObject)
{
	return NewObject<UOBP_ClearRichPresence>();
}

//---GetDestinations---
void UOBP_GetDestinations::Activate()
{
#if PLATFORM_MINOR_VERSION >= 41
	UOBP_DestinationArray* DestinationArray = NewObject<UOBP_DestinationArray>();

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
	OBP_PlatformVersionError("GetDestinations", "1.41");
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
	UOBP_DestinationArray* DestinationArray = NewObject<UOBP_DestinationArray>();

	ovrRequest RequestId = ovr_RichPresence_GetNextDestinationArrayPage(ovrDestinationArrayHandle);

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
	OBP_PlatformVersionError("GetNextDestinationArrayPage", "1.41");
	OnFailure.Broadcast(nullptr);
#endif
}

UOBP_GetNextDestinationArrayPage* UOBP_GetNextDestinationArrayPage::GetNextDestinationArrayPage(UObject* WorldContextObject, UOBP_DestinationArray* DestinationArray)
{
	UOBP_GetNextDestinationArrayPage* DestinationArrayPage = NewObject<UOBP_GetNextDestinationArrayPage>();
#if PLATFORM_MINOR_VERSION >= 41
	DestinationArrayPage->ovrDestinationArrayHandle = DestinationArray;
#endif
	return DestinationArrayPage;
}

//---SetRichPresence---
void UOBP_SetRichPresence::Activate()
{
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
}

UOBP_SetRichPresence* UOBP_SetRichPresence::SetRichPresence(UObject* WorldContextObject, UOBP_RichPresence* RichPresenceObject)
{
	UOBP_SetRichPresence* SetRichPresence = NewObject<UOBP_SetRichPresence>();
	SetRichPresence->OvrRichPresenceOptions = RichPresenceObject->OvrRichPresenceOptions;
	return SetRichPresence;
}

// --------------------
// OVR_RichPresence.h
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