// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_DataStore.h"

// --------------------
// Initializers
// --------------------

UOBP_DataStore::UOBP_DataStore(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_DataStore.h
// --------------------

int32 UOBP_DataStore::Contains(FString Key)
{
	return ovr_DataStore_Contains(ovrDataStoreHandle, TCHAR_TO_ANSI(*Key));
}

FString UOBP_DataStore::GetKey(int32 Index)
{
	return ovr_DataStore_GetKey(ovrDataStoreHandle, Index);
}

int32 UOBP_DataStore::GetNumKeys()
{
	return ovr_DataStore_GetNumKeys(ovrDataStoreHandle);
}

FString UOBP_DataStore::GetValue(FString Key)
{
	return ovr_DataStore_GetValue(ovrDataStoreHandle, TCHAR_TO_ANSI(*Key));
}