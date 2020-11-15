// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_UserOptions.h"

// --------------------
// Initializers
// --------------------

UOBP_UserOptions::UOBP_UserOptions(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_UserOptions.h
// --------------------

UOBP_UserOptions* UOBP_UserOptions::CreateUserOptions(UObject* WorldContextObject)
{
	auto UserOptions = NewObject<UOBP_UserOptions>();
	UserOptions->ovrUserOptionsHandle = ovr_UserOptions_Create();
	return UserOptions;
}

void UOBP_UserOptions::DestroyUserOptions()
{
	ovr_UserOptions_Destroy(ovrUserOptionsHandle);
}

void UOBP_UserOptions::SetMaxUsers(int32 MaxUsers)
{
	ovr_UserOptions_SetMaxUsers(ovrUserOptionsHandle, MaxUsers);
}

void UOBP_UserOptions::AddServiceProvider(EOBP_ServiceProvider ServiceProvider)
{
	switch (ServiceProvider)
	{
	case EOBP_ServiceProvider::Unknown:
		ovr_UserOptions_AddServiceProvider(ovrUserOptionsHandle, ovrServiceProvider_Unknown);
		break;
	case EOBP_ServiceProvider::Dropbox:
		ovr_UserOptions_AddServiceProvider(ovrUserOptionsHandle, ovrServiceProvider_Dropbox);
		break;
	case EOBP_ServiceProvider::Facebook:
		ovr_UserOptions_AddServiceProvider(ovrUserOptionsHandle, ovrServiceProvider_Facebook);
		break;
	case EOBP_ServiceProvider::Google:
		ovr_UserOptions_AddServiceProvider(ovrUserOptionsHandle, ovrServiceProvider_Google);
		break;
	case EOBP_ServiceProvider::Instagram:
		ovr_UserOptions_AddServiceProvider(ovrUserOptionsHandle, ovrServiceProvider_Instagram);
		break;
	case EOBP_ServiceProvider::RemoteMedia:
		ovr_UserOptions_AddServiceProvider(ovrUserOptionsHandle, ovrServiceProvider_RemoteMedia);
		break;
	default:
		ovr_UserOptions_AddServiceProvider(ovrUserOptionsHandle, ovrServiceProvider_Unknown);
		break;
	}
}

void UOBP_UserOptions::ClearServiceProviders()
{
	ovr_UserOptions_ClearServiceProviders(ovrUserOptionsHandle);
}

void UOBP_UserOptions::SetTimeWindow(EOBP_TimeWindow TimeWindow)
{
	switch (TimeWindow)
	{
	case EOBP_TimeWindow::Unknown:
		ovr_UserOptions_SetTimeWindow(ovrUserOptionsHandle, ovrTimeWindow_Unknown);
		break;
	case EOBP_TimeWindow::OneHour:
		ovr_UserOptions_SetTimeWindow(ovrUserOptionsHandle, ovrTimeWindow_OneHour);
		break;
	case EOBP_TimeWindow::OneDay:
		ovr_UserOptions_SetTimeWindow(ovrUserOptionsHandle, ovrTimeWindow_OneDay);
		break;
	case EOBP_TimeWindow::OneWeek:
		ovr_UserOptions_SetTimeWindow(ovrUserOptionsHandle, ovrTimeWindow_OneWeek);
		break;
	case EOBP_TimeWindow::ThirtyDays:
		ovr_UserOptions_SetTimeWindow(ovrUserOptionsHandle, ovrTimeWindow_ThirtyDays);
		break;
	case EOBP_TimeWindow::NinetyDays:
		ovr_UserOptions_SetTimeWindow(ovrUserOptionsHandle, ovrTimeWindow_NinetyDays);
		break;
	default:
		ovr_UserOptions_SetTimeWindow(ovrUserOptionsHandle, ovrTimeWindow_Unknown);
		break;
	}
}