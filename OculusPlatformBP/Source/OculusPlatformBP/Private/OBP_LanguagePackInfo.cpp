// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_LanguagePackInfo.h"

// --------------------
// Initializers
// --------------------

UOBP_LanguagePackInfo::UOBP_LanguagePackInfo(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_LanguagePackInfo.h
// --------------------

FString UOBP_LanguagePackInfo::GetEnglishName()
{
#if PLATFORM_MINOR_VERSION >= 28
	return ovr_LanguagePackInfo_GetEnglishName(ovrLanguagePackInfoHandle);
#else
	OBP_PlatformVersionError("LanguagePackInfo::GetEnglishName", "1.28");
	return FString();
#endif
}

FString UOBP_LanguagePackInfo::GetNativeName()
{
#if PLATFORM_MINOR_VERSION >= 28
	return ovr_LanguagePackInfo_GetNativeName(ovrLanguagePackInfoHandle);
#else
	OBP_PlatformVersionError("LanguagePackInfo::GetNativeName", "1.28");
	return FString();
#endif
}

FString UOBP_LanguagePackInfo::GetTag()
{
#if PLATFORM_MINOR_VERSION >= 28
	return ovr_LanguagePackInfo_GetTag(ovrLanguagePackInfoHandle);
#else
	OBP_PlatformVersionError("LanguagePackInfo::GetTag", "1.28");
	return FString();
#endif
}
