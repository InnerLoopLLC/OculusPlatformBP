// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_UserArray.h"
#include "OBP_Leaderboard.h"
#include "OBP_Challenge.generated.h"

// --------------------
// OVR_Challenge.h
// --------------------
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Challenge : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

#if PLATFORM_MINOR_VERSION >= 51
	ovrChallenge* ovrChallengeHandle;
#endif

	/* Was this challenge created by a user or the app developer.
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge")
		EOBP_ChallengeCreationType GetCreationType();

	/* A displayable string of the challenge's description.
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge")
		FString GetDescription();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge")
		UOBP_UserArray* GetInvitedUsers();

	/* The leaderboard associated with this challenge.
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge")
		UOBP_Leaderboard* GetLeaderboard();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge")
		UOBP_UserArray* GetParticipants();

	/* A displayable string of the challenge's title.
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge")
		FString GetTitle();

	/* A enum that specify who can see this challenge.
	Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge")
		EOBP_ChallengeVisibility GetVisibility();
	
	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge")
		int32 GetEndDate();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge")
		FString GetID();

	/* Challenges require OculusPlatfromSDK v19 or later */
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Challenges|Challenge")
		int32 GetStartDate();
};