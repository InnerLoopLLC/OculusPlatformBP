// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_UserOptions.generated.h"

// --------------------
// OVR_UserOptions.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_UserOptions : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrUserOptions* ovrUserOptionsHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|User Options", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", DeprecatedFunction, DeprecationMessage = "Create an OBP_UserOptionsStruct instead."))
		static UOBP_UserOptions* CreateUserOptions(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|User Options", meta = (DeprecatedFunction, DeprecationMessage = "Create an OBP_UserOptionsStruct instead."))
		void DestroyUserOptions();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|User Options", meta = (DeprecatedFunction, DeprecationMessage = "Create an OBP_UserOptionsStruct instead."))
		void SetMaxUsers(int32 MaxUsers);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|User Options", meta = (DeprecatedFunction, DeprecationMessage = "Create an OBP_UserOptionsStruct instead."))
		void AddServiceProvider(EOBP_ServiceProvider ServiceProvider);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|User Options", meta = (DeprecatedFunction, DeprecationMessage = "Create an OBP_UserOptionsStruct instead."))
		void ClearServiceProviders();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|User Options", meta = (DeprecatedFunction, DeprecationMessage = "Create an OBP_UserOptionsStruct instead."))
		void SetTimeWindow(EOBP_TimeWindow TimeWindow);
};