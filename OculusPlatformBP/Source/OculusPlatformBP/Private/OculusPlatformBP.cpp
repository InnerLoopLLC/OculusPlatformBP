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

/*Log errors caused by incorrect OculusPlatformSDK.*/
void OBP_PlatformVersionError(FString NodeName, FString RequiredPlatformVersion)
{
	FString ErrorString = FString("Unable to use ") + NodeName + FString(" node. Incorrect OculusPlatformSDK version in use. ") + RequiredPlatformVersion + FString(" or later required.");
	UE_LOG(LogOculusPlatformBP, Log, TEXT("%s"), *ErrorString);
};

/*Log ovr message errors.*/
void OBP_MessageError(FString NodeName, ovrMessageHandle Message)
{
	FString ErrorCode = FString::FromInt(ovr_Error_GetCode(ovr_Message_GetError(Message)));
	FString ErrorString = FString("Error on ") + NodeName + FString(". Error Code: ") + ErrorCode + FString(")");
	UE_LOG(LogOculusPlatformBP, Log, TEXT("%s"), *ErrorString);

	FString ErrorMessage = ovr_Error_GetMessage(ovr_Message_GetError(Message));
	UE_LOG(LogOculusPlatformBP, Log, TEXT("%s"), *ErrorMessage);
};

// --------------------
// Enum Conversions
// --------------------

/* Converts an EOBPLeaderboardFilterType to an ovrLeaderboardFilterType for passing to the OculusPlatformSDK
	Note: Enum value 'UserIds' Requires OculusPlatfromSDK v15 or later
		  Otherwise, 'UserIds' returns 'None' */
ovrLeaderboardFilterType OBP_LeaderboardFilterToEnum(EOBPLeaderboardFilterType OBPLeaderboardFilterType)
{
	switch (OBPLeaderboardFilterType)
	{
	case EOBPLeaderboardFilterType::None:
		return ovrLeaderboard_FilterNone;
		break;
	case EOBPLeaderboardFilterType::Friends:
		return ovrLeaderboard_FilterFriends;
		break;
	case EOBPLeaderboardFilterType::Unknown:
		return ovrLeaderboard_FilterUnknown;
		break;
	case EOBPLeaderboardFilterType::UserIds:
#if PLATFORM_MINOR_VERSION >= 47
		return ovrLeaderboard_FilterUserIds;
#else
		return ovrLeaderboard_FilterNone;
#endif
		break;
	default:
		return ovrLeaderboard_FilterNone;
	}
}

/* Converts an EOBPLeaderboardStartAt to an ovrLeaderboardStartAt for passing to the OculusPlatformSDK */
ovrLeaderboardStartAt OBP_LeaderboardStartAtToEnum(EOBPLeaderboardStartAt OBPLeaderboardStartAt)
{
	switch (OBPLeaderboardStartAt)
	{
	case EOBPLeaderboardStartAt::Top:
		return ovrLeaderboard_StartAtTop;
		break;
	case EOBPLeaderboardStartAt::CenteredOnViewer:
		return ovrLeaderboard_StartAtCenteredOnViewer;
		break;
	case EOBPLeaderboardStartAt::CenteredOnViewerOrTop:
		return ovrLeaderboard_StartAtCenteredOnViewerOrTop;
		break;
	case EOBPLeaderboardStartAt::Unknown:
		return ovrLeaderboard_StartAtUnknown;
		break;
	default:
		return ovrLeaderboard_StartAtTop;
	}
}