// OculusPlatformBP plugin by InnerLoop LLC 2020

//#pragma once

//#include "OculusPlatformBP.h"
//#include "OBP_Requests_Challenges.h"
//#include "OBP_Requests_Deprecated.generated.h"

// --------------------
//	THIS FILE CONSISTS OF DEPRECATED FUNCTIONS ONLY!
//	These allow projects that have not yet been updated to open without crashing. Mostly these are functions which have been moved and renamed.
//	This will all be deleted in a future update.
//
//  Deprecated function left here, but commented out, as an example so I don't forget how to set it up next time.
// --------------------

//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChallenges_Create, UOBP_Challenge*, Challenge);

// --------------------
// OVR_Requests_Deprecated.h
// --------------------

//UCLASS(BlueprintType)
//class OCULUSPLATFORMBP_API UOBP_Challenges_Create : public UBlueprintAsyncActionBase
//{
//
//	GENERATED_UCLASS_BODY()
//
//public:
//
//	UPROPERTY(BlueprintAssignable)
//		FChallenges_Create OnSuccess;
//
//	UPROPERTY(BlueprintAssignable)
//		FChallenges_Create OnFailure;
//
//	/* DEPRECATED. Use server-to-server API call instead. */
//	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, 
//		DeprecationMessage = "This function has been deprecated! Use server-to-server API call instead.", 
//		BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
//		static UOBP_Challenges_Create* Create(UObject* WorldContextObject, FString LeaderboardName, FOBP_ChallengeOptionsStruct ChallengeOptions);
//
//	// UBlueprintAsyncActionBase interface
//	virtual void Activate() override;
//};