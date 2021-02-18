// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_User.h"
#include "OBP_UserArray.generated.h"

// --------------------
// OVR_UserArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_UserArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrUserArray* ovrUserArrayHandle;

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User Array")
		UOBP_User* GetElement(int32 Index);

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User Array")
		FString GetNextUrl();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User Array")
		int32 GetSize();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User Array")
		bool HasNextPage();
};