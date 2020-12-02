// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Requests_RichPresence.h"

// --------------------
// Initializers
// --------------------

UOBP_RichPresence_ClearRichPresence::UOBP_RichPresence_ClearRichPresence(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_RichPresence_GetDestinations::UOBP_RichPresence_GetDestinations(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_RichPresence_GetNextDestinationArrayPage::UOBP_RichPresence_GetNextDestinationArrayPage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_RichPresence_SetRichPresence::UOBP_RichPresence_SetRichPresence(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_Requests_RichPresence.h
// --------------------

//---ClearRichPresence---
void UOBP_RichPresence_ClearRichPresence::Activate()
{
#if PLATFORM_MINOR_VERSION >= 39
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
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
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast();
	}
#else
	OBP_PlatformVersionError("RichPresence::ClearRichPresence", "1.39");
	OnFailure.Broadcast();
#endif
}

UOBP_RichPresence_ClearRichPresence* UOBP_RichPresence_ClearRichPresence::ClearRichPresence(UObject* WorldContextObject)
{
	return NewObject<UOBP_RichPresence_ClearRichPresence>();
}

//---GetDestinations---
void UOBP_RichPresence_GetDestinations::Activate()
{
#if PLATFORM_MINOR_VERSION >= 41
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_RichPresence_GetDestinations();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
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
	}
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(nullptr);
	}
#else
	OBP_PlatformVersionError("RichPresence::GetDestinations", "1.41");
	OnFailure.Broadcast(nullptr);
#endif
}

UOBP_RichPresence_GetDestinations* UOBP_RichPresence_GetDestinations::GetDestinations(UObject* WorldContextObject)
{
	return NewObject<UOBP_RichPresence_GetDestinations>();
}

//---GetNextDestinationArrayPage---
void UOBP_RichPresence_GetNextDestinationArrayPage::Activate()
{
#if PLATFORM_MINOR_VERSION >= 41
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_RichPresence_GetNextDestinationArrayPage(DestinationArray->ovrDestinationArrayHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
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
					auto NextDestinationArray = NewObject<UOBP_DestinationArray>();
					NextDestinationArray->ovrDestinationArrayHandle = ovr_Message_GetDestinationArray(Message);
					OnSuccess.Broadcast(NextDestinationArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get destination array page."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(nullptr);
	}
#else
	OBP_PlatformVersionError("RichPresence::GetNextDestinationArrayPage", "1.41");
	OnFailure.Broadcast(nullptr);
#endif
}

UOBP_RichPresence_GetNextDestinationArrayPage* UOBP_RichPresence_GetNextDestinationArrayPage::GetNextDestinationArrayPage(UObject* WorldContextObject, UOBP_DestinationArray* DestinationArray)
{
	auto DestinationArrayPage = NewObject<UOBP_RichPresence_GetNextDestinationArrayPage>();
	DestinationArrayPage->DestinationArray = DestinationArray;
	return DestinationArrayPage;
}

//---SetRichPresence---
void UOBP_RichPresence_SetRichPresence::Activate()
{
#if PLATFORM_MINOR_VERSION >= 39
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_RichPresence_Set(RichPresenceObject->ovrRichPresenceOptionsHandle);

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
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast();
	}
#else
	OBP_PlatformVersionError("RichPresence::SetRichPresence", "1.39");
	OnFailure.Broadcast();
#endif
}

UOBP_RichPresence_SetRichPresence* UOBP_RichPresence_SetRichPresence::SetRichPresence(UObject* WorldContextObject, UOBP_RichPresenceOptions* RichPresenceObject)
{
	auto SetRichPresence = NewObject<UOBP_RichPresence_SetRichPresence>();
	SetRichPresence->RichPresenceObject = RichPresenceObject;
	return SetRichPresence;
}