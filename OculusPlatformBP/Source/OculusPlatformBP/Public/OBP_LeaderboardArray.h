// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_Leaderboard.h"
#include "OBP_LeaderboardArray.generated.h"

// --------------------
// OVR_LeaderboardArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_LeaderboardArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

#if PLATFORM_MINOR_VERSION >= 59
	ovrLeaderboardArray* ovrLeaderboardArrayHandle;
#endif

	/* Requires OculusPlatfromSDK v27 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Leaderboard|Leaderboard Array")
		UOBP_Leaderboard* GetElement(int32 Index);

	/* Requires OculusPlatfromSDK v27 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Leaderboard|Leaderboard Array")
		FString GetNextUrl();

	/* Requires OculusPlatfromSDK v27 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Leaderboard|Leaderboard Array")
		int32 GetSize();

	/* Requires OculusPlatfromSDK v27 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Leaderboard|Leaderboard Array")
		bool HasNextPage();
};