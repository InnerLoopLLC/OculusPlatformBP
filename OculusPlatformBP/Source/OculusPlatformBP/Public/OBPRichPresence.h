// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBPRichPresence.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGetDestinations, UOBP_DestinationArray*, DestinationArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGetDestinationsArrayPage, UOBP_DestinationArray*, DestinationArray);

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetDestinations : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FOnGetDestinations OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FOnGetDestinations OnFailure;

	/*Gets all the destinations that the presence can be set to
	Requires OculusPlatfromSDK 1.41 or later*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetDestinations* GetDestinations(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetNextDestinationArrayPage : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FOnGetDestinationsArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FOnGetDestinationsArrayPage OnFailure;

	/*Get the next page of entries
	Requires OculusPlatfromSDK 1.41 or later*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetNextDestinationArrayPage* GetNextDestinationArrayPage(UObject* WorldContextObject, UOBP_DestinationArray* DestinationArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_RichPresence : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	// --------------------
	// OVR_RichPresence.h (https://developer.oculus.com/reference/platform/v19/o_v_r_rich_presence_options_8h)
	// --------------------

	ovrRichPresenceOptions* OvrRichPresenceOptions = ovr_RichPresenceOptions_Create();

	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Rich Presence", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_RichPresence* CreateRichPresenceOptions(UObject* WorldContextObject);
	
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
		void SetExtraContext(EOBP_RichPresenceExtraContext RichPresenceExtraContext);

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

	// --------------------
	// OVR_RichPresenceExtraContext.h (https://developer.oculus.com/reference/platform/v19/o_v_r_rich_presence_extra_context_8h/)
	// --------------------
	/*
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		static FString ExtraContext_ToString(EOBP_RichPresenceExtraContext RichPresenceExtraContext);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		static EOBP_RichPresenceExtraContext ExtraContext_FromString(FString RichPresenceExtraContextString);
	*/

	// --------------------
	// OVR_RichPresenceRequests.h (https://developer.oculus.com/reference/platform/v19/o_v_r_requests_rich_presence_8h)
	// --------------------

	/*Clear rich presence for running app*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void ClearRichPresence();

	/*Set rich presence for running app*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetRichPresence();
};