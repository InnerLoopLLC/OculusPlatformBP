// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_Challenge.h"
#include "OBP_ChallengeArray.generated.h"

// --------------------
// OVR_ChallengeArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_ChallengeArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

#if PLATFORM_MINOR_VERSION >= 51
	ovrChallengeArray* ovrChallengeArrayHandle;
#endif

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Array")
		UOBP_Challenge* GetElement(int32 Index);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Array")
		FString GetNextUrl();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Array")
		FString GetPreviousUrl();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Array")
		int32 GetSize();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Array")
		int32 GetTotalCount();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Array")
		bool HasNextPage();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Array")
		bool HasPreviousPage();
};