// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_TeamArray.h"

// --------------------
// Initializers
// --------------------

UOBP_TeamArray::UOBP_TeamArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_TeamArray.h
// --------------------

UOBP_Team* UOBP_TeamArray::GetElement(int32 Index)
{
#if PLATFORM_MINOR_VERSION >= 39
	auto Team = NewObject<UOBP_Team>();
	Team->ovrTeamHandle = ovr_TeamArray_GetElement(ovrTeamArrayHandle, Index);
	return Team;
#else
	OBP_PlatformVersionError("TeamArray::GetElement", "1.39");
	return nullptr;
#endif
}

int32 UOBP_TeamArray::GetSize()
{
#if PLATFORM_MINOR_VERSION >= 39
	return ovr_TeamArray_GetSize(ovrTeamArrayHandle);
#else
	OBP_PlatformVersionError("TeamArray::GetSize", "1.39");
	return 0;
#endif
}