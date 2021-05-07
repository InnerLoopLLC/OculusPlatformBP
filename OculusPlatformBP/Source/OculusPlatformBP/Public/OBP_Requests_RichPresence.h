// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_DestinationArray.h"
#include "OBP_Requests_RichPresence.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRichPresense_ClearRichPresence);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRichPresense_GetDestinations, const TArray<UOBP_Destination*>&, Destinations, UOBP_DestinationArray*, DestinationArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRichPresense_GetDestinationsArrayPage, const TArray<UOBP_Destination*>&, Destinations, UOBP_DestinationArray*, DestinationArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRichPresense_SetRichPresence);

// --------------------
// OVR_Requests_RichPresence.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_RichPresence_ClearRichPresence : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FRichPresense_ClearRichPresence OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRichPresense_ClearRichPresence OnFailure;

	/*Clear rich presence for running app
	Rich Presence requires OculusPlatfromSDK 1.39 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_RichPresence_ClearRichPresence* ClearRichPresence(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_RichPresence_GetDestinations : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FRichPresense_GetDestinations OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRichPresense_GetDestinations OnFailure;

	/*Gets all the destinations that the presence can be set to
	Requires OculusPlatfromSDK 1.41 or later*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_RichPresence_GetDestinations* GetDestinations(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_RichPresence_GetNextDestinationArrayPage : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_DestinationArray* DestinationArray;

	UPROPERTY(BlueprintAssignable)
		FRichPresense_GetDestinationsArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRichPresense_GetDestinationsArrayPage OnFailure;

	/*Get the next page of entries
	Requires OculusPlatfromSDK 1.41 or later*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_RichPresence_GetNextDestinationArrayPage* GetNextDestinationArrayPage(UObject* WorldContextObject, UOBP_DestinationArray* DestinationArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_RichPresence_SetRichPresence : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FOBP_RichPresenceOptionsStruct RichPresence;

	UPROPERTY(BlueprintAssignable)
		FRichPresense_SetRichPresence OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FRichPresense_SetRichPresence OnFailure;

	/*Set rich presence for running app
	Rich Presence requires OculusPlatfromSDK 1.39 or later
	NOTE: CurrentCapacity, MaxCapacity, StartTime, DeeplinkMessageOverride, and ExtraContext require OculusPlatformSDK 1.40 or later 
	NOTE: InstanceId requires OculusPlatformSDK v23 or later */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Rich Presence|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_RichPresence_SetRichPresence* SetRichPresence(UObject* WorldContextObject, FOBP_RichPresenceOptionsStruct RichPresence);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};