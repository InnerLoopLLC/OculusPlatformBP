// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_AssetDetails.h"
#include "OBP_AssetDetailsArray.h"
#include "OBP_Requests_AssetFile.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAssetFile_DeleteByID, FString, AssetID, FString, FilePath, bool, WasSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAssetFile_DeleteByName, FString, AssetID, FString, FilePath, bool, WasSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAssetFile_DownloadByID, FString, AssetID, FString, FilePath);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAssetFile_DownloadByName, FString, AssetID, FString, FilePath);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAssetFile_DownloadCancelByID, FString, AssetID, FString, FilePath, bool, WasSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAssetFile_DownloadCancelByName, FString, AssetID, FString, FilePath, bool, WasSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAssetFile_GetList, const TArray<UOBP_AssetDetails*>&, AssetDetails, UOBP_AssetDetailsArray*, AssetDetailsArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAssetFile_StatusByID, UOBP_AssetDetails*, AssetDetails);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAssetFile_StatusByName, UOBP_AssetDetails*, AssetDetails);

// --------------------
// OVR_Requests_AssetFile.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_AssetFile_DeleteByID : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString AssetFileID;

	UPROPERTY(BlueprintAssignable)
		FAssetFile_DeleteByID OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAssetFile_DeleteByID OnFailure;

	/* Removes an previously installed asset file from the device by its ID. Returns an object containing the asset ID and file name, and a success flag. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Asset File|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_AssetFile_DeleteByID* DeleteByID(UObject* WorldContextObject, FString AssetFileID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_AssetFile_DeleteByName : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString AssetFileName;

	UPROPERTY(BlueprintAssignable)
		FAssetFile_DeleteByName OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAssetFile_DeleteByName OnFailure;

	/* Removes an previously installed asset file from the device by its name. Returns an object containing the asset ID and file name, and a success flag. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Asset File|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_AssetFile_DeleteByName* DeleteByName(UObject* WorldContextObject, FString AssetFileName);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_AssetFile_DownloadByID : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString AssetFileID;

	UPROPERTY(BlueprintAssignable)
		FAssetFile_DownloadByID OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAssetFile_DownloadByID OnFailure;

	/* Downloads an asset file by its ID on demand. Returns an object containing the asset ID and filepath. Sends periodic ovrNotification_AssetFile_DownloadUpdate to track the downloads. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Asset File|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_AssetFile_DownloadByID* DownloadByID(UObject* WorldContextObject, FString AssetFileID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_AssetFile_DownloadByName : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString AssetFileName;

	UPROPERTY(BlueprintAssignable)
		FAssetFile_DownloadByName OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAssetFile_DownloadByName OnFailure;

	/* Downloads an asset file by its name on demand. Returns an object containing the asset ID and filepath. Sends periodic {notifications.asset_file.download_update}} to track the downloads. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Asset File|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_AssetFile_DownloadByName* DownloadByName(UObject* WorldContextObject, FString AssetFileName);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_AssetFile_DownloadCancelByID : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString AssetFileID;

	UPROPERTY(BlueprintAssignable)
		FAssetFile_DownloadCancelByID OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAssetFile_DownloadCancelByID OnFailure;

	/* Cancels a previously spawned download request for an asset file by its ID. Returns an object containing the asset ID and file path, and a success flag. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Asset File|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_AssetFile_DownloadCancelByID* DownloadCancelByID(UObject* WorldContextObject, FString AssetFileID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_AssetFile_DownloadCancelByName : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString AssetFileName;

	UPROPERTY(BlueprintAssignable)
		FAssetFile_DownloadCancelByName OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAssetFile_DownloadCancelByName OnFailure;

	/* Cancels a previously spawned download request for an asset file by its name. Returns an object containing the asset ID and file path, and a success flag. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Asset File|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_AssetFile_DownloadCancelByName* DownloadCancelByName(UObject* WorldContextObject, FString AssetFileName);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_AssetFile_GetList : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FAssetFile_GetList OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAssetFile_GetList OnFailure;

	/* Returns an array of objects with asset file names and their associated IDs, and and whether it's currently installed. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Asset File|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_AssetFile_GetList* GetList(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_AssetFile_StatusByID : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString AssetFileID;

	UPROPERTY(BlueprintAssignable)
		FAssetFile_StatusByID OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAssetFile_StatusByID OnFailure;

	/* Returns the details on a single asset: ID, file name, and whether it's currently installed */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Asset File|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_AssetFile_StatusByID* StatusByID(UObject* WorldContextObject, FString AssetFileID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_AssetFile_StatusByName : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString AssetFileName;

	UPROPERTY(BlueprintAssignable)
		FAssetFile_StatusByName OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FAssetFile_StatusByName OnFailure;

	/* Returns the details on a single asset: ID, file name, and whether it's currently installed */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Asset File|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_AssetFile_StatusByName* StatusByName(UObject* WorldContextObject, FString AssetFileName);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};