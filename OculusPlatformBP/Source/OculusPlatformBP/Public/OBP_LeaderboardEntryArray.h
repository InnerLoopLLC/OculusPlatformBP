// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_LeaderboardEntry.h"
#include "OBP_LeaderboardEntryArray.generated.h"

// --------------------
// OVR_LeaderboardEntryArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_LeaderboardEntryArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrLeaderboardEntryArray* ovrLeaderboardEntryArrayHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry Array")
		UOBP_LeaderboardEntry* GetElement(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry Array")
		FString GetNextUrl();
	
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry Array")
		FString GetPreviousUrl();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry Array")
		int32 GetSize();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry Array")
		int32 GetTotalCount();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry Array")
		bool HasNextPage();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Leaderboard|Leaderboard Entry Array")
		bool HasPreviousPage();
};