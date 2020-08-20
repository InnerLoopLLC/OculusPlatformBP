// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogOculusPlatformBP, Log, All);

class IOculusPlatformBP : public IModuleInterface
{
public:

	static inline IOculusPlatformBP& Get()
	{
		return FModuleManager::LoadModuleChecked< IOculusPlatformBP >("OculusPlatformBP");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("OculusPlatformBP");
	}
};