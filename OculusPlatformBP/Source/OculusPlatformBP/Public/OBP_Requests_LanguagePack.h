// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_AssetDetails.h"
#include "OBP_Requests_LanguagePack.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLanguagePack_GetCurrent, UOBP_AssetDetails*, AssetDetails);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLanguagePack_SetCurrent, FString, AssetID, FString, FilePath);

// --------------------
// OVR_Requests_Application.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_LanguagePack_GetCurrent : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FLanguagePack_GetCurrent OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FLanguagePack_GetCurrent OnFailure;

	/* Returns currently installed and selected language pack for an app in the view of the asset_details. Use language field to extract neeeded language info. 
	A particular language can be download and installed by a user from the Oculus app on the application page. 
	Require OculusPlatfromSDK 1.28 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Language Pack|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_LanguagePack_GetCurrent* GetCurrent(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_LanguagePack_SetCurrent : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString Tag;

	UPROPERTY(BlueprintAssignable)
		FLanguagePack_SetCurrent OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FLanguagePack_SetCurrent OnFailure;

	/* Sets the current language to specified. The parameter is the BCP47 language tag. 
	If a language pack is not downloaded yet, spawns automatically the ovr_AssetFile_DownloadByName() request, and sends periodic ovrNotification_AssetFile_DownloadUpdate to track the downloads. 
	Once the language asset file is downloaded, call ovr_LanguagePack_GetCurrent() to retrive the data, and use the language at runtime. 
	Require OculusPlatfromSDK 1.31 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Language Pack|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_LanguagePack_SetCurrent* SetCurrent(UObject* WorldContextObject, FString Tag);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};