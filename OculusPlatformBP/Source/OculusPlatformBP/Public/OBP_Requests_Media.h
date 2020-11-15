// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_Requests_Media.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMedia_ShareToFacebook, EOBP_ShareMediaStatus, ShareMediaStatus);

// --------------------
// ovr_Requests_Media.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Media_ShareToFacebook : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString PostTextSuggestion;
	FString FilePath;
	EOBP_MediaContentType ContentType;

	UPROPERTY(BlueprintAssignable)
		FMedia_ShareToFacebook OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FMedia_ShareToFacebook OnFailure;

	/* Launch the Share to Facebook modal via a deeplink to Home on Gear VR, allowing users to share local media files to Facebook. 
	Accepts a postTextSuggestion string for the default text of the Facebook post. 
	Requires a filePath string as the path to the image to be shared to Facebook. This image should be located in your app's internal storage directory. 
	Requires a contentType indicating the type of media to be shared (only 'photo' is currently supported.) */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Media Sharing|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_Media_ShareToFacebook* ShareToFacebook(UObject* WorldContextObject, FString PostTextSuggestion, FString FilePath, EOBP_MediaContentType ContentType);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};