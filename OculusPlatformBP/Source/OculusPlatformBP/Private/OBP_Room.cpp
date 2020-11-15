// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Room.h"

// --------------------
// Initializers
// --------------------

UOBP_Room::UOBP_Room(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// ovr_Room.h
// --------------------

UOBP_DataStore* UOBP_Room::GetDataStore()
{
	auto DataStoreToGet = NewObject<UOBP_DataStore>();
	DataStoreToGet->ovrDataStoreHandle = ovr_Room_GetDataStore(ovrRoomHandle);
	return DataStoreToGet;
}

UOBP_UserArray* UOBP_Room::GetInvitedUsers()
{
	auto UserArrayToGet = NewObject<UOBP_UserArray>();
	UserArrayToGet->ovrUserArrayHandle = ovr_Room_GetInvitedUsers(ovrRoomHandle);
	return UserArrayToGet;
}

/*
UOBP_MatchmakingEnqueuedUserArray* UOBP_Room::GetMatchedUsers()
{
	auto MatchmakingEnqueuedUserArrayToGet = NewObject<UOBP_MatchmakingEnqueuedUserArray>();
	MatchmakingEnqueuedUserArrayToGet->ovrMatchmakingEnqueuedUserArray = ovr_Room_GetMatchedUsers(ovrRoomHandle);
	return MatchmakingEnqueuedUserArrayToGet;
}*/

UOBP_User* UOBP_Room::GetOwner()
{
	auto UserToGet = NewObject<UOBP_User>();
	UserToGet->ovrUserHandle = ovr_Room_GetOwner(ovrRoomHandle);
	return UserToGet;
}

UOBP_TeamArray* UOBP_Room::GetTeams()
{
#if PLATFORM_MINOR_VERSION >= 40
	auto TeamsToGet = NewObject<UOBP_TeamArray>();
	TeamsToGet->ovrTeamArrayHandle = ovr_Room_GetTeams(ovrRoomHandle);
	return TeamsToGet;
#else
	OBP_PlatformVersionError("Room::GetTeams", "1.40");
	return nullptr;
#endif
}

UOBP_UserArray* UOBP_Room::GetUsers()
{
	auto UserArrayToGet = NewObject<UOBP_UserArray>();
	UserArrayToGet->ovrUserArrayHandle = ovr_Room_GetUsers(ovrRoomHandle);
	return UserArrayToGet;
}

FString UOBP_Room::GetApplicationID()
{
	return OBP_Int64ToFString(ovr_Room_GetApplicationID(ovrRoomHandle));
}

FString UOBP_Room::GetDescription()
{
	return ovr_Room_GetDescription(ovrRoomHandle);
}

FString UOBP_Room::GetID()
{
	return OBP_Int64ToFString(ovr_Room_GetID(ovrRoomHandle));
}

bool UOBP_Room::GetIsMembershipLocked()
{
	return ovr_Room_GetIsMembershipLocked(ovrRoomHandle);
}

EOBP_RoomJoinPolicy UOBP_Room::GetJoinPolicy()
{	
	switch (ovr_Room_GetJoinPolicy(ovrRoomHandle))
	{
	case ovrRoom_JoinPolicyNone:
		return EOBP_RoomJoinPolicy::None;
	case ovrRoom_JoinPolicyEveryone:
		return EOBP_RoomJoinPolicy::Everyone;
	case ovrRoom_JoinPolicyFriendsOfMembers:
		return EOBP_RoomJoinPolicy::FriendsOfMembers;
	case ovrRoom_JoinPolicyFriendsOfOwner:
		return EOBP_RoomJoinPolicy::FriendsOfOwner;
	case ovrRoom_JoinPolicyInvitedUsers:
		return EOBP_RoomJoinPolicy::InvitedUsers;
	case ovrRoom_JoinPolicyUnknown:
		return EOBP_RoomJoinPolicy::Unknown;
	default:
		return EOBP_RoomJoinPolicy::Unknown;
	}
}

EOBP_RoomJoinability UOBP_Room::GetJoinability()
{
	switch (ovr_Room_GetJoinability(ovrRoomHandle))
	{
	case ovrRoom_JoinabilityUnknown:
		return EOBP_RoomJoinability::Unknown;
	case ovrRoom_JoinabilityAreIn:
		return EOBP_RoomJoinability::AreIn;
	case ovrRoom_JoinabilityAreKicked:
		return EOBP_RoomJoinability::AreKicked;
	case ovrRoom_JoinabilityCanJoin:
		return EOBP_RoomJoinability::CanJoin;
	case ovrRoom_JoinabilityIsFull:
		return EOBP_RoomJoinability::IsFull;
	case ovrRoom_JoinabilityNoViewer:
		return EOBP_RoomJoinability::NoViewer;
	case ovrRoom_JoinabilityPolicyPrevents:
		return EOBP_RoomJoinability::PolicyPrevents;
	default:
		return EOBP_RoomJoinability::Unknown;
	}
}

int32 UOBP_Room::GetMaxUsers()
{
	return ovr_Room_GetMaxUsers(ovrRoomHandle);
}

FString UOBP_Room::GetName()
{
	return ovr_Room_GetName(ovrRoomHandle);
}

EOBP_RoomType UOBP_Room::GetType()
{
	return EOBP_RoomType::Unknown;
}

int32 UOBP_Room::GetVersion()
{
	return ovr_Room_GetVersion(ovrRoomHandle);
}