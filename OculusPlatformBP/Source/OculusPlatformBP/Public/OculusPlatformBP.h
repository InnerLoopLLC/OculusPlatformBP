// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBPSettings.h"

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

#include "OculusPlatformBP.generated.h"

// Used to prevent incomplete functions from being compiled
#define OBP_IS_NOT_IMPLEMENTED 1

class FOculusPlatformBP : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

#if WITH_EDITOR
	void RegisterSettings(TWeakObjectPtr<UObject> UObject);
	void UnregisterSettings();
#endif //WITH_EDITOR

	static inline FOculusPlatformBP& Get()
	{
		return FModuleManager::LoadModuleChecked< FOculusPlatformBP >("OculusPlatformBP");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("OculusPlatformBP");
	}
};

// --------------------
// OculusPlatformBP Enums
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

/* ovr_LaunchType.h */
UENUM(BlueprintType)
enum class EOBP_LaunchType : uint8
{
	Unknown,
	Normal,
	Invite,
	Coordinated,
	Deeplink
};

/* ovr_LaunchResult.h */
UENUM(BlueprintType)
enum class EOBP_LaunchResult : uint8
{
	Unknown,
	Success,
	FailedRoomFull,
	FailedGameAlreadyStarted,
	FailedRoomNotFound,
	FailedUserDeclined,
	FailedOtherReason
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

/* ovr_MediaContentType.h */
UENUM(BlueprintType)
enum class EOBP_MediaContentType : uint8
{
	Unknown,
	Photo
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

/* ovr_ShareMediaStatus.h */
UENUM(BlueprintType)
enum class EOBP_ShareMediaStatus : uint8
{
	Unknown,
	Shared,
	Canceled
};

/* ovr_SystemVoipStatus.h */
UENUM(BlueprintType)
enum class EOBP_SystemVoipStatus : uint8
{
	Unknown,
	Unavailable,
	Suppressed,
	Active
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

/* ovr_UserOrdering.h */
UENUM(BlueprintType)
enum class EOBP_UserOrdering : uint8
{
	Unknown,
	None,
	PresenceAlphabetical
};

/* ovr_UserPresenceStatus.h */
UENUM(BlueprintType)
enum class EOBP_UserPresenceStatus : uint8
{
	Unknown,
	Online,
	Offline
};

/* ovr_VoipMuteState.h */
UENUM(BlueprintType)
enum class EOBP_VoipMuteState : uint8
{
	Unknown,
	Muted,
	Unmuted
};

// --------------------
// Structures
// --------------------

/* OVR_ApplicationOptions.h */
/* This structure only has a single variable (as of v23), so we're setting that variable directly for now.
USTRUCT(BlueprintType)
struct FOBP_ApplicationOptionsStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Application|Application Options") FString DeeplinkMessage;
};*/

/* OVR_ChallengeOptions.h */
USTRUCT(BlueprintType)
struct FOBP_ChallengeOptionsStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Challenges|Challenge Options") FString Title;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Challenges|Challenge Options") FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Challenges|Challenge Options") int32 StartDate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Challenges|Challenge Options") int32 EndDate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Challenges|Challenge Options") FString LeaderboardName; // optional
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Challenges|Challenge Options") bool bIncludeActiveChallenges;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Challenges|Challenge Options") bool bIncludeFutureChallenges;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Challenges|Challenge Options") bool bIncludePastChallenges;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Challenges|Challenge Options") EOBP_ChallengeViewerFilter ViewerFilter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Challenges|Challenge Options") EOBP_ChallengeVisibility Visibility;
};

/* OVR_RichPresenceOptions.h */
USTRUCT(BlueprintType)
struct FOBP_RichPresenceOptionsStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options") FString ApiName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options") int32 CurrentCapacity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options") int32 MaxCapacity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options") bool bIsJoinable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options") bool bIsIdle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options") FString InstanceID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options") FString DeeplinkMessageOverride;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options") int32 StartTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options") int32 EndTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options") FString LobbySessionID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options") FString MatchSessionID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Rich Presence|Rich Presence Options") EOBP_RichPresenceExtraContext ExtraContext = EOBP_RichPresenceExtraContext::None;
};

/* OVR_RoomOptions.h */
USTRUCT(BlueprintType)
struct FOBP_RoomOptionsStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Room|Room Options") FString RoomId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Room|Room Options") int32 MaxUserResults;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Room|Room Options") bool bExcludeRecentlyMet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Room|Room Options") EOBP_UserOrdering Ordering;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Room|Room Options") EOBP_TimeWindow TimeWindow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Room|Room Options") bool bTurnOffUpdates;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Room|Room Options") FString DataStoreKey;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|Room|Room Options") FString DataStoreValue;
};

/* OVR_UserOptions.h */
USTRUCT(BlueprintType)
struct FOBP_UserOptionsStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|User|User Options") int32 MaxUsers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|User|User Options") TArray<EOBP_ServiceProvider> ServiceProvider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oculus Platform BP|User|User Options") EOBP_TimeWindow TimeWindow;
};

// --------------------
// Logging Functions
// --------------------

/* Log errors caused by incorrect OculusPlatformSDK */
void OBP_PlatformVersionError(FString NodeName, FString RequiredPlatformVersion);

/* Log errors caused by OnlineSubsystemOculus not being active */
void OBP_SubsystemError(FString NodeName);

/* Log errors receiving ovr messages */
void OBP_MessageError(FString NodeName, ovrMessageHandle Message);

/* Log errors caused by a function that hasn't been fully implemented */
void OBP_NotImplementedError(FString NodeName);

/* Log errors caused by a deprecated function */
void OBP_DeprecatedError(FString NodeName, FString Reason);

// --------------------
// Helper Functions
// --------------------

/* Converts an TArray of FStrings to an array of const char */
const char** OBP_FStringArrayToChar(TArray<FString> Names);

/* Converts an FString to an int64/ovrID */
int64 OBP_FStringToInt64(FString InFString);

/* Converts an int64/ovrID to an FString */
FString OBP_Int64ToFString(int64 InInt64);