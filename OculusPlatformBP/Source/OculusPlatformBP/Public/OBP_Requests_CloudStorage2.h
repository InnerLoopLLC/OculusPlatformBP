// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_Requests_CloudStorage2.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCloudStorage2_GetUserDirectoryPath, FString, UserDirectoryPath);

// --------------------
// OVR_Requests_CloudStorage2.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_CloudStorage2_GetUserDirectoryPath : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString ovrId;

	UPROPERTY(BlueprintAssignable)
		FCloudStorage2_GetUserDirectoryPath OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FCloudStorage2_GetUserDirectoryPath OnFailure;

	/* Get the directory path for the current user/app pair that will be used during cloud storage synchronization
	Requires OculusPlatfromSDK 1.39 or later*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|CloudStorageV2|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_CloudStorage2_GetUserDirectoryPath* GetUserDirectoryPath(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};