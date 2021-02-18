// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_ChallengeEntry.h"
#include "OBP_ChallengeEntryArray.generated.h"

// --------------------
// OVR_ChallengeEntryArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_ChallengeEntryArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

#if PLATFORM_MINOR_VERSION >= 51
	ovrChallengeEntryArray* ovrChallengeEntryArrayHandle;
#endif

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Challenges|Challenge Entry Array")
		UOBP_ChallengeEntry* GetElement(int32 Index);

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Entry Array")
		FString GetNextUrl();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Entry Array")
		FString GetPreviousUrl();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Entry Array")
		int32 GetSize();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Entry Array")
		int32 GetTotalCount();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Entry Array")
		bool HasNextPage();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge Entry Array")
		bool HasPreviousPage();
};