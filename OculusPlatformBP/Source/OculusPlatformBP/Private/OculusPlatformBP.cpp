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

// --------------------
// Enum Conversions
// --------------------

/* Converts an EOBP_AchievementType to an ovrAchievementType for passing to the OculusPlatformSDK */
ovrAchievementType OBP_AchievementTypeToEnum(EOBP_AchievementType OBPAchievementType)
{
	switch (OBPAchievementType)
	{
	case EOBP_AchievementType::Unknown:
		return ovrAchievement_TypeUnknown;
	case EOBP_AchievementType::Simple:
		return ovrAchievement_TypeSimple;
	case EOBP_AchievementType::Bitfield:
		return ovrAchievement_TypeBitfield;
	case EOBP_AchievementType::Count:
		return ovrAchievement_TypeCount;
	default:
		return ovrAchievement_TypeUnknown;
	}
}

/* Converts an EOBP_LeaderboardFilterType to an ovrLeaderboardFilterType for passing to the OculusPlatformSDK
	Note: Enum value 'UserIds' Requires OculusPlatfromSDK v15 or later
		  Otherwise, 'UserIds' returns 'None' */
ovrLeaderboardFilterType OBP_LeaderboardFilterToEnum(EOBP_LeaderboardFilterType OBPLeaderboardFilterType)
{
	switch (OBPLeaderboardFilterType)
	{
	case EOBP_LeaderboardFilterType::None:
		return ovrLeaderboard_FilterNone;
	case EOBP_LeaderboardFilterType::Friends:
		return ovrLeaderboard_FilterFriends;
	case EOBP_LeaderboardFilterType::Unknown:
		return ovrLeaderboard_FilterUnknown;
	case EOBP_LeaderboardFilterType::UserIds:
#if PLATFORM_MINOR_VERSION >= 47
		return ovrLeaderboard_FilterUserIds;
#else
		return ovrLeaderboard_FilterNone;
#endif
	default:
		return ovrLeaderboard_FilterNone;
	}
}

/* Converts an EOBP_LeaderboardStartAt to an ovrLeaderboardStartAt for passing to the OculusPlatformSDK */
ovrLeaderboardStartAt OBP_LeaderboardStartAtToEnum(EOBP_LeaderboardStartAt OBPLeaderboardStartAt)
{
	switch (OBPLeaderboardStartAt)
	{
	case EOBP_LeaderboardStartAt::Top:
		return ovrLeaderboard_StartAtTop;
	case EOBP_LeaderboardStartAt::CenteredOnViewer:
		return ovrLeaderboard_StartAtCenteredOnViewer;
	case EOBP_LeaderboardStartAt::CenteredOnViewerOrTop:
		return ovrLeaderboard_StartAtCenteredOnViewerOrTop;
	case EOBP_LeaderboardStartAt::Unknown:
		return ovrLeaderboard_StartAtUnknown;
	default:
		return ovrLeaderboard_StartAtTop;
	}
}

// --------------------
// Logging Functions
// --------------------

/*Log errors caused by incorrect OculusPlatformSDK */
void OBP_PlatformVersionError(FString NodeName, FString RequiredPlatformVersion)
{
	FString ErrorString = FString("Unable to use ") + NodeName + FString(" node. Incorrect OculusPlatformSDK version in use. ") + RequiredPlatformVersion + FString(" or later required.");
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("%s"), *ErrorString);
}

/* Log ovr message errors.*/
void OBP_MessageError(FString NodeName, ovrMessageHandle Message)
{
	FString ErrorCode = FString::FromInt(ovr_Error_GetCode(ovr_Message_GetError(Message)));
	FString ErrorString = FString("Error on ") + NodeName + FString(". Error Code: ") + ErrorCode;
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("%s"), *ErrorString);

	FString ErrorMessage = ovr_Error_GetMessage(ovr_Message_GetError(Message));
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("%s"), *ErrorMessage);
}

/* Log errors caused by a function that hasn't been fully implemented */
void OBP_NotImplementedError(FString NodeName)
{
	FString ErrorString = NodeName + FString(" has not yet been fully implemented. This node will work in a future version of this plugin.");
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("%s"), *ErrorString);
}

// --------------------
// Helper Functions
// --------------------

/* Converts an TArray of FStrings to an array of const char - This works... except on <=4.21. This is safer than the in-use method... but oh well. */
const char** OBP_FStringArrayToChar(TArray<FString> Names)
{
	/*
	std::vector<std::string> StringArray;
	for (size_t i = 0; i < Names.Num(); i++)
	{
		StringArray.push_back(std::string(TCHAR_TO_UTF8(*(Names[i]))));
	}
	std::vector<const char*> CharPtrArray;
	for (size_t i = 0; i < StringArray.size(); i++)
	{
		CharPtrArray.push_back(StringArray[i].c_str());
	}
	return CharPtrArray.data(); */
	return nullptr;
}

/* Converts an FString to an int64 or ovrID - Function exists in case it needs to be modified later */
int64 OBP_FStringToInt64(FString InFString)
{
	return FCString::Atoi64(*InFString);
}

/* Converts an int64 or ovrID to an FString - Function exists in case it needs to be modified later */
FString OBP_Int64ToFString(int64 InInt64)
{
	return FString::Printf(TEXT("%lld"), InInt64);
}