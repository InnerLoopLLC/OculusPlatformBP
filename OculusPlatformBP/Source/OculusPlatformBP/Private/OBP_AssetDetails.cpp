// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_AssetDetails.h"

// --------------------
// Initializers
// --------------------

UOBP_AssetDetails::UOBP_AssetDetails(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_AssetDetails.h
// --------------------

FString UOBP_AssetDetails::GetAssetId(int32 Index)
{
	return OBP_Int64ToFString(ovr_AssetDetails_GetAssetId(ovrAssetDetailsHandle));
}

FString UOBP_AssetDetails::GetAssetType()
{
#if PLATFORM_MINOR_VERSION >= 28
	return ovr_AssetDetails_GetAssetType(ovrAssetDetailsHandle);
#else
	OBP_PlatformVersionError("AssetDetails::GetAssetType", "1.28");
	return FString();
#endif
}

FString UOBP_AssetDetails::GetDownloadStatus()
{
	return ovr_AssetDetails_GetDownloadStatus(ovrAssetDetailsHandle);
}

FString UOBP_AssetDetails::GetFilePath()
{
	return ovr_AssetDetails_GetFilepath(ovrAssetDetailsHandle);
}

FString UOBP_AssetDetails::GetIapStatus()
{
	return ovr_AssetDetails_GetIapStatus(ovrAssetDetailsHandle);
}

UOBP_LanguagePackInfo* UOBP_AssetDetails::GetLanguage()
{
#if PLATFORM_MINOR_VERSION >= 28
	auto LanguagePackInfo = NewObject< UOBP_LanguagePackInfo>();
	LanguagePackInfo->ovrLanguagePackInfoHandle = ovr_AssetDetails_GetLanguage(ovrAssetDetailsHandle);
	return LanguagePackInfo;
#else
	OBP_PlatformVersionError("AssetDetails::GetLanguage", "1.28");
	return nullptr;
#endif
}

FString UOBP_AssetDetails::GetMetadata()
{
#if PLATFORM_MINOR_VERSION >= 40
	return ovr_AssetDetails_GetMetadata(ovrAssetDetailsHandle);
#else
	OBP_PlatformVersionError("AssetDetails::GetMetadata", "1.40");
	return FString();
#endif
}
