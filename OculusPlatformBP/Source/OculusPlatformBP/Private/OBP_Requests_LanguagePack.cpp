// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Requests_LanguagePack.h"

// --------------------
// Initializers
// --------------------

UOBP_LanguagePack_GetCurrent::UOBP_LanguagePack_GetCurrent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_LanguagePack_SetCurrent::UOBP_LanguagePack_SetCurrent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_Requests_LanguagePack.h
// --------------------

//---GetCurrent---
void UOBP_LanguagePack_GetCurrent::Activate()
{
#if PLATFORM_MINOR_VERSION >= 28
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_LanguagePack_GetCurrent();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("LanguagePack::GetCurrent", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_LanguagePack_GetCurrent)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got current language pack."));
					auto AssetDetails = NewObject<UOBP_AssetDetails>();
					AssetDetails->ovrAssetDetailsHandle = ovr_Message_GetAssetDetails(Message);
					OnSuccess.Broadcast(AssetDetails);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get current language pack."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("LanguagePack::GetCurrent");
		OnFailure.Broadcast(nullptr);
	}
#else
	OBP_PlatformVersionError("LanguagePack::GetCurrent", "1.28");
	OnFailure.Broadcast(nullptr);
#endif
}

UOBP_LanguagePack_GetCurrent* UOBP_LanguagePack_GetCurrent::GetCurrent(UObject* WorldContextObject)
{
	return NewObject<UOBP_LanguagePack_GetCurrent>();
}

//---SetCurrent---
void UOBP_LanguagePack_SetCurrent::Activate()
{
#if PLATFORM_MINOR_VERSION >= 31
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_LanguagePack_SetCurrent(TCHAR_TO_ANSI(*Tag));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("LanguagePack::SetCurrent", Message);
				OnFailure.Broadcast(FString(), FString());
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_LanguagePack_SetCurrent)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully set current language pack."));
					auto AssetFileDownloadResultHandle = ovr_Message_GetAssetFileDownloadResult(Message);
					auto AssetID = OBP_Int64ToFString(ovr_AssetFileDownloadResult_GetAssetId(AssetFileDownloadResultHandle));
					auto FilePath = ovr_AssetFileDownloadResult_GetFilepath(AssetFileDownloadResultHandle);
					OnSuccess.Broadcast(AssetID, FilePath);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to set current language pack."));
					OnFailure.Broadcast(FString(), FString());
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("LanguagePack::SetCurrent");
		OnFailure.Broadcast(FString(), FString());
	}
#else
	OBP_PlatformVersionError("LanguagePack::SetCurrent", "1.31");
	OnFailure.Broadcast(FString(), FString());
#endif
}

UOBP_LanguagePack_SetCurrent* UOBP_LanguagePack_SetCurrent::SetCurrent(UObject* WorldContextObject, FString Tag)
{
	auto SetCurrent = NewObject<UOBP_LanguagePack_SetCurrent>();
	SetCurrent->Tag = Tag;
	return SetCurrent;
}