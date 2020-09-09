// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBPDestination.generated.h"

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Destination : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	// --------------------
	// OVR_Destination.h (https://developer.oculus.com/reference/platform/v19/o_v_r_destination_8h)
	// --------------------

#if PLATFORM_MINOR_VERSION >= 41
	ovrDestination* ovrDestinationHandle;
#endif

	/*Pass it into ovr_RichPresenceOptions_SetApiName() when calling ovr_RichPresence_Set() to set this user's rich presence
	Requires OculusPlatfromSDK 1.41 or later*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Destination")
		FString GetApiName();

	/*The information that will be in ovr_LaunchDetails_GetDeeplinkMessage() when a user enters via a deeplink. Alternatively will be in ovr_User_GetPresenceDeeplinkMessage() if the rich presence is set for the user.
	Requires OculusPlatfromSDK 1.41 or later*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Destination")
		FString GetDeeplinkMessage();

	/*Requires OculusPlatfromSDK 1.41 or later*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Destination")
		FString GetDisplayName();
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_DestinationArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	// --------------------
	// OVR_DestinationArray.h (https://developer.oculus.com/reference/platform/v19/o_v_r_destination_array_8h/)
	// --------------------

#if PLATFORM_MINOR_VERSION >= 41
	ovrDestinationArray* ovrDestinationArrayHandle;
#endif

	/*Pass it into ovr_RichPresenceOptions_SetApiName() when calling ovr_RichPresence_Set() to set this user's rich presence
	Requires OculusPlatfromSDK 1.41 or later*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Destination|Array")
		UOBP_Destination* GetElement(int Index);

	/*The information that will be in ovr_LaunchDetails_GetDeeplinkMessage() when a user enters via a deeplink. Alternatively will be in ovr_User_GetPresenceDeeplinkMessage() if the rich presence is set for the user.
	Requires OculusPlatfromSDK 1.41 or later*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Destination|Array")
		FString GetNextUrl();

	/*Requires OculusPlatfromSDK 1.41 or later*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Destination|Array")
		int GetSize();

	/*Requires OculusPlatfromSDK 1.41 or later*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Destination|Array")
		bool HasNextPage();
};