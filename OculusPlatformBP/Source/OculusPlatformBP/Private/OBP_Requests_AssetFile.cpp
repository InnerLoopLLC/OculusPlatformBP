// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Requests_AssetFile.h"

// --------------------
// Initializers
// --------------------

UOBP_AssetFile_DeleteByID::UOBP_AssetFile_DeleteByID(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_AssetFile_DeleteByName::UOBP_AssetFile_DeleteByName(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_AssetFile_DownloadByID::UOBP_AssetFile_DownloadByID(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_AssetFile_DownloadByName::UOBP_AssetFile_DownloadByName(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_AssetFile_DownloadCancelByID::UOBP_AssetFile_DownloadCancelByID(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_AssetFile_DownloadCancelByName::UOBP_AssetFile_DownloadCancelByName(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_AssetFile_GetList::UOBP_AssetFile_GetList(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_AssetFile_StatusByID::UOBP_AssetFile_StatusByID(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_AssetFile_StatusByName::UOBP_AssetFile_StatusByName(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// --------------------
// OVR_Requests_AssetFile.h
// --------------------

//---DeleteByID---
void UOBP_AssetFile_DeleteByID::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_AssetFile_DeleteById(OBP_FStringToInt64(AssetFileID));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("AssetFile::DeleteByID", Message);
				OnFailure.Broadcast(FString(), FString(), false);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_AssetFile_DeleteById)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully deleted asset file by ID."));
					auto AssetFileDeleteResultHandle = ovr_Message_GetAssetFileDeleteResult(Message);
					auto AssetID = OBP_Int64ToFString(ovr_AssetFileDeleteResult_GetAssetId(AssetFileDeleteResultHandle));
					auto FilePath = ovr_AssetFileDeleteResult_GetFilepath(AssetFileDeleteResultHandle);
					auto bWasSuccessful = ovr_AssetFileDeleteResult_GetSuccess(AssetFileDeleteResultHandle);
					OnSuccess.Broadcast(AssetID, FilePath, bWasSuccessful);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to delete asset file by ID."));
					OnFailure.Broadcast(FString(), FString(), false);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("AssetFile::DeleteByID");
		OnFailure.Broadcast(FString(), FString(), false);
	}
}

UOBP_AssetFile_DeleteByID* UOBP_AssetFile_DeleteByID::DeleteByID(UObject* WorldContextObject, FString AssetFileID)
{
	auto DeleteByID = NewObject<UOBP_AssetFile_DeleteByID>();
	DeleteByID->AssetFileID = AssetFileID;
	return DeleteByID;
}

//---DeleteByName---
void UOBP_AssetFile_DeleteByName::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_AssetFile_DeleteByName(TCHAR_TO_ANSI(*AssetFileName));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("AssetFile::DeleteByName", Message);
				OnFailure.Broadcast(FString(), FString(), false);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_AssetFile_DeleteByName)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully deleted asset file by name."));
					auto AssetFileDeleteResultHandle = ovr_Message_GetAssetFileDeleteResult(Message);
					auto AssetID = OBP_Int64ToFString(ovr_AssetFileDeleteResult_GetAssetId(AssetFileDeleteResultHandle));
					auto FilePath = ovr_AssetFileDeleteResult_GetFilepath(AssetFileDeleteResultHandle);
					auto bWasSuccessful = ovr_AssetFileDeleteResult_GetSuccess(AssetFileDeleteResultHandle);
					OnSuccess.Broadcast(AssetID, FilePath, bWasSuccessful);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to delete asset file by name."));
					OnFailure.Broadcast(FString(), FString(), false);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("AssetFile::DeleteByName");
		OnFailure.Broadcast(FString(), FString(), false);
	}
}

UOBP_AssetFile_DeleteByName* UOBP_AssetFile_DeleteByName::DeleteByName(UObject* WorldContextObject, FString AssetFileName)
{
	auto DeleteByName = NewObject<UOBP_AssetFile_DeleteByName>();
	DeleteByName->AssetFileName = AssetFileName;
	return DeleteByName;
}

//---DownloadByID---
void UOBP_AssetFile_DownloadByID::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_AssetFile_DownloadById(OBP_FStringToInt64(AssetFileID));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("AssetFile::DownloadByID", Message);
				OnFailure.Broadcast(FString(), FString());
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_AssetFile_DownloadById)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully downloaded asset file by ID."));
					auto AssetFileDownloadResultHandle = ovr_Message_GetAssetFileDownloadResult(Message);
					auto AssetID = OBP_Int64ToFString(ovr_AssetFileDownloadResult_GetAssetId(AssetFileDownloadResultHandle));
					auto FilePath = ovr_AssetFileDownloadResult_GetFilepath(AssetFileDownloadResultHandle);
					OnSuccess.Broadcast(AssetID, FilePath);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to download asset file by ID."));
					OnFailure.Broadcast(FString(), FString());
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("AssetFile::DownloadByID");
		OnFailure.Broadcast(FString(), FString());
	}
}

