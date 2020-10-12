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

#include <ThirdParty/Oculus/LibOVRPlatform/LibOVRPlatform/include/OVR_Platform.h>

#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogOculusPlatformBP, Log, All);

// Used to prevent incomplete functions from being compiled
#define OBP_IS_IMPLEMENTED 0

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

// --------------------
// Enums - UEnums have to be declared here, I guess? They don't work when declared in each OBP_xxx.h file
// --------------------

/* ovr_AchievementType.h */
UENUM(BlueprintType)
enum class EOBPAchievementType : uint8
{
	Unknown,
	Simple,
	Bitfield,
	Count
};

/* ovr_LeaderboardFilterType.h */
UENUM(BlueprintType)
enum class EOBPLeaderboardFilterType : uint8
{
	None,
	Friends,
	Unknown,
	UserIds
};

/* ovr_LeaderboardStartAt.h */
UENUM(BlueprintType)
enum class EOBPLeaderboardStartAt : uint8
{
	Top,
	CenteredOnViewer,
	CenteredOnViewerOrTop,
	Unknown
};

/* ovr_RichPresenceExtraContext.h */
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

/* ovr_ServiceProvider.h */
UENUM(BlueprintType)
enum class EOBPServiceProvider : uint8
{
	Unknown,
	Dropbox,
	Facebook,
	Google,
	Instagram,
	RemoteMedia
};

/* ovr_SdkAccountType.h */
UENUM(BlueprintType)
enum class EOBPSdkAccountType : uint8
{
	Unknown,
	Oculus,
	FacebookGameroom
};

/* ovr_TimeWindow.h */
UENUM(BlueprintType)
enum class EOBPTimeWindow : uint8
{
	Unknown,
	OneHour,
	OneDay,
	OneWeek,
	ThirtyDays,
	NinetyDays
};

/* ovr_UserPresenceStatus.h */
UENUM(BlueprintType)
enum class EOBP_UserPresenceStatus : uint8
{
	Unknown,
	Online,
	Offline
};

// --------------------
// Enum Conversions
// --------------------

/* Converts an EOBPAchievementType to an ovrAchievementType for passing to the OculusPlatformSDK */
ovrAchievementType OBP_AchievementTypeToEnum(EOBPAchievementType OBPAchievementType);

/* Converts an EOBPLeaderboardFilterType to an ovrLeaderboardFilterType for passing to the OculusPlatformSDK
	Note: Enum value 'UserIds' Requires OculusPlatfromSDK v15 or later*/
ovrLeaderboardFilterType OBP_LeaderboardFilterToEnum(EOBPLeaderboardFilterType OBPLeaderboardFilterType);

/* Converts an EOBPLeaderboardStartAt to an ovrLeaderboardStartAt for passing to the OculusPlatformSDK */
ovrLeaderboardStartAt OBP_LeaderboardStartAtToEnum(EOBPLeaderboardStartAt OBPLeaderboardStartAt);

// --------------------
// Logging Functions
// --------------------

/*Log errors caused by incorrect OculusPlatformSDK.*/
void OBP_PlatformVersionError(FString NodeName, FString RequiredPlatformVersion);

/*Log errors receiving ovr messages.*/
void OBP_MessageError(FString NodeName, ovrMessageHandle Message);

/*Log errors caused by a function that hasn't been fully implemented.*/
void OBP_NotImplementedError(FString NodeName);