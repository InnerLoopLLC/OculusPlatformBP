#pragma once

#include "CoreGlobals.h"
#include "Kismet/GameplayStatics.h"
#include "OculusPlatformBPSettings.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogOculusPlatformBP, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class UOculusPlatformBPSettings : public UObject
{
	GENERATED_BODY()

public:

	// To access Oculus Platform features, this must be set as follows: `DefaultPlatformService=Oculus`.
	// This field updates both `DefaultEngine.ini` and `Android/AndroidEngine.ini`
	UPROPERTY(EditAnywhere, Category = "OnlineSubsystem")
		FString DefaultPlatformService;

	FString AndroidPlatformService;

	// OnlineSubsystemOculus must be enabled to use OculusPlatformBP nodes.
	UPROPERTY(EditAnywhere, Category = "OnlineSubsystemOculus")
		bool bEnabled = true;

	// The AppId corresponding to this Oculus Rift project.
	// Required for all Oculus Rift projects.
	UPROPERTY(EditAnywhere, Category = "OnlineSubsystemOculus")
		FString RiftAppId;

	// The AppId corresponding to this Oculus mobile project.
	// Required for all Oculus Quest project (including App Lab projects).
	UPROPERTY(EditAnywhere, Category = "OnlineSubsystemOculus")
		FString MobileAppId;

	// The OculusAppId is not preferred. It is provided as a fallback option if RiftAppId or MobileAppId fails.
	UPROPERTY(EditAnywhere, Category = "OnlineSubsystemOculus")
		FString OculusAppId;

	// Gets the config file settings in-game.
	UFUNCTION(BlueprintPure, Category = "OculusPlatformBP|OnlineSubsystemOculus")
		static void GetOculusPlatformSettings(bool& _IsEnabled, FString& _RiftAppId, FString& _MobileAppId, FString& _OculusAppId, FString& _DefaultPlatformService);

	void LoadSettings();

#if WITH_EDITOR
	void SaveSettings();
	bool ValidateSettings();

	// Called when any property is changed externally.
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif //WITH_EDITOR
};