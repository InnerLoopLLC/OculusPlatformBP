// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Requests_Deprecated.h"

// --------------------
//	THIS FILE CONSISTS OF DEPRECATED FUNCTIONS ONLY!
//	These allow projects that have not yet been updated to open without crashing.
//	This will all be deleted in a future update.
// --------------------

// --------------------
// Initializers
// --------------------
// Leaderboard Requests
UOBP_GetEntries::UOBP_GetEntries(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
UOBP_GetEntriesAfterRank::UOBP_GetEntriesAfterRank(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
UOBP_GetEntriesByIds::UOBP_GetEntriesByIds(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
UOBP_GetNextEntries::UOBP_GetNextEntries(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
UOBP_GetPreviousEntries::UOBP_GetPreviousEntries(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
UOBP_WriteEntry::UOBP_WriteEntry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
// Rich Presence Requests
UOBP_ClearRichPresence::UOBP_ClearRichPresence(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
UOBP_GetDestinations::UOBP_GetDestinations(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
UOBP_GetNextDestinationArrayPage::UOBP_GetNextDestinationArrayPage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
UOBP_SetRichPresence::UOBP_SetRichPresence(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
// User Requests
UOBP_GetUser::UOBP_GetUser(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
UOBP_GetAccessToken::UOBP_GetAccessToken(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
UOBP_GetLoggedInUser::UOBP_GetLoggedInUser(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
UOBP_GetLoggedInUserFriends::UOBP_GetLoggedInUserFriends(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
UOBP_GetLoggedInUserFriendsAndRooms::UOBP_GetLoggedInUserFriendsAndRooms(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
UOBP_GetLoggedInUserRecentlyMetUsersAndRooms::UOBP_GetLoggedInUserRecentlyMetUsersAndRooms(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
UOBP_GetNextUserAndRoomArrayPage::UOBP_GetNextUserAndRoomArrayPage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
UOBP_GetNextUserArrayPage::UOBP_GetNextUserArrayPage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
UOBP_GetOrgScopedID::UOBP_GetOrgScopedID(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
UOBP_GetSdkAccounts::UOBP_GetSdkAccounts(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
UOBP_GetUserProof::UOBP_GetUserProof(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
UOBP_LaunchFriendRequestFlow::UOBP_LaunchFriendRequestFlow(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
UOBP_LaunchProfile::UOBP_LaunchProfile(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_Requests_User.h
// --------------------
//---GetUser---
void UOBP_GetUser::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_GetUser* UOBP_GetUser::GetUser(UObject* WorldContextObject, FString UserId)
{
	return NewObject<UOBP_GetUser>();
}
//---GetAccessToken---
void UOBP_GetAccessToken::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_GetAccessToken* UOBP_GetAccessToken::GetAccessToken(UObject* WorldContextObject)
{
	return NewObject<UOBP_GetAccessToken>();
}
//---GetLoggedInUser---
void UOBP_GetLoggedInUser::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_GetLoggedInUser* UOBP_GetLoggedInUser::GetLoggedInUser(UObject* WorldContextObject)
{
	return NewObject<UOBP_GetLoggedInUser>();
}
//---GetLoggedInUserFriends---
void UOBP_GetLoggedInUserFriends::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_GetLoggedInUserFriends* UOBP_GetLoggedInUserFriends::GetLoggedInUserFriends(UObject* WorldContextObject)
{
	return NewObject<UOBP_GetLoggedInUserFriends>();
}
//---GetLoggedInUserFriendsAndRooms---
void UOBP_GetLoggedInUserFriendsAndRooms::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_GetLoggedInUserFriendsAndRooms* UOBP_GetLoggedInUserFriendsAndRooms::GetLoggedInUserFriendsAndRooms(UObject* WorldContextObject)
{
	return NewObject<UOBP_GetLoggedInUserFriendsAndRooms>();
}
//---GetLoggedInUserRecentlyMetUsersAndRooms---
void UOBP_GetLoggedInUserRecentlyMetUsersAndRooms::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_GetLoggedInUserRecentlyMetUsersAndRooms* UOBP_GetLoggedInUserRecentlyMetUsersAndRooms::GetLoggedInUserRecentlyMetUsersAndRooms(UObject* WorldContextObject, UOBP_UserOptions* UserOptions)
{
	return NewObject<UOBP_GetLoggedInUserRecentlyMetUsersAndRooms>();
}
//---GetNextUserAndRoomArrayPage---
void UOBP_GetNextUserAndRoomArrayPage::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_GetNextUserAndRoomArrayPage* UOBP_GetNextUserAndRoomArrayPage::GetNextUserAndRoomArrayPage(UObject* WorldContextObject, UOBP_UserAndRoomArray* UserAndRoomArray)
{
	return NewObject<UOBP_GetNextUserAndRoomArrayPage>();
}
//---GetNextUserArrayPage---
void UOBP_GetNextUserArrayPage::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_GetNextUserArrayPage* UOBP_GetNextUserArrayPage::GetNextUserArrayPage(UObject* WorldContextObject, UOBP_UserArray* UserArray)
{
	return NewObject<UOBP_GetNextUserArrayPage>();
}
//---GetOrgScopedID---
void UOBP_GetOrgScopedID::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_GetOrgScopedID* UOBP_GetOrgScopedID::GetOrgScopedID(UObject* WorldContextObject, FString UserID)
{
	return NewObject<UOBP_GetOrgScopedID>();
}
//---GetSdkAccounts---
void UOBP_GetSdkAccounts::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_GetSdkAccounts* UOBP_GetSdkAccounts::GetSdkAccounts(UObject* WorldContextObject)
{
	return NewObject<UOBP_GetSdkAccounts>();
}
//---GetUserProof---
void UOBP_GetUserProof::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_GetUserProof* UOBP_GetUserProof::GetUserProof(UObject* WorldContextObject)
{
	return NewObject<UOBP_GetUserProof>();
}
//---LaunchFriendRequestFlow---
void UOBP_LaunchFriendRequestFlow::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_LaunchFriendRequestFlow* UOBP_LaunchFriendRequestFlow::LaunchFriendRequestFlow(UObject* WorldContextObject, FString UserID)
{
	return NewObject<UOBP_LaunchFriendRequestFlow>();
}
//---LaunchProfile---
void UOBP_LaunchProfile::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_LaunchProfile* UOBP_LaunchProfile::LaunchProfile(UObject* WorldContextObject, FString UserID)
{
	return NewObject<UOBP_LaunchProfile>();
}

// --------------------
// Leaderboard
// --------------------
//---GetEntries---
void UOBP_GetEntries::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_GetEntries* UOBP_GetEntries::GetEntries(UObject* WorldContextObject, FString LeaderboardName, int32 Limit, EOBP_LeaderboardFilterType Filter, EOBP_LeaderboardStartAt StartAt)
{
	return NewObject<UOBP_GetEntries>();
}
//---GetEntriesAfterRank---
void UOBP_GetEntriesAfterRank::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_GetEntriesAfterRank* UOBP_GetEntriesAfterRank::GetEntriesAfterRank(UObject* WorldContextObject, FString LeaderboardName, int32 Limit, int32 AfterRank)
{
	return NewObject<UOBP_GetEntriesAfterRank>();
}
//---GetEntriesByIds---
void UOBP_GetEntriesByIds::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_GetEntriesByIds* UOBP_GetEntriesByIds::GetEntriesByIds(UObject* WorldContextObject, FString LeaderboardName, int32 Limit, EOBP_LeaderboardStartAt StartAt, TArray<FString> UserIds, int32 UserIdLength)
{
	return NewObject<UOBP_GetEntriesByIds>();
}
//---GetNextEntries---
void UOBP_GetNextEntries::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_GetNextEntries* UOBP_GetNextEntries::GetNextEntries(UObject* WorldContextObject, UOBP_LeaderboardEntryArray* LeaderboardEntryArray)
{
	return NewObject<UOBP_GetNextEntries>();
}
//---GetPreviousEntries---
void UOBP_GetPreviousEntries::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_GetPreviousEntries* UOBP_GetPreviousEntries::GetPreviousEntries(UObject* WorldContextObject, UOBP_LeaderboardEntryArray* LeaderboardEntryArray)
{
	return NewObject<UOBP_GetPreviousEntries>();
}
//---WriteEntry---
void UOBP_WriteEntry::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_WriteEntry* UOBP_WriteEntry::WriteEntry(UObject* WorldContextObject, FString LeaderboardName, int32 Score, FString ExtraData, int32 ExtraDataLength, bool bForceUpdate)
{
	return NewObject<UOBP_WriteEntry>();
}

// --------------------
// RIch Presence
// --------------------
//---ClearRichPresence---
void UOBP_ClearRichPresence::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning ,TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_ClearRichPresence* UOBP_ClearRichPresence::ClearRichPresence(UObject* WorldContextObject)
{
	return NewObject<UOBP_ClearRichPresence>();
}
//---GetDestinations---
void UOBP_GetDestinations::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_GetDestinations* UOBP_GetDestinations::GetDestinations(UObject* WorldContextObject)
{
	return NewObject<UOBP_GetDestinations>();
}
//---GetNextDestinationArrayPage---
void UOBP_GetNextDestinationArrayPage::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_GetNextDestinationArrayPage* UOBP_GetNextDestinationArrayPage::GetNextDestinationArrayPage(UObject* WorldContextObject, UOBP_DestinationArray* DestinationArray)
{
	return NewObject<UOBP_GetNextDestinationArrayPage>();
}
//---SetRichPresence---
void UOBP_SetRichPresence::Activate()
{
	UE_LOG(LogOculusPlatformBP, Warning, TEXT("Deprecated function in use! Please update OculusPlatformBP request nodes to new versions!"));
}
UOBP_SetRichPresence* UOBP_SetRichPresence::SetRichPresence(UObject* WorldContextObject, UOBP_RichPresenceOptions* RichPresenceObject)
{
	return NewObject<UOBP_SetRichPresence>();
}