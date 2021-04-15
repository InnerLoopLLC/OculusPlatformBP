// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_Destination.h"
#include "OBP_Leaderboard.generated.h"

// --------------------
// OVR_Leaderboard.h
// --------------------
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Leaderboard : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

#if PLATFORM_MINOR_VERSION >= 50
	ovrLeaderboard* ovrLeaderboardHandle;
#endif

	/* Requires OculusPlatfromSDK v18 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Leaderboard|Leaderboard")
		FString GetApiName();

	/* This method may return null. This indicates that the value is not present or that the curent app or user is not permitted to access it.
	Requires OculusPlatfromSDK v27 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Leaderboard|Leaderboard")
		UOBP_Destination* GetDestination();

	/* Requires OculusPlatfromSDK v27 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Leaderboard|Leaderboard")
		FString GetID();
};