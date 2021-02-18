// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_Destination.h"
#include "OBP_DestinationArray.generated.h"

// --------------------
// OVR_DestinationArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_DestinationArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

#if PLATFORM_MINOR_VERSION >= 41
	ovrDestinationArray* ovrDestinationArrayHandle;
#endif

	/*Pass it into ovr_RichPresenceOptions_SetApiName() when calling ovr_RichPresence_Set() to set this user's rich presence
	Requires OculusPlatfromSDK 1.41 or later*/
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Destination|Destination Array")
		UOBP_Destination* GetElement(int32 Index);

	/*The information that will be in ovr_LaunchDetails_GetDeeplinkMessage() when a user enters via a deeplink. Alternatively will be in ovr_User_GetPresenceDeeplinkMessage() if the rich presence is set for the user.
	Requires OculusPlatfromSDK 1.41 or later*/
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Destination|Destination Array")
		FString GetNextUrl();

	/*Requires OculusPlatfromSDK 1.41 or later*/
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Destination|Destination Array")
		int32 GetSize();

	/*Requires OculusPlatfromSDK 1.41 or later*/
	UFUNCTION(BlueprintPure, Category = "Oculus Platform BP|Destination|Destination Array")
		bool HasNextPage();
};