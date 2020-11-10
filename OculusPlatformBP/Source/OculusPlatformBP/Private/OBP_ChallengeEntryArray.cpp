// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_ChallengeEntryArray.h"

// --------------------
// Initializers
// --------------------

UOBP_ChallengeEntryArray::UOBP_ChallengeEntryArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_ChallengeEntryArray.h
// --------------------

UOBP_ChallengeEntry* UOBP_ChallengeEntryArray::GetElement(int32 Index)
{
#if PLATFORM_MINOR_VERSION >= 51
	auto ChallengeEntryToGet = NewObject<UOBP_ChallengeEntry>();
	ChallengeEntryToGet->ovrChallengeEntryHandle = ovr_ChallengeEntryArray_GetElement(ovrChallengeEntryArrayHandle, Index);
	return ChallengeEntryToGet;
#else
	OBP_PlatformVersionError("ChallengeEntryArray::GetElement", "v19");
	return nullptr;
#endif
}

FString UOBP_ChallengeEntryArray::GetNextUrl()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_ChallengeEntryArray_GetNextUrl(ovrChallengeEntryArrayHandle);
#else
	OBP_PlatformVersionError("ChallengeEntryArray::GetElement", "v19");
	return FString();
#endif
}

FString UOBP_ChallengeEntryArray::GetPreviousUrl()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_ChallengeEntryArray_GetPreviousUrl(ovrChallengeEntryArrayHandle);
#else
	OBP_PlatformVersionError("ChallengeEntryArray::GetElement", "v19");
	return FString();
#endif
}

int32 UOBP_ChallengeEntryArray::GetSize()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_ChallengeEntryArray_GetSize(ovrChallengeEntryArrayHandle);
#else
	OBP_PlatformVersionError("ChallengeEntryArray::GetElement", "v19");
	return 0;
#endif
}

int32 UOBP_ChallengeEntryArray::GetTotalCount()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_ChallengeEntryArray_GetTotalCount(ovrChallengeEntryArrayHandle);
#else
	OBP_PlatformVersionError("ChallengeEntryArray::GetElement", "v19");
	return 0;
#endif
}

bool UOBP_ChallengeEntryArray::HasNextPage()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_ChallengeEntryArray_HasNextPage(ovrChallengeEntryArrayHandle);
#else
	OBP_PlatformVersionError("ChallengeEntryArray::GetElement", "v19");
	return false;
#endif
}

bool UOBP_ChallengeEntryArray::HasPreviousPage()
{
#if PLATFORM_MINOR_VERSION >= 51
	return ovr_ChallengeEntryArray_HasPreviousPage(ovrChallengeEntryArrayHandle);
#else
	OBP_PlatformVersionError("ChallengeEntryArray::GetElement", "v19");
	return false;
#endif
}