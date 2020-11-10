// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_ChallengeArray.h"

// --------------------
// Initializers
// --------------------

UOBP_ChallengeArray::UOBP_ChallengeArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_ChallengeArray.h
// --------------------

UOBP_Challenge* UOBP_ChallengeArray::GetElement(int32 Index)
{
#if PLATFORM_MINOR_VERSION >= 51
	auto ChallengeToGet = NewObject<UOBP_Challenge>();
	ChallengeToGet->ovrChallengeHandle = ovr_ChallengeArray_GetElement(ovrChallengeArrayHandle, Index);
	return ChallengeToGet;
#else
	OBP_PlatformVersionError("ChallengeArray::GetElement", "v19");
	return nullptr;
#endif
}

FString UOBP_ChallengeArray::GetNextUrl()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_ChallengeArray_GetNextUrl(ovrChallengeArrayHandle);
#else
	OBP_PlatformVersionError("ChallengeArray::GetNextUrl", "v19");
	return FString();
#endif
}

FString UOBP_ChallengeArray::GetPreviousUrl()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_ChallengeArray_GetPreviousUrl(ovrChallengeArrayHandle);
#else
	OBP_PlatformVersionError("ChallengeArray::GetPreviousUrl", "v19");
	return FString();
#endif
}

int32 UOBP_ChallengeArray::GetSize()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_ChallengeArray_GetSize(ovrChallengeArrayHandle);
#else
	OBP_PlatformVersionError("ChallengeArray::GetSize", "v19");
	return 0;
#endif
}

int32 UOBP_ChallengeArray::GetTotalCount()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_ChallengeArray_GetTotalCount(ovrChallengeArrayHandle);
#else
	OBP_PlatformVersionError("ChallengeArray::GetTotalCount", "v19");
	return 0;
#endif
}

bool UOBP_ChallengeArray::HasNextPage()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_ChallengeArray_HasNextPage(ovrChallengeArrayHandle);
#else
	OBP_PlatformVersionError("ChallengeArray::HasNextPage", "v19");
	return false;
#endif
}

bool UOBP_ChallengeArray::HasPreviousPage()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_ChallengeArray_HasPreviousPage(ovrChallengeArrayHandle);
#else
	OBP_PlatformVersionError("ChallengeArray::HasPreviousPage", "v19");
	return false;
#endif
}