UOBP_AssetFile_DownloadByID* UOBP_AssetFile_DownloadByID::DownloadByID(UObject* WorldContextObject, FString AssetFileID)
{
	auto DownloadByID = NewObject<UOBP_AssetFile_DownloadByID>();
	DownloadByID->AssetFileID = AssetFileID;
	return DownloadByID;
}

//---DownloadByName---
void UOBP_AssetFile_DownloadByName::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_AssetFile_DownloadByName(TCHAR_TO_ANSI(*AssetFileName));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("AssetFile::DownloadByName", Message);
				OnFailure.Broadcast(FString(), FString());
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_AssetFile_DownloadByName)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully downloaded asset file by name."));
					auto AssetFileDownloadResultHandle = ovr_Message_GetAssetFileDownloadResult(Message);
					auto AssetID = OBP_Int64ToFString(ovr_AssetFileDownloadResult_GetAssetId(AssetFileDownloadResultHandle));
					auto FilePath = ovr_AssetFileDownloadResult_GetFilepath(AssetFileDownloadResultHandle);
					OnSuccess.Broadcast(AssetID, FilePath);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to download asset file by name."));
					OnFailure.Broadcast(FString(), FString());
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("AssetFile::DownloadByName");
		OnFailure.Broadcast(FString(), FString());
	}
}

UOBP_AssetFile_DownloadByName* UOBP_AssetFile_DownloadByName::DownloadByName(UObject* WorldContextObject, FString AssetFileName)
{
	auto DownloadByName = NewObject<UOBP_AssetFile_DownloadByName>();
	DownloadByName->AssetFileName = AssetFileName;
	return DownloadByName;
}

//---DownloadCancelByID---
void UOBP_AssetFile_DownloadCancelByID::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_AssetFile_DownloadCancelById(OBP_FStringToInt64(AssetFileID));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("AssetFile::DownloadCancelByID", Message);
				OnFailure.Broadcast(FString(), FString(), false);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_AssetFile_DownloadCancelById)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully canceled download of asset file by ID."));
					auto AssetFileDownloadCancelResultHandle = ovr_Message_GetAssetFileDownloadCancelResult(Message);
					auto AssetID = OBP_Int64ToFString(ovr_AssetFileDownloadCancelResult_GetAssetId(AssetFileDownloadCancelResultHandle));
					auto FilePath = ovr_AssetFileDownloadCancelResult_GetFilepath(AssetFileDownloadCancelResultHandle);
					auto bWasSuccessful = ovr_AssetFileDownloadCancelResult_GetSuccess(AssetFileDownloadCancelResultHandle);
					OnSuccess.Broadcast(AssetID, FilePath, bWasSuccessful);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to cancel download of asset file by ID."));
					OnFailure.Broadcast(FString(), FString(), false);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("AssetFile::DownloadCancelByID");
		OnFailure.Broadcast(FString(), FString(), false);
	}
}

UOBP_AssetFile_DownloadCancelByID* UOBP_AssetFile_DownloadCancelByID::DownloadCancelByID(UObject* WorldContextObject, FString AssetFileID)
{
	auto DownloadCancelByID = NewObject<UOBP_AssetFile_DownloadCancelByID>();
	DownloadCancelByID->AssetFileID = AssetFileID;
	return DownloadCancelByID;
}

//---DownloadCancelByName---
void UOBP_AssetFile_DownloadCancelByName::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_AssetFile_DownloadCancelByName(TCHAR_TO_ANSI(*AssetFileName));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("AssetFile::DownloadCancelByName", Message);
				OnFailure.Broadcast(FString(), FString(), false);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_AssetFile_DownloadCancelByName)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully canceled download of asset file by name."));
					auto AssetFileDownloadCancelResultHandle = ovr_Message_GetAssetFileDownloadCancelResult(Message);
					auto AssetID = OBP_Int64ToFString(ovr_AssetFileDownloadCancelResult_GetAssetId(AssetFileDownloadCancelResultHandle));
					auto FilePath = ovr_AssetFileDownloadCancelResult_GetFilepath(AssetFileDownloadCancelResultHandle);
					auto bWasSuccessful = ovr_AssetFileDownloadCancelResult_GetSuccess(AssetFileDownloadCancelResultHandle);
					OnSuccess.Broadcast(AssetID, FilePath, bWasSuccessful);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to cancel download of asset file by name."));
					OnFailure.Broadcast(FString(), FString(), false);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("AssetFile::DownloadCancelByName");
		OnFailure.Broadcast(FString(), FString(), false);
	}
}

UOBP_AssetFile_DownloadCancelByName* UOBP_AssetFile_DownloadCancelByName::DownloadCancelByName(UObject* WorldContextObject, FString AssetFileName)
{
	auto DownloadCancelByName = NewObject<UOBP_AssetFile_DownloadCancelByName>();
	DownloadCancelByName->AssetFileName = AssetFileName;
	return DownloadCancelByName;
}

//---GetList---
void UOBP_AssetFile_GetList::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_AssetFile_GetList();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("AssetFile::GetList", Message);
				OnFailure.Broadcast(TArray<UOBP_AssetDetails*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_AssetFile_GetList)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got list of asset files."));
					auto AssetDetailsArray = NewObject<UOBP_AssetDetailsArray>();
					AssetDetailsArray->ovrAssetDetailsArrayHandle = ovr_Message_GetAssetDetailsArray(Message);

					TArray<UOBP_AssetDetails*> AssetDetails;

					for (size_t i = 0; i < ovr_AssetDetailsArray_GetSize(AssetDetailsArray->ovrAssetDetailsArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_AssetDetails>();
						ThisElement->ovrAssetDetailsHandle = ovr_AssetDetailsArray_GetElement(AssetDetailsArray->ovrAssetDetailsArrayHandle, i);
						AssetDetails.Add(ThisElement);
					}

					OnSuccess.Broadcast(AssetDetails, AssetDetailsArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get list of asset files."));
					OnFailure.Broadcast(TArray<UOBP_AssetDetails*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("AssetFile::GetList");
		OnFailure.Broadcast(TArray<UOBP_AssetDetails*>(), nullptr);
	}
}

UOBP_AssetFile_GetList* UOBP_AssetFile_GetList::GetList(UObject* WorldContextObject)
{
	return NewObject<UOBP_AssetFile_GetList>();
}

//---StatusByID---
void UOBP_AssetFile_StatusByID::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_AssetFile_StatusById(OBP_FStringToInt64(AssetFileID));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("AssetFile::StatusByID", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_AssetFile_StatusById)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got asset status by ID."));
					auto AssetDetails = NewObject<UOBP_AssetDetails>();
					AssetDetails->ovrAssetDetailsHandle = ovr_Message_GetAssetDetails(Message);
					OnSuccess.Broadcast(AssetDetails);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get asset status by ID."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("AssetFile::StatusByID");
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_AssetFile_StatusByID* UOBP_AssetFile_StatusByID::StatusByID(UObject* WorldContextObject, FString AssetFileID)
{
	auto StatusByID = NewObject<UOBP_AssetFile_StatusByID>();
	StatusByID->AssetFileID = AssetFileID;
	return StatusByID;
}

//---StatusByName---
void UOBP_AssetFile_StatusByName::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_AssetFile_StatusByName(TCHAR_TO_ANSI(*AssetFileName));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("AssetFile::StatusByName", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_AssetFile_DeleteById)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully deleted asset file by name."));
					auto AssetDetails = NewObject<UOBP_AssetDetails>();
					AssetDetails->ovrAssetDetailsHandle = ovr_Message_GetAssetDetails(Message);
					OnSuccess.Broadcast(AssetDetails);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to delete asset file by name."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("AssetFile::StatusByName");
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_AssetFile_StatusByName* UOBP_AssetFile_StatusByName::StatusByName(UObject* WorldContextObject, FString AssetFileName)
{
	auto StatusByName = NewObject<UOBP_AssetFile_StatusByName>();
	StatusByName->AssetFileName = AssetFileName;
	return StatusByName;
}