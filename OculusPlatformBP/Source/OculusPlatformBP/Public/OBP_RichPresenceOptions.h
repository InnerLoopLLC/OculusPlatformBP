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

	/* This the unique API Name that refers to an in-app destination
	Rich Presence requires OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetApiName(const FString RichPresenceApiName);

	/* DEPRECATED: Unused (v23)
	Rich Presence requires OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options", meta = (DeprecatedFunction, DeprecationMessage = "DEPRECATED: Unused (v23)"))
		void SetArgsString(const FString RichPresenceApiKey, const FString RichPresenceApiValue);

	/* Rich Presence requires OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void ClearArgs();

	/* The current amount of users that have joined this user's squad/team/game/match etc.
	Requires OculusPlatfromSDK 1.40 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetCurrentCapacity(const int32 RichPresenceCurrentCapacity);

	/* Optionally passed in to use a different deeplink message than the one defined in the api_name
	Requires OculusPlatfromSDK 1.40 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetDeeplinkMessageOverride(const FString RichPresenceDeeplinkMessage);

	/* The time the current match/game/round etc. ends
	Rich Presence requires OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetEndTime(const int32 RichPresenceEndTime);

	/* Requires OculusPlatfromSDK 1.40 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetExtraContext(EOBP_RichPresenceExtraContext RichPresenceExtraContext);

	/* Users reported with the same instance ID will be considered to be together and could interact with each other 
	Requires OculusPlatfromSDK v23 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetInstanceId(const FString Value);

	/* Set whether or not the person is shown as active or idle
	Rich Presence requires OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetIsIdle(const bool RichPresenceIsIdle);

	/* Set whether or not the person is shown as joinable or not to others
	Rich Presence requires OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetIsJoinable(const bool RichPresenceIsJoinable);

	/* DEPRECATED: Unused (v23)
	Rich Presence requires OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options", meta = (DeprecatedFunction, DeprecationMessage = "DEPRECATED: Unused (v23)"))
		void SetJoinableId(const FString RichPresenceJoinableId);

	/* The maximum that can join this user
	Requires OculusPlatfromSDK 1.40 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetMaxCapacity(const int32 RichPresenceMaxCapacity);

	/* The time the current match/game/round etc. started
	Requires OculusPlatfromSDK 1.40 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options")
		void SetStartTime(const int32 RichPresenceStartTime);
};