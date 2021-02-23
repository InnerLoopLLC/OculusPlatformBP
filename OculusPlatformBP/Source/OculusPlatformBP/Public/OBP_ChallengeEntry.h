// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_User.h"
#include "OBP_ChallengeEntry.generated.h"

// --------------------
// OVR_ChallengeEntry.h
// --------------------
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_ChallengeEntry : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

#if PLATFORM_MINOR_VERSION >= 51
	ovrChallengeEntry* ovrChallengeEntryHandle;
#endif

	/* Challenges require OculusPlatfromSDK v19 or later 
	GetDisplayScore() requires OculusPlatformSDK v25 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Entry")
		FString GetDisplayScore();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Entry")
		FString GetExtraData();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Entry")
		int32 GetExtraDataLength();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Entry")
		int32 GetRank();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Entry")
		int32 GetScore();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Entry")
		int32 GetTimestamp();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Entry")
		UOBP_User* GetUser();
};