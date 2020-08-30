// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OculusPlatformBP.h"

DEFINE_LOG_CATEGORY(LogOculusPlatformBP);

class FOculusPlatformBP : public IOculusPlatformBP
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(FOculusPlatformBP, OculusPlatformBP)

void FOculusPlatformBP::StartupModule()
{
}


void FOculusPlatformBP::ShutdownModule()
{
}

void OBPPlatformVersionError(FString NodeName, FString RequiredPlatformVersion)
{
	FString errorString = FString("Unable to use ") + NodeName + FString(" node. Incorrect OculusPlatformSDK version in use. ") + RequiredPlatformVersion + FString(" or later required.");
	UE_LOG(LogOculusPlatformBP, Log, TEXT("%s"), *errorString);
};