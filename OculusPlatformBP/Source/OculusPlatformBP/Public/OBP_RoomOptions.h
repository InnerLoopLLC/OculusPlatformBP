// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_RoomOptions.generated.h"

// --------------------
// OVR_RoomOptions.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_RoomOptions : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrRoomOptions* ovrRoomOptionsHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room Options", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_RoomOptions* CreateRoomOptions(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room Options")
		void DestroyRoomOptions();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room Options")
		void SetDataStoreString(FString Key, FString Value);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room Options")
		void ClearDataStore();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room Options")
		void SetExcludeRecentlyMet(bool Value);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room Options")
		void SetMaxUserResults(int32 Value);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room Options")
		void SetOrdering(EOBP_UserOrdering Order);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room Options")
		void SetRecentlyMetTimeWindow(EOBP_TimeWindow TimeWindow);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room Options")
		void SetRoomId(FString RoomId);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Room Options")
		void SetTurnOffUpdates(bool Value);
};