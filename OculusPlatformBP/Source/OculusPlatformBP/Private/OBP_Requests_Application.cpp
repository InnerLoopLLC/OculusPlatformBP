// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Requests_Application.h"

// --------------------
// Initializers
// --------------------

UOBP_Application_GetVersion::UOBP_Application_GetVersion(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Application_LaunchOtherApp::UOBP_Application_LaunchOtherApp(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_Requests_Application.h
// --------------------

//---GetVersion---
void UOBP_Application_GetVersion::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Application_GetVersion();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Application::GetVersion", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Application_GetVersion)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got application version."));
					auto ApplicationVersion = NewObject<UOBP_ApplicationVersion>();
					ApplicationVersion->ovrApplicationVersionHandle = ovr_Message_GetApplicationVersion(Message);
					OnSuccess.Broadcast(ApplicationVersion);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get application version."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure OnlineSubsystemOculus is enabled and DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_Application_GetVersion* UOBP_Application_GetVersion::GetVersion(UObject* WorldContextObject)
{
	return NewObject<UOBP_Application_GetVersion>();
}

//---LaunchOtherApp---
void UOBP_Application_LaunchOtherApp::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Application_LaunchOtherApp(OBP_FStringToInt64(AppID), DeeplinkOptions->ovrApplicationOptionsHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Application::LauchOtherApp", Message);
				OnFailure.Broadcast(FString());
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Application_LaunchOtherApp)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully launched other app."));
					auto String = ovr_Message_GetString(Message);
					OnSuccess.Broadcast(String);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to launch other app."));
					OnFailure.Broadcast(FString());
				}
			}
		}));
	}
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure OnlineSubsystemOculus is enabled and DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast(FString());
	}
}

UOBP_Application_LaunchOtherApp *UOBP_Application_LaunchOtherApp::LaunchOtherApp(UObject* WorldContextObject, FString AppID, UOBP_ApplicationOptions* DeeplinkOptions)
{
	auto LaunchOtherApp = NewObject<UOBP_Application_LaunchOtherApp>();
	LaunchOtherApp->AppID = AppID;
	LaunchOtherApp->DeeplinkOptions = DeeplinkOptions;
	return LaunchOtherApp;
}