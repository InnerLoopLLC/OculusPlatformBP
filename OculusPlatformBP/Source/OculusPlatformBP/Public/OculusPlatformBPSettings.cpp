#include "OculusPlatformBPSettings.h"

DEFINE_LOG_CATEGORY(LogOculusPlatformBP);

void UOculusPlatformBPSettings::GetOculusPlatformSettings(bool& _bEnabled, FString& _RiftAppId, FString& _MobileAppId, FString& _OculusAppId, FString& _DefaultPlatformService)
{
	UOculusPlatformBPSettings* OculusPlatformBPSettings = GetMutableDefault<UOculusPlatformBPSettings>();
	
	_bEnabled = OculusPlatformBPSettings->bEnabled;
	_RiftAppId = OculusPlatformBPSettings->RiftAppId;
	_MobileAppId = OculusPlatformBPSettings->MobileAppId;
	_OculusAppId = OculusPlatformBPSettings->OculusAppId;
	_DefaultPlatformService = OculusPlatformBPSettings->DefaultPlatformService;
}

void UOculusPlatformBPSettings::LoadSettings()
{
	// Get values from config files.
	bool bDidGetbEnabled = GConfig->GetBool(TEXT("OnlineSubsystemOculus"), TEXT("bEnabled"), bEnabled, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
	bool bDidGetRiftAppId = GConfig->GetString(TEXT("OnlineSubsystemOculus"), TEXT("RiftAppId"), RiftAppId, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
	bool bDidGetMobileAppId = GConfig->GetString(TEXT("OnlineSubsystemOculus"), TEXT("MobileAppId"), MobileAppId, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
	bool bDidGetOculusAppId = GConfig->GetString(TEXT("OnlineSubsystemOculus"), TEXT("OculusAppId"), OculusAppId, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
	bool bDidGetDefaultPlatformService = GConfig->GetString(TEXT("OnlineSubsystem"), TEXT("DefaultPlatformService"), DefaultPlatformService, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
	bool bDidGetAndroidPlatformService = GConfig->GetString(TEXT("OnlineSubsystem"), TEXT("DefaultPlatformService"), AndroidPlatformService, FPaths::ProjectDir() + "Config/Android/AndroidEngine.ini");

#if WITH_EDITOR
	// Validate settings and flag if values need to be updated.
	bool bShouldForceSaveSettings = ValidateSettings();

	// Print values to logs, but only in editor. These values shouldn't be end-user accessible.
	UE_LOG(LogOculusPlatformBP, Log, TEXT("DefaultEngine.ini->bEnabled = %s"), bEnabled ? TEXT("True") : TEXT("False"));
	UE_LOG(LogOculusPlatformBP, Log, TEXT("DefaultEngine.ini->RiftAppId = %s"), *RiftAppId);
	UE_LOG(LogOculusPlatformBP, Log, TEXT("DefaultEngine.ini->MobileAppId = %s"), *MobileAppId);
	UE_LOG(LogOculusPlatformBP, Log, TEXT("DefaultEngine.ini->OculusAppId = %s"), *OculusAppId);
	UE_LOG(LogOculusPlatformBP, Log, TEXT("DefaultEngine.ini->DefaultPlatformService = %s"), *DefaultPlatformService);
	UE_LOG(LogOculusPlatformBP, Log, TEXT("AndroidEngine.ini->DefaultPlatformService = %s"), *AndroidPlatformService);

	// Make sure all values exist. If they don't, make them. Force save to update settings if data did not validate.
	if (!bDidGetbEnabled || !bDidGetRiftAppId || !bDidGetMobileAppId || !bDidGetOculusAppId || !bDidGetDefaultPlatformService || !bDidGetAndroidPlatformService || bShouldForceSaveSettings)
	{
		SaveSettings();
	}
#endif //WITH_EDITOR
}

#if WITH_EDITOR
void UOculusPlatformBPSettings::SaveSettings()
{
	// Copy values to config files, using DefaultPlatformService value for both, to ensure they're always the same.
	GConfig->SetBool(TEXT("OnlineSubsystemOculus"), TEXT("bEnabled"), bEnabled, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
	GConfig->SetString(TEXT("OnlineSubsystemOculus"), TEXT("RiftAppId"), *RiftAppId, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
	GConfig->SetString(TEXT("OnlineSubsystemOculus"), TEXT("MobileAppId"), *MobileAppId, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
	GConfig->SetString(TEXT("OnlineSubsystemOculus"), TEXT("OculusAppId"), *OculusAppId, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
	GConfig->SetString(TEXT("OnlineSubsystem"), TEXT("DefaultPlatformService"), *DefaultPlatformService, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
	GConfig->SetString(TEXT("OnlineSubsystem"), TEXT("DefaultPlatformService"), *DefaultPlatformService, FPaths::ProjectDir() + "Config/Android/AndroidEngine.ini");

	GConfig->Flush(false, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
	GConfig->Flush(false, FPaths::ProjectDir() + "Config/Android/AndroidEngine.ini");

	UE_LOG(LogOculusPlatformBP, Log, TEXT("Finished saving values to config files."));
}
#endif //WITH_EDITOR

#if WITH_EDITOR
bool UOculusPlatformBPSettings::ValidateSettings()
{
	bool bShouldForceSaveSettings = false;

	// Don't validate settings if the subsystem is disabled. Ignore it to prevent log spam in projects that aren't built for the Oculus platform.
	if (bEnabled)
	{
		// Ensure the DefaultPlatformService is the same for both files (`DefaultEngine.ini` and `Android/AndroidEngine.ini`).
		if (AndroidPlatformService != DefaultPlatformService)
		{
			AndroidPlatformService = DefaultPlatformService;
			UE_LOG(LogOculusPlatformBP, Warning, TEXT("AndroidEngine.ini->DefaultPlatformService and DefaultEngine.ini->DefaultPlatformService had conflicting values. Updated values to match DefaultEngine.ini."));
			bShouldForceSaveSettings = true;
		}

		// Warn if DefaultPlatformService is not set to Oculus, but still allow it in case the app uses multiple OSS.
		if (DefaultPlatformService != "Oculus")
		{
			UE_LOG(LogOculusPlatformBP, Warning, TEXT("OnlineSubsystemOculus is enabled, but DefaultPlatformService is NOT set to Oculus."));
		}

		// Check that AppIDs are the correct length.
		if (RiftAppId.Len() != 16)
		{
			if (RiftAppId == "")
			{
				UE_LOG(LogOculusPlatformBP, Warning, TEXT("RiftAppID is not configured. Please check configuration."));
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Error, TEXT("RiftAppID is not the correct number of digits (16). Please check configuration."));
			}
		}
		if (MobileAppId.Len() != 16)
		{
			if (MobileAppId == "")
			{
				UE_LOG(LogOculusPlatformBP, Warning, TEXT("MobileAppId is not configured. Please check configuration."));
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Error, TEXT("MobileAppId is not the correct number of digits (16). Please check configuration."));
			}
		}
		/* Don't warn about OculusAppId, as it's deprecated. 
		if (OculusAppId.Len() != 16)
		{
			if (OculusAppId == "")
			{
				UE_LOG(LogOculusPlatformBP, Warning, TEXT("OculusAppId is not configured. Please check configuration."));
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Error, TEXT("OculusAppId is not the correct number of digits (16). Please check configuration."));
			}
		}
		*/
	}

	return bShouldForceSaveSettings;
}
#endif //WITH_EDITOR

#if WITH_EDITOR
void UOculusPlatformBPSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	GConfig->Flush(true, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
	GConfig->Flush(true, FPaths::ProjectDir() + "Config/Android/AndroidEngine.ini");
	
	bool bEnabledFromConfig;
	FString RiftAppIdFromConfig;
	FString MobileAppIdFromConfig;
	FString OculusAppIdFromConfig;
	FString DefaultPlatformServiceFromConfig;
	FString AndroidPlatformServiceFromConfig;
	
	// Get values from config files so we can compare against them
	GConfig->GetBool(TEXT("OnlineSubsystemOculus"), TEXT("bEnabled"), bEnabledFromConfig, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
	GConfig->GetString(TEXT("OnlineSubsystemOculus"), TEXT("RiftAppId"), RiftAppIdFromConfig, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
	GConfig->GetString(TEXT("OnlineSubsystemOculus"), TEXT("MobileAppId"), MobileAppIdFromConfig, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
	GConfig->GetString(TEXT("OnlineSubsystemOculus"), TEXT("OculusAppId"), OculusAppIdFromConfig, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
	GConfig->GetString(TEXT("OnlineSubsystem"), TEXT("DefaultPlatformService"), DefaultPlatformServiceFromConfig, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
	GConfig->GetString(TEXT("OnlineSubsystem"), TEXT("DefaultPlatformService"), AndroidPlatformServiceFromConfig, FPaths::ProjectDir() + "Config/Android/AndroidEngine.ini");

	// Force these values to always be the same
	AndroidPlatformService = DefaultPlatformService;

	// Log what changed, in case we need to retrieve old values
	if (bEnabled != bEnabledFromConfig)
	{
		UE_LOG(LogOculusPlatformBP, Log, TEXT("Settings Property Changed: The previous value set in DefaultEngine.ini -> bEnabled = %s"), bEnabledFromConfig ? TEXT("True") : TEXT("False"));
		UE_LOG(LogOculusPlatformBP, Log, TEXT("Saving current value in OculusPlatformBPSettings to config file -> bEnabled = %s"), bEnabled ? TEXT("True") : TEXT("False"));
	}
	if (RiftAppId != RiftAppIdFromConfig)
	{
		UE_LOG(LogOculusPlatformBP, Log, TEXT("Settings Property Changed: The previous value set in DefaultEngine.ini -> RiftAppId = %s"), *RiftAppIdFromConfig);
		UE_LOG(LogOculusPlatformBP, Log, TEXT("Saving current value in OculusPlatformBPSettings to config file -> RiftAppId = %s"), *RiftAppId);
	}
	if (MobileAppId != MobileAppIdFromConfig)
	{
		UE_LOG(LogOculusPlatformBP, Log, TEXT("Settings Property Changed: The previous value set in DefaultEngine.ini -> MobileAppId = %s"), *MobileAppIdFromConfig);
		UE_LOG(LogOculusPlatformBP, Log, TEXT("Saving current value in OculusPlatformBPSettings to config file -> MobileAppId = %s"), *MobileAppId);
	}
	if (OculusAppId != OculusAppIdFromConfig)
	{
		UE_LOG(LogOculusPlatformBP, Log, TEXT("Settings Property Changed: The previous value set in DefaultEngine.ini -> OculusAppId = %s"), *OculusAppIdFromConfig);
		UE_LOG(LogOculusPlatformBP, Log, TEXT("Saving current value in OculusPlatformBPSettings to config file -> OculusAppId = %s"), *OculusAppId);
	}
	if (DefaultPlatformService != DefaultPlatformServiceFromConfig)
	{
		UE_LOG(LogOculusPlatformBP, Log, TEXT("Settings Property Changed: The previous value set in DefaultEngine.ini -> DefaultPlatformService = %s"), *DefaultPlatformServiceFromConfig);
		UE_LOG(LogOculusPlatformBP, Log, TEXT("Saving current value in OculusPlatformBPSettings to config file -> DefaultPlatformService = %s"), *DefaultPlatformService);
	}
	if (AndroidPlatformService != AndroidPlatformServiceFromConfig)
	{
		UE_LOG(LogOculusPlatformBP, Log, TEXT("The previous value set in AndroidEngine.ini -> AndroidPlatformService = %s"), *AndroidPlatformServiceFromConfig);
		UE_LOG(LogOculusPlatformBP, Log, TEXT("Saving current value in OculusPlatformBPSettings to config file -> AndroidPlatformService = %s"), *AndroidPlatformService);
	}

	// Save updated settings to config files
	SaveSettings();

	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif //WITH_EDITOR
