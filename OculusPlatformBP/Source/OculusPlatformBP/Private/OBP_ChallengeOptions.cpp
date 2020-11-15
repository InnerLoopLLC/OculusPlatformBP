// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_ChallengeOptions.h"

// --------------------
// Initializers
// --------------------

UOBP_ChallengeOptions::UOBP_ChallengeOptions(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_ChallengeOptions.h
// --------------------

UOBP_ChallengeOptions* UOBP_ChallengeOptions::CreateChallengeOptions(UObject* WorldContextObject)
{
#if PLATFORM_MINOR_VERSION >= 51
	auto ChallengeOptions = NewObject<UOBP_ChallengeOptions>();
	ChallengeOptions->ovrChallengeOptionsHandle = ovr_ChallengeOptions_Create();
	return ChallengeOptions;
#else
	OBP_PlatformVersionError("ChallengeOptions::CreateChallengeOptions", "v19");
	return nullptr;
#endif
}

void UOBP_ChallengeOptions::DestroyChallengeOptions()
{
#if PLATFORM_MINOR_VERSION >= 51
	ovr_ChallengeOptions_Destroy(ovrChallengeOptionsHandle);
#else
	OBP_PlatformVersionError("ChallengeOptions::DestroyChallengeOptions", "v19");
#endif
}

void UOBP_ChallengeOptions::SetDescription(FString Description)
{
#if PLATFORM_MINOR_VERSION >= 51
	ovr_ChallengeOptions_SetDescription(ovrChallengeOptionsHandle, TCHAR_TO_ANSI(*Description));
#else
	OBP_PlatformVersionError("ChallengeOptions::SetDescription", "v19");
#endif
}

void UOBP_ChallengeOptions::SetEndDate(int32 Value)
{
#if PLATFORM_MINOR_VERSION >= 51
	ovr_ChallengeOptions_SetEndDate(ovrChallengeOptionsHandle, Value);
#else
	OBP_PlatformVersionError("ChallengeOptions::SetEndDate", "v19");
#endif
}

void UOBP_ChallengeOptions::SetIncludeActiveChallenges(bool bShouldInclude)
{
#if PLATFORM_MINOR_VERSION >= 51
	ovr_ChallengeOptions_SetIncludeActiveChallenges(ovrChallengeOptionsHandle, bShouldInclude);
#else
	OBP_PlatformVersionError("ChallengeOptions::SetIncludeActiveChallenges", "v19");
#endif
}

void UOBP_ChallengeOptions::SetIncludeFutureChallenges(bool bShouldInclude)
{
#if PLATFORM_MINOR_VERSION >= 51
	ovr_ChallengeOptions_SetIncludeFutureChallenges(ovrChallengeOptionsHandle, bShouldInclude);
#else
	OBP_PlatformVersionError("ChallengeOptions::SetIncludeFutureChallenges", "v19");
#endif
}

void UOBP_ChallengeOptions::SetIncludePastChallenges(bool bShouldInclude)
{
#if PLATFORM_MINOR_VERSION >= 51
	ovr_ChallengeOptions_SetIncludePastChallenges(ovrChallengeOptionsHandle, bShouldInclude);
#else
	OBP_PlatformVersionError("ChallengeOptions::SetIncludePastChallenges", "v19");
#endif
}

void UOBP_ChallengeOptions::SetLeaderboardName(FString LeaderboardName)
{
#if PLATFORM_MINOR_VERSION >= 51
	ovr_ChallengeOptions_SetLeaderboardName(ovrChallengeOptionsHandle, TCHAR_TO_ANSI(*LeaderboardName));
#else
	OBP_PlatformVersionError("ChallengeOptions::SetLeaderboardName", "v19");
#endif
}

void UOBP_ChallengeOptions::SetStartDate(int32 Value)
{
#if PLATFORM_MINOR_VERSION >= 51
	ovr_ChallengeOptions_SetStartDate(ovrChallengeOptionsHandle, Value);
#else
	OBP_PlatformVersionError("ChallengeOptions::SetStartDate", "v19");
#endif
}

void UOBP_ChallengeOptions::SetTitle(FString Title)
{
#if PLATFORM_MINOR_VERSION >= 51
	ovr_ChallengeOptions_SetTitle(ovrChallengeOptionsHandle, TCHAR_TO_ANSI(*Title));
#else
	OBP_PlatformVersionError("ChallengeOptions::SetTitle", "v19");
#endif
}

void UOBP_ChallengeOptions::SetViewerFilter(EOBP_ChallengeViewerFilter Filter)
{
#if PLATFORM_MINOR_VERSION >= 51
	switch (Filter)
	{
	case EOBP_ChallengeViewerFilter::Unknown:
		ovr_ChallengeOptions_SetViewerFilter(ovrChallengeOptionsHandle, ovrChallengeViewerFilter_Unknown);
		break;
	case EOBP_ChallengeViewerFilter::AllVisible:
		ovr_ChallengeOptions_SetViewerFilter(ovrChallengeOptionsHandle, ovrChallengeViewerFilter_AllVisible);
		break;
	case EOBP_ChallengeViewerFilter::Participating:
		ovr_ChallengeOptions_SetViewerFilter(ovrChallengeOptionsHandle, ovrChallengeViewerFilter_Participating);
		break;
	case EOBP_ChallengeViewerFilter::Invited:
		ovr_ChallengeOptions_SetViewerFilter(ovrChallengeOptionsHandle, ovrChallengeViewerFilter_Invited);
		break;
	case EOBP_ChallengeViewerFilter::ParticipatingOrInvited:
		ovr_ChallengeOptions_SetViewerFilter(ovrChallengeOptionsHandle, ovrChallengeViewerFilter_ParticipatingOrInvited);
		break;
	default:
		ovr_ChallengeOptions_SetViewerFilter(ovrChallengeOptionsHandle, ovrChallengeViewerFilter_Unknown);
		break;
}
#else
	OBP_PlatformVersionError("ChallengeOptions::SetViewerFilter", "v19");
#endif
}

void UOBP_ChallengeOptions::SetVisibility(EOBP_ChallengeVisibility Visibility)
{
#if PLATFORM_MINOR_VERSION >= 51
	switch (Visibility)
	{
	case EOBP_ChallengeVisibility::Unknown:
		ovr_ChallengeOptions_SetVisibility(ovrChallengeOptionsHandle, ovrChallengeVisibility_Unknown);
		break;
	case EOBP_ChallengeVisibility::InviteOnly:
		ovr_ChallengeOptions_SetVisibility(ovrChallengeOptionsHandle, ovrChallengeVisibility_InviteOnly);
		break;
	case EOBP_ChallengeVisibility::Public:
		ovr_ChallengeOptions_SetVisibility(ovrChallengeOptionsHandle, ovrChallengeVisibility_Public);
		break;
	case EOBP_ChallengeVisibility::Private:
		ovr_ChallengeOptions_SetVisibility(ovrChallengeOptionsHandle, ovrChallengeVisibility_Private);
		break;
	default:
		ovr_ChallengeOptions_SetVisibility(ovrChallengeOptionsHandle, ovrChallengeVisibility_Unknown);
		break;
	}
#else
	OBP_PlatformVersionError("ChallengeOptions::SetVisibility", "v19");
#endif
}
