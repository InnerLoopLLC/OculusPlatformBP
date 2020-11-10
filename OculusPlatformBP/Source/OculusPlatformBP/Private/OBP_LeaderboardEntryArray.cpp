// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_LeaderboardEntryArray.h"

// --------------------
// Initializers
// --------------------

UOBP_LeaderboardEntryArray::UOBP_LeaderboardEntryArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_LeaderboardEntryArray.h
// --------------------

UOBP_LeaderboardEntry* UOBP_LeaderboardEntryArray::GetElement(int32 Index)
{
	auto LeaderboardEntryToGet = NewObject<UOBP_LeaderboardEntry>();
	LeaderboardEntryToGet->ovrLeaderboardEntryHandle = ovr_LeaderboardEntryArray_GetElement(ovrLeaderboardEntryArrayHandle, Index);
	return LeaderboardEntryToGet;
}

FString UOBP_LeaderboardEntryArray::GetNextUrl()
{
	return ovr_LeaderboardEntryArray_GetNextUrl(ovrLeaderboardEntryArrayHandle);
}

FString UOBP_LeaderboardEntryArray::GetPreviousUrl()
{
	return ovr_LeaderboardEntryArray_GetPreviousUrl(ovrLeaderboardEntryArrayHandle);
}

int32 UOBP_LeaderboardEntryArray::GetSize()
{
	return ovr_LeaderboardEntryArray_GetSize(ovrLeaderboardEntryArrayHandle);
}

int32 UOBP_LeaderboardEntryArray::GetTotalCount()
{
	return ovr_LeaderboardEntryArray_GetTotalCount(ovrLeaderboardEntryArrayHandle);
}

bool UOBP_LeaderboardEntryArray::HasNextPage()
{
	return ovr_LeaderboardEntryArray_HasNextPage(ovrLeaderboardEntryArrayHandle);
}

bool UOBP_LeaderboardEntryArray::HasPreviousPage()
{
	return ovr_LeaderboardEntryArray_HasPreviousPage(ovrLeaderboardEntryArrayHandle);
}