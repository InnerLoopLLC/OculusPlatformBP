// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_SdkAccount.h"

// --------------------
// Initializers
// --------------------

UOBP_SdkAccount::UOBP_SdkAccount(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_SdkAccount.h
// --------------------

EOBP_SdkAccountType UOBP_SdkAccount::GetAccountType()
{
	switch (ovr_SdkAccount_GetAccountType(ovrSdkAccountHandle))
	{
	case ovrSdkAccountType_Unknown:
		return EOBP_SdkAccountType::Unknown;
	case ovrSdkAccountType_Oculus:
		return EOBP_SdkAccountType::Oculus;
	case ovrSdkAccountType_FacebookGameroom:
		return EOBP_SdkAccountType::FacebookGameroom;
	default:
		return EOBP_SdkAccountType::Unknown;
	}
}

FString UOBP_SdkAccount::GetUserId()
{
	int64 ovrID = ovr_SdkAccount_GetUserId(ovrSdkAccountHandle);
	return OBP_Int64ToFString(ovrID);
}