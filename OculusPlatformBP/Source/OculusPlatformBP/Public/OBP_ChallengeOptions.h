// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_ChallengeOptions.generated.h"

// --------------------
// OVR_ChallengeOptions.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_ChallengeOptions : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

#if PLATFORM_MINOR_VERSION >= 51
	ovrChallengeOptions* ovrChallengeOptionsHandle;
#endif

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Options", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_ChallengeOptions* CreateChallengeOptions(UObject* WorldContextObject);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options")
		void DestroyChallengeOptions();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options")
		void SetDescription(FString Description);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options")
		void SetEndDate(int32 Value);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options")
		void SetIncludeActiveChallenges(bool bShouldInclude);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options")
		void SetIncludeFutureChallenges(bool bShouldInclude);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options")
		void SetIncludePastChallenges(bool bShouldInclude);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options")
		void SetLeaderboardName(FString LeaderboardName);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options")
		void SetStartDate(int32 Value);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options")
		void SetTitle(FString Title);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options")
		void SetViewerFilter(EOBP_ChallengeViewerFilter Filter);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options")
		void SetVisibility(EOBP_ChallengeVisibility Visibility);
};