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
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", DeprecatedFunction, DeprecationMessage = "Create an OBP_ChallengeOptionsStruct instead."))
		static UOBP_ChallengeOptions* CreateChallengeOptions(UObject* WorldContextObject);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options", meta = (DeprecatedFunction, DeprecationMessage = "Create an OBP_ChallengeOptionsStruct instead."))
		void DestroyChallengeOptions();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options", meta = (DeprecatedFunction, DeprecationMessage = "Create an OBP_ChallengeOptionsStruct instead."))
		void SetDescription(FString Description);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options", meta = (DeprecatedFunction, DeprecationMessage = "Create an OBP_ChallengeOptionsStruct instead."))
		void SetEndDate(int32 Value);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options", meta = (DeprecatedFunction, DeprecationMessage = "Create an OBP_ChallengeOptionsStruct instead."))
		void SetIncludeActiveChallenges(bool bShouldInclude);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options", meta = (DeprecatedFunction, DeprecationMessage = "Create an OBP_ChallengeOptionsStruct instead."))
		void SetIncludeFutureChallenges(bool bShouldInclude);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options", meta = (DeprecatedFunction, DeprecationMessage = "Create an OBP_ChallengeOptionsStruct instead."))
		void SetIncludePastChallenges(bool bShouldInclude);

	/* Optional: Only find challenges belonging to this leaderboard.
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options", meta = (DeprecatedFunction, DeprecationMessage = "Create an OBP_ChallengeOptionsStruct instead."))
		void SetLeaderboardName(FString LeaderboardName);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options", meta = (DeprecatedFunction, DeprecationMessage = "Create an OBP_ChallengeOptionsStruct instead."))
		void SetStartDate(int32 Value);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options", meta = (DeprecatedFunction, DeprecationMessage = "Create an OBP_ChallengeOptionsStruct instead."))
		void SetTitle(FString Title);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options", meta = (DeprecatedFunction, DeprecationMessage = "Create an OBP_ChallengeOptionsStruct instead."))
		void SetViewerFilter(EOBP_ChallengeViewerFilter Filter);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Options", meta = (DeprecatedFunction, DeprecationMessage = "Create an OBP_ChallengeOptionsStruct instead."))
		void SetVisibility(EOBP_ChallengeVisibility Visibility);
};