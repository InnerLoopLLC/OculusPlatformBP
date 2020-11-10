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
#define OBP_IS_NOT_IMPLEMENTED 1

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
enum class EOBP_AchievementType : uint8
{
	Unknown,
	Simple,
	Bitfield,
	Count
};

/* ovr_ChallengeCreationType.h */
UENUM(BlueprintType)
enum class EOBP_ChallengeCreationType : uint8
{
	Unknown,
	UserCreated,
	DeveloperCreated
};

/* ovr_ChallengeViewerFilter.h */
UENUM(BlueprintType)
enum class EOBP_ChallengeViewerFilter : uint8
{
	Unknown,
	AllVisible,
	Participating,
	Invited,
	ParticipatingOrInvited
};

/* ovr_ChallengeVisibility.h */
UENUM(BlueprintType)
enum class EOBP_ChallengeVisibility : uint8
{
	Unknown,
	InviteOnly,
	Public,
	Private
};


/* ovr_LeaderboardFilterType.h */
UENUM(BlueprintType)
enum class EOBP_LeaderboardFilterType : uint8
{
	None,
	Friends,
	Unknown,
	UserIds
};

/* ovr_LeaderboardStartAt.h */
UENUM(BlueprintType)
enum class EOBP_LeaderboardStartAt : uint8
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

/* ovr_RoomJoinability.h */
UENUM(BlueprintType)
enum class EOBP_RoomJoinability : uint8
{
	Unknown,
	AreIn,
	AreKicked,
	CanJoin,
	IsFull,
	NoViewer,
	PolicyPrevents
};

/* ovr_RoomJoinPolicy.h */
UENUM(BlueprintType)
enum class EOBP_RoomJoinPolicy : uint8
{
	None,
	Everyone,
	FriendsOfMembers,
	FriendsOfOwner,
	InvitedUsers,
	Unknown
};

/* ovr_RoomMembershipLockStatus.h */
UENUM(BlueprintType)
enum class EOBP_RoomMembershipLockStatus : uint8
{
	Unknown,
	Lock,
	Unlock
};

/* ovr_RoomType.h */
UENUM(BlueprintType)
enum class EOBP_RoomType : uint8
{
	Unknown,
	Matchmaking,
	Moderated,
	Private,
	Solo
};

/* ovr_ServiceProvider.h */
UENUM(BlueprintType)
enum class EOBP_ServiceProvider : uint8
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
enum class EOBP_SdkAccountType : uint8
{
	Unknown,
	Oculus,
	FacebookGameroom
};

/* ovr_TimeWindow.h */
UENUM(BlueprintType)
enum class EOBP_TimeWindow : uint8
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

/* Converts an EOBP_AchievementType to an ovrAchievementType for passing to the OculusPlatformSDK */
ovrAchievementType OBP_AchievementTypeToEnum(EOBP_AchievementType OBPAchievementType);

/* Converts an EOBP_LeaderboardFilterType to an ovrLeaderboardFilterType for passing to the OculusPlatformSDK
	Note: Enum value 'UserIds' Requires OculusPlatfromSDK v15 or later*/
ovrLeaderboardFilterType OBP_LeaderboardFilterToEnum(EOBP_LeaderboardFilterType OBPLeaderboardFilterType);

/* Converts an EOBP_LeaderboardStartAt to an ovrLeaderboardStartAt for passing to the OculusPlatformSDK */
ovrLeaderboardStartAt OBP_LeaderboardStartAtToEnum(EOBP_LeaderboardStartAt OBPLeaderboardStartAt);

// --------------------
// Logging Functions
// --------------------

/* Log errors caused by incorrect OculusPlatformSDK */
void OBP_PlatformVersionError(FString NodeName, FString RequiredPlatformVersion);

/* Log errors receiving ovr messages */
void OBP_MessageError(FString NodeName, ovrMessageHandle Message);

/* Log errors caused by a function that hasn't been fully implemented */
void OBP_NotImplementedError(FString NodeName);

// --------------------
// Helper Functions
// --------------------

/* Converts an TArray of FStrings to an array of const char */
const char** OBP_FStringArrayToChar(TArray<FString> Names);

/* Converts an FString to an int64/ovrID */
int64 OBP_FStringToInt64(FString InFString);

/* Converts an int64/ovrID to an FString */
FString OBP_Int64ToFString(int64 InInt64);