// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_RoomOptions.h"

// --------------------
// Initializers
// --------------------

UOBP_RoomOptions::UOBP_RoomOptions(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_RoomOptions.h
// --------------------

UOBP_RoomOptions* UOBP_RoomOptions::CreateRoomOptions(UObject* WorldContextObject)
{
	auto RoomOptions = NewObject<UOBP_RoomOptions>();
	RoomOptions->ovrRoomOptionsHandle = ovr_RoomOptions_Create();
	return RoomOptions;
}

void UOBP_RoomOptions::DestroyRoomOptions()
{
	ovr_RoomOptions_Destroy(ovrRoomOptionsHandle);
}

void UOBP_RoomOptions::SetDataStoreString(FString Key, FString Value)
{
	ovr_RoomOptions_SetDataStoreString(ovrRoomOptionsHandle, TCHAR_TO_ANSI(*Key), TCHAR_TO_ANSI(*Value));
}

void UOBP_RoomOptions::ClearDataStore()
{
	ovr_RoomOptions_ClearDataStore(ovrRoomOptionsHandle);
}

void UOBP_RoomOptions::SetExcludeRecentlyMet(bool Value)
{
	ovr_RoomOptions_SetExcludeRecentlyMet(ovrRoomOptionsHandle, Value);
}

void UOBP_RoomOptions::SetMaxUserResults(int32 Value)
{
	ovr_RoomOptions_SetMaxUserResults(ovrRoomOptionsHandle, Value);
}

void UOBP_RoomOptions::SetOrdering(EOBP_UserOrdering Order)
{
	switch (Order)
	{
	case EOBP_UserOrdering::Unknown:
		ovr_RoomOptions_SetOrdering(ovrRoomOptionsHandle, ovrUserOrdering_Unknown);
		break;
	case EOBP_UserOrdering::None:
		ovr_RoomOptions_SetOrdering(ovrRoomOptionsHandle, ovrUserOrdering_None);
		break;
	case EOBP_UserOrdering::PresenceAlphabetical:
		ovr_RoomOptions_SetOrdering(ovrRoomOptionsHandle, ovrUserOrdering_PresenceAlphabetical);
		break;
	default:
		ovr_RoomOptions_SetOrdering(ovrRoomOptionsHandle, ovrUserOrdering_Unknown);
		break;
	}
}

void UOBP_RoomOptions::SetRecentlyMetTimeWindow(EOBP_TimeWindow TimeWindow)
{
	switch (TimeWindow)
	{
	case EOBP_TimeWindow::Unknown:
		ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_Unknown);
		break;
	case EOBP_TimeWindow::OneHour:
		ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_OneHour);
		break;
	case EOBP_TimeWindow::OneDay:
		ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_OneDay);
		break;
	case EOBP_TimeWindow::OneWeek:
		ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_OneWeek);
		break;
	case EOBP_TimeWindow::ThirtyDays:
		ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_ThirtyDays);
		break;
	case EOBP_TimeWindow::NinetyDays:
		ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_NinetyDays);
		break;
	default:
		ovr_RoomOptions_SetRecentlyMetTimeWindow(ovrRoomOptionsHandle, ovrTimeWindow_Unknown);
		break;
	}
}

void UOBP_RoomOptions::SetRoomId(FString RoomId)
{
	ovr_RoomOptions_SetRoomId(ovrRoomOptionsHandle, OBP_FStringToInt64(RoomId));
}

void UOBP_RoomOptions::SetTurnOffUpdates(bool Value)
{
	ovr_RoomOptions_SetTurnOffUpdates(ovrRoomOptionsHandle, Value);
}