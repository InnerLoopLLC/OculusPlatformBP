// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBPRichPresence.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FClearRichPresence);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetDestinations, UOBP_DestinationArray*, DestinationArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetDestinationsArrayPage, UOBP_DestinationArray*, DestinationArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSetRichPresence);

// --------------------
// OVR_Requests_RichPresence.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_ClearRichPresence : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FClearRichPresence OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FClearRichPresence OnFailure;

	/*Clear rich presence for running app*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_ClearRichPresence* ClearRichPresence(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetDestinations : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetDestinations OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetDestinations OnFailure;

	/*Gets all the destinations that the presence can be set to
	Requires OculusPlatfromSDK 1.41 or later*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
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
		FGetDestinationsArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetDestinationsArrayPage OnFailure;

	/*Get the next page of entries
	Requires OculusPlatfromSDK 1.41 or later*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetNextDestinationArrayPage* GetNextDestinationArrayPage(UObject* WorldContextObject, UOBP_DestinationArray* DestinationArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_SetRichPresence : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	ovrRichPresenceOptions* OvrRichPresenceOptions = ovr_RichPresenceOptions_Create();
	
	UPROPERTY(BlueprintAssignable)
		FSetRichPresence OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FSetRichPresence OnFailure;

	/*Set rich presence for running app*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_SetRichPresence* SetRichPresence(UObject* WorldContextObject, UOBP_RichPresence* RichPresenceObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

// --------------------
// OVR_RichPresence.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_RichPresence : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

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
		void SetMaxCapacity(const int32 RichPresenceMaxCapacity);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence")
		void SetStartTime(const int64 RichPresenceStartTime);
};