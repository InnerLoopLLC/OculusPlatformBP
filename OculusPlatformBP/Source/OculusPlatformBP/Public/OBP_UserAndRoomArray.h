// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_UserAndRoom.h"
#include "OBP_UserAndRoomArray.generated.h"

// --------------------
// OVR_UserAndRoomArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_UserAndRoomArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrUserAndRoomArray* ovrUserAndRoomArrayHandle;

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User And Room Array")
		UOBP_UserAndRoom* GetElement(int32 Index);

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User And Room Array")
		FString GetNextUrl();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User And Room Array")
		int32 GetSize();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|User|User And Room Array")
		bool HasNextPage();
};