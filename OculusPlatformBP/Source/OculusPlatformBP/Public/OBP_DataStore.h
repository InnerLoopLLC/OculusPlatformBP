// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_DataStore.generated.h"

// --------------------
// OVR_DataStore.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_DataStore : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrDataStore* ovrDataStoreHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Misc|Data Store")
		int32 Contains(FString Key);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Misc|Data Store")
		FString GetKey(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Misc|Data Store")
		int32 GetNumKeys();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Misc|Data Store")
		FString GetValue(FString Key);
};