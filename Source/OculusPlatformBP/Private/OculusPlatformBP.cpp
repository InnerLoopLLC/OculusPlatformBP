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