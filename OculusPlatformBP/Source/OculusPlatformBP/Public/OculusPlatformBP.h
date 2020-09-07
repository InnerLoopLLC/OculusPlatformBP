// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "CoreGlobals.h"
#include "CoreMinimal.h"
#include "EngineGlobals.h"
#include "Engine/Engine.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "UObject/ObjectMacros.h"

#include "Online.h"
#include "OnlineSubsystem.h"
#include "OnlineSubsystemOculus.h"

#include <ThirdParty\Oculus\LibOVRPlatform\LibOVRPlatform\include\OVR_Platform.h>

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

// OVR_RichPresenceExtraContext.h (https://developer.oculus.com/reference/platform/v19/o_v_r_rich_presence_extra_context_8h/)
UENUM(BlueprintType)
enum class EOBP_RichPresenceExtraContext : uint8
{
	Unknown,
	None,
	CurrentCapacity,
	StartedAgo,
	EndingIn,
	LookingForMatch
};

UENUM(BlueprintType)
enum class EOBP_UserPresenceStatus : uint8
{
	Unknown,
	Online,
	Offline
};

void OBP_PlatformVersionError(FString NodeName, FString RequiredPlatformVersion);
