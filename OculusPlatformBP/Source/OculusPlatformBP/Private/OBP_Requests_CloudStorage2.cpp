// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Requests_CloudStorage2.h"

// --------------------
// Initializers
// --------------------

UOBP_CloudStorage2_GetUserDirectoryPath::UOBP_CloudStorage2_GetUserDirectoryPath(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_Requests_CloudStorage2.h
// --------------------

//---GetUser---
void UOBP_CloudStorage2_GetUserDirectoryPath::Activate()
{
#if PLATFORM_MINOR_VERSION >= 39
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_CloudStorage2_GetUserDirectoryPath();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("CloudStorage2::GetUserDirectoryPath", Message);
				OnFailure.Broadcast("");
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_User_Get)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got user directory path."));
					OnSuccess.Broadcast(ovr_Message_GetString(Message));
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get user directory path."));
					OnFailure.Broadcast("");
				}
			}
		}));
	}
	else
	{
		UE_LOG(LogOculusPlatformBP, Warning, TEXT("Oculus platform service not available. Ensure OnlineSubsystemOculus is enabled and DefaultEngine.ini is properly configured."));
		OnFailure.Broadcast("");
	}
#else
	OBP_PlatformVersionError("CloudStorage2::GetUserDirectoryPath", "1.39");
	OnFailure.Broadcast("");
#endif
}

UOBP_CloudStorage2_GetUserDirectoryPath* UOBP_CloudStorage2_GetUserDirectoryPath::GetUserDirectoryPath(UObject* WorldContextObject)
{
	return NewObject<UOBP_CloudStorage2_GetUserDirectoryPath>();
}