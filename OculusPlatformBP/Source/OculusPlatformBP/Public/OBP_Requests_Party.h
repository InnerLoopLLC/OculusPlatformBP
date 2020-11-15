// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_Party.h"
#include "OBP_Requests_Party.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FParty_GetCurrent, UOBP_Party*, Party);

// --------------------
// ovr_Requests_Party.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Party_GetCurrent : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FParty_GetCurrent OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FParty_GetCurrent OnFailure;

	/* Load the party the current user is in. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Party|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Party_GetCurrent* GetCurrentParty(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};