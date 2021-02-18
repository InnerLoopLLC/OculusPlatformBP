// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_LanguagePackInfo.generated.h"

// --------------------
// OVR_LanguagePackInfo.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_LanguagePackInfo : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

#if PLATFORM_MINOR_VERSION >= 28
	ovrLanguagePackInfo* ovrLanguagePackInfoHandle;
#endif

	/* Language Pack Info requires OculusPlatfromSDK 1.28 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Language Pack|Language Pack Info")
		FString GetEnglishName();

	/* Language Pack Info requires OculusPlatfromSDK 1.28 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Language Pack|Language Pack Info")
		FString GetNativeName();

	/* Language Pack Info requires OculusPlatfromSDK 1.28 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Language Pack|Language Pack Info")
		FString GetTag();
};