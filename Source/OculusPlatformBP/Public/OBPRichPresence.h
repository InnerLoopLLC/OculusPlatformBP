// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"

#include "CoreGlobals.h"
#include "CoreMinimal.h"
#include "EngineGlobals.h"
#include "Engine/Engine.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/ObjectMacros.h"

#include "Online.h"
#include "OnlineSubsystem.h"
#include "OnlineSubsystemOculus.h"

#include <ThirdParty\Oculus\LibOVRPlatform\LibOVRPlatform\include\OVR_Platform.h>

#include "OBPRichPresence.generated.h"

UENUM(BlueprintType)
enum class EOBPRichPresenceExtraContext : uint8
{
	Unknown,
	None,
	CurrentCapacity,
	StartedAgo,
	EndingIn,
	LookingForMatch
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBPRichPresence : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	// --------------------
	// Rich Presense Object Properties
	// --------------------

	ovrRichPresenceOptions* OvrRichPresenceOptions = ovr_RichPresenceOptions_Create();

	// --------------------
	// Rich Presense Functions (https://developer.oculus.com/reference/platform/v19/o_v_r_rich_presence_options_8h)
	// --------------------

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Rich Presence", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBPRichPresence* CreateRichPresenceOptions(UObject* WorldContextObject);
	
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void DestroyRichPresenseOptions();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetApiName(const FString RichPresenseApiName);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetArgsString(const FString RichPresenseApiKey, const FString RichPresenseApiValue);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void ClearArgs();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetCurrentCapacity(const int32 RichPresenseCurrentCapacity);
	
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetDeeplinkMessageOverride(const FString RichPresenseDeeplinkMessage);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetEndTime(const int64 RichPresenseEndTime);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetExtraContext(EOBPRichPresenceExtraContext RichPresenceExtraContext);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetIsIdle(const bool RichPresenseIsIdle);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetIsJoinable(const bool RichPresenseIsJoinable);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetJoinableId(const FString RichPresenseJoinableId);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetMaxCapacity(const int RichPresenseMaxCapacity);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetStartTime(const int64 RichPresenseStartTime);

	// --------------------
	// Rich Presense Extra Context (https://developer.oculus.com/reference/platform/v19/o_v_r_rich_presence_extra_context_8h/)
	// --------------------

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		static FString ExtraContext_ToString(EOBPRichPresenceExtraContext RichPresenceExtraContext);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		static EOBPRichPresenceExtraContext ExtraContext_FromString(FString RichPresenceExtraContextString);

	// --------------------
	// Rich Presense Requests (https://developer.oculus.com/reference/platform/v19/o_v_r_requests_rich_presence_8h)
	// --------------------

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void ClearRichPresence();

	// requires OculusPlatfromSDK v12 (1.44) or later; default UE4 distribution = 1.40
#if PLATFORM_MINOR_VERSION >= 44
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void GetDestinations();
#endif

	// requires OculusPlatfromSDK v12 (1.44) or later; default UE4 distribution = 1.40
#if PLATFORM_MINOR_VERSION >= 44
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void GetNextDestinationArrayPage();
#endif

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetRichPresence();
};