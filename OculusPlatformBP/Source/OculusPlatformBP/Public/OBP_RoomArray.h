// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_Room.h"
#include "OBP_RoomArray.generated.h"

// --------------------
// OVR_RoomArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_RoomArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrRoomArray* ovrRoomArrayHandle;

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room Array")
		UOBP_Room* GetElement(int32 Index);

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room Array")
		FString GetNextUrl();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room Array")
		int32 GetSize();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Room|Room Array")
		bool HasNextPage();
};