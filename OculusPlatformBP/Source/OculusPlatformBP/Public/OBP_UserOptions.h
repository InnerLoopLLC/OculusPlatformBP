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

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User Options", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		UOBP_UserOptions* CreateUserOptions();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|User Options")
		void DestroyUserOptions();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|User Options")
		void SetMaxUsers(int32 MaxUsers);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|User Options")
		void AddServiceProvider(EOBP_ServiceProvider ServiceProvider);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|User Options")
		void ClearServiceProviders();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|User|User Options")
		void SetTimeWindow(EOBP_TimeWindow TimeWindow);
};