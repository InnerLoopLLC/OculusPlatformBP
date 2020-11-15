// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_RichPresenceOptions.generated.h"

// --------------------
// OVR_RichPresenceOptions.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_RichPresenceOptions : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

#if PLATFORM_MINOR_VERSION >= 39
	ovrRichPresenceOptions* ovrRichPresenceOptionsHandle;
#endif

	/* Rich Presence requires OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_RichPresenceOptions* CreateRichPresenceOptions(UObject* WorldContextObject);

	/* Rich Presence requires OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void DestroyRichPresenceOptions();

	/* Rich Presence requires OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetApiName(const FString RichPresenceApiName);

	/* Rich Presence requires OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetArgsString(const FString RichPresenceApiKey, const FString RichPresenceApiValue);

	/* Rich Presence requires OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void ClearArgs();

	/* Requires OculusPlatfromSDK 1.40 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetCurrentCapacity(const int32 RichPresenceCurrentCapacity);

	/* Requires OculusPlatfromSDK 1.40 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetDeeplinkMessageOverride(const FString RichPresenceDeeplinkMessage);

	/* Rich Presence requires OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetEndTime(const int32 RichPresenceEndTime);

	/* Requires OculusPlatfromSDK 1.40 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetExtraContext(EOBP_RichPresenceExtraContext RichPresenceExtraContext);

	/* Rich Presence requires OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetIsIdle(const bool RichPresenceIsIdle);

	/* Rich Presence requires OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetIsJoinable(const bool RichPresenceIsJoinable);

	/* Rich Presence requires OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetJoinableId(const FString RichPresenceJoinableId);

	/* Requires OculusPlatfromSDK 1.40 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetMaxCapacity(const int32 RichPresenceMaxCapacity);

	/* Requires OculusPlatfromSDK 1.40 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetStartTime(const int32 RichPresenceStartTime);
};