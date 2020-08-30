// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBPRichPresence.generated.h"

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBPRichPresence : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	// --------------------
	// OVR_RichPresence.h (https://developer.oculus.com/reference/platform/v19/o_v_r_rich_presence_options_8h)
	// --------------------

	ovrRichPresenceOptions* OvrRichPresenceOptions = ovr_RichPresenceOptions_Create();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Rich Presence", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBPRichPresence* CreateRichPresenceOptions(UObject* WorldContextObject);
	
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void DestroyRichPresenceOptions();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetApiName(const FString RichPresenceApiName);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetArgsString(const FString RichPresenceApiKey, const FString RichPresenceApiValue);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void ClearArgs();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetCurrentCapacity(const int32 RichPresenceCurrentCapacity);
	
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetDeeplinkMessageOverride(const FString RichPresenceDeeplinkMessage);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetEndTime(const int64 RichPresenceEndTime);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetExtraContext(EOBPRichPresenceExtraContext RichPresenceExtraContext);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetIsIdle(const bool RichPresenceIsIdle);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetIsJoinable(const bool RichPresenceIsJoinable);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetJoinableId(const FString RichPresenceJoinableId);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetMaxCapacity(const int RichPresenceMaxCapacity);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetStartTime(const int64 RichPresenceStartTime);

	/*/ --------------------
	// OVR_RichPresenceExtraContext.h (https://developer.oculus.com/reference/platform/v19/o_v_r_rich_presence_extra_context_8h/)
	// --------------------

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		static FString ExtraContext_ToString(EOBPRichPresenceExtraContext RichPresenceExtraContext);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		static EOBPRichPresenceExtraContext ExtraContext_FromString(FString RichPresenceExtraContextString);
	*/

	// --------------------
	// OVR_RichPresenceRequests.h (https://developer.oculus.com/reference/platform/v19/o_v_r_requests_rich_presence_8h)
	// --------------------

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void ClearRichPresence();

	// requires OculusPlatfromSDK v12 (1.44) or later
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void GetDestinations();

	// requires OculusPlatfromSDK v12 (1.44) or later
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void GetNextDestinationArrayPage();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetRichPresence();
};