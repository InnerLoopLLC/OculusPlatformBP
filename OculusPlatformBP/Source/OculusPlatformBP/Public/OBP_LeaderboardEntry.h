// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_User.h"
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

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry")
		FString GetExtraData();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry")
		int32 GetExtraDataLength();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry")
		int32 GetRank();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry")
		int32 GetScore();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry")
		int32 GetTimestamp();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry")
		UOBP_User* GetUser();
};