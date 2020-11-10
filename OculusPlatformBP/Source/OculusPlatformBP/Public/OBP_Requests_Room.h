// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_Room.h"
#include "OBP_Requests_Room.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRoomGet, UOBP_Room*, Room);

// --------------------
// ovr_Requests_Room.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Room_Get : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString RoomID;

	UPROPERTY(BlueprintAssignable)
		FRoomGet OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRoomGet OnFailure;

	/* Allows arbitrary rooms for the application to be loaded. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Room|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Room_Get* GetRoom(UObject* WorldContextObject, FString RoomID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};