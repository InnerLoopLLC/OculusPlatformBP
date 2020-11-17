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

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Asset File|Asset Details")
		FString GetAssetId(int32 Index);

	/* Requires OculusPlatfromSDK 1.28 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Asset File|Asset Details")
		FString GetAssetType();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Asset File|Asset Details")
		FString GetDownloadStatus();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Asset File|Asset Details")
		FString GetFilePath();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Asset File|Asset Details")
		FString GetIapStatus();

	/* Requires OculusPlatfromSDK 1.28 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Asset File|Asset Details")
		UOBP_LanguagePackInfo* GetLanguage();

	/* Requires OculusPlatfromSDK 1.40 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Asset File|Asset Details")
		FString GetMetadata();
};