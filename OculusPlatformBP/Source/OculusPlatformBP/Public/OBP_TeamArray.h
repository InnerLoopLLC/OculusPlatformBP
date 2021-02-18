// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_Team.h"
#include "OBP_TeamArray.generated.h"

// --------------------
// OVR_TeamArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_TeamArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

#if PLATFORM_MINOR_VERSION >= 39
	ovrTeamArray* ovrTeamArrayHandle;
#endif

	/* Teams require OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Team|Team Array")
		UOBP_Team* GetElement(int32 Index);

	/* Teams require OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Team|Team Array")
		int32 GetSize();
};