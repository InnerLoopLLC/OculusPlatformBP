// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_LanguagePackInfo.h"
#include "OBP_AssetDetails.generated.h"

// --------------------
// OVR_AssetDetails.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_AssetDetails : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrAssetDetails* ovrAssetDetailsHandle;

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Asset File|Asset Details")
		FString GetAssetId(int32 Index);

	/* Requires OculusPlatfromSDK 1.28 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Asset File|Asset Details")
		FString GetAssetType();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Asset File|Asset Details")
		FString GetDownloadStatus();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Asset File|Asset Details")
		FString GetFilePath();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Asset File|Asset Details")
		FString GetIapStatus();

	/* Requires OculusPlatfromSDK 1.28 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Asset File|Asset Details")
		UOBP_LanguagePackInfo* GetLanguage();

	/* Requires OculusPlatfromSDK 1.40 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Asset File|Asset Details")
		FString GetMetadata();
};