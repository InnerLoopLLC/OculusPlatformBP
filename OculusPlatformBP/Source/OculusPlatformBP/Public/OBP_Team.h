// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_UserArray.h"
#include "OBP_Team.generated.h"

// --------------------
// ovr_Team.h
// --------------------
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Team : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

#if PLATFORM_MINOR_VERSION >= 39
	ovrTeam* ovrTeamHandle;
#endif

	/* Teams require OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Team|Team")
		UOBP_UserArray* GetAssignedUsers();

	/* Teams require OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Team|Team")
		int32 GetMaxUsers();

	/* Teams require OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Team|Team")
		int32 GetMinUsers();

	/* Teams require OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Team|Team")
		FString GetName();
};