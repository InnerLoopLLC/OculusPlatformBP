// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_User.h"
#include "OBP_SupplementaryMetric.h"
#include "OBP_LeaderboardEntry.generated.h"

// --------------------
// OVR_LeaderboardEntry.h
// --------------------
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_LeaderboardEntry : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrLeaderboardEntry* ovrLeaderboardEntryHandle;

	/* Requires OculusPlatformSDK v25 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry")
		FString GetDisplayScore();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry")
		FString GetExtraData();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry")
		int32 GetExtraDataLength();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry")
		int32 GetRank();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry")
		int32 GetScore();

	/* This method may return null. This indicates that the value is not present or that the curent app or user is not permitted to access it.
	Requires OculusPlatformSDK v25 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry")
		UOBP_SupplementaryMetric* GetSupplementaryMetric();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry")
		int32 GetTimestamp();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry")
		UOBP_User* GetUser();
};