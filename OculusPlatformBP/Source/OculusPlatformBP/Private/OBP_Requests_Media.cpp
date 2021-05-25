// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Requests_Media.h"

// --------------------
// Initializers
// --------------------

UOBP_Media_ShareToFacebook::UOBP_Media_ShareToFacebook(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// ovr_Requests_Media.h
// --------------------

//---GetStatus---
void UOBP_Media_ShareToFacebook::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrMediaContentType ThisMediaContentType;
		switch (ContentType)
		{
		case EOBP_MediaContentType::Unknown:
			ThisMediaContentType = ovrMediaContentType_Unknown;
			break;
		case EOBP_MediaContentType::Photo:
			ThisMediaContentType = ovrMediaContentType_Photo;
			break;
		default:
			ThisMediaContentType = ovrMediaContentType_Unknown;
			break;
		}

		ovrRequest RequestId = ovr_Media_ShareToFacebook(TCHAR_TO_ANSI(*PostTextSuggestion), TCHAR_TO_ANSI(*FilePath), ThisMediaContentType);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Media::ShareToFacebook", Message);
				OnFailure.Broadcast(EOBP_ShareMediaStatus::Unknown);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Media_ShareToFacebook)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully shared to Facebook."));
					auto ShareMediaResult = ovr_ShareMediaResult_GetStatus(ovr_Message_GetShareMediaResult(Message));
					EOBP_ShareMediaStatus ShareMediaStatus;
					switch (ShareMediaResult)
					{
					case ovrShareMediaStatus_Unknown:
						ShareMediaStatus = EOBP_ShareMediaStatus::Unknown;
						break;
					case ovrShareMediaStatus_Shared:
						ShareMediaStatus = EOBP_ShareMediaStatus::Shared;
						break;
					case ovrShareMediaStatus_Canceled:
						ShareMediaStatus = EOBP_ShareMediaStatus::Canceled;
						break;
					default:
						ShareMediaStatus = EOBP_ShareMediaStatus::Unknown;
						break;
					}
					OnSuccess.Broadcast(ShareMediaStatus);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to share to Facebook."));
					OnFailure.Broadcast(EOBP_ShareMediaStatus::Unknown);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Media::ShareToFacebook");
		OnFailure.Broadcast(EOBP_ShareMediaStatus::Unknown);
	}
}

UOBP_Media_ShareToFacebook* UOBP_Media_ShareToFacebook::ShareToFacebook(UObject* WorldContextObject, FString PostTextSuggestion, FString FilePath, EOBP_MediaContentType ContentType)
{
	auto ShareToFacebook = NewObject<UOBP_Media_ShareToFacebook>();
	ShareToFacebook->PostTextSuggestion = PostTextSuggestion;
	ShareToFacebook->FilePath = FilePath;
	ShareToFacebook->ContentType = ContentType;
	return ShareToFacebook;
}