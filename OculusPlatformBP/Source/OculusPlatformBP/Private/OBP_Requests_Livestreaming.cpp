// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Requests_Livestreaming.h"

// --------------------
// Initializers
// --------------------

UOBP_Livestreaming_GetStatus::UOBP_Livestreaming_GetStatus(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Livestreaming_PauseStream::UOBP_Livestreaming_PauseStream(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Livestreaming_ResumeStream::UOBP_Livestreaming_ResumeStream(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// ovr_Requests_Livestreaming.h
// --------------------

//---GetStatus---
void UOBP_Livestreaming_GetStatus::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Livestreaming_GetStatus();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Livestreaming::GetStatus", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Livestreaming_GetStatus)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got livestreaming status."));
					auto LivestreamingStatus = NewObject<UOBP_LivestreamingStatus>();
					LivestreamingStatus->ovrLivestreamingStatusHandle = ovr_Message_GetLivestreamingStatus(Message);
					OnSuccess.Broadcast(LivestreamingStatus);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get livestreaming status."));
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
}

UOBP_Livestreaming_GetStatus* UOBP_Livestreaming_GetStatus::GetStatus(UObject* WorldContextObject)
{
	return NewObject<UOBP_Livestreaming_GetStatus>();
}

//---PauseStream---
void UOBP_Livestreaming_PauseStream::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Livestreaming_PauseStream();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Livestreaming::PauseStream", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Livestreaming_PauseStream)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully paused livestream."));
					auto LivestreamingStatus = NewObject<UOBP_LivestreamingStatus>();
					LivestreamingStatus->ovrLivestreamingStatusHandle = ovr_Message_GetLivestreamingStatus(Message);
					OnSuccess.Broadcast(LivestreamingStatus);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to pause livestream."));
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
}

UOBP_Livestreaming_PauseStream* UOBP_Livestreaming_PauseStream::PauseStream(UObject* WorldContextObject)
{
	return NewObject<UOBP_Livestreaming_PauseStream>();
}

//---ResumeStream---
void UOBP_Livestreaming_ResumeStream::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Livestreaming_ResumeStream();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Livestreaming::ResumeStream", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Livestreaming_ResumeStream)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully resumed livestream."));
					auto LivestreamingStatus = NewObject<UOBP_LivestreamingStatus>();
					LivestreamingStatus->ovrLivestreamingStatusHandle = ovr_Message_GetLivestreamingStatus(Message);
					OnSuccess.Broadcast(LivestreamingStatus);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to resume livestream."));
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
}

UOBP_Livestreaming_ResumeStream* UOBP_Livestreaming_ResumeStream::ResumeStream(UObject* WorldContextObject)
{
	return NewObject<UOBP_Livestreaming_ResumeStream>();
}