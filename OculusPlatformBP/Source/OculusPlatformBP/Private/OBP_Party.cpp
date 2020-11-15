// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Party.h"

// --------------------
// Initializers
// --------------------

UOBP_Party::UOBP_Party(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_Party.h
// --------------------

UOBP_UserArray* UOBP_Party::GetInvitedUsers()
{
	auto InvitedUsers = NewObject<UOBP_UserArray>();
	InvitedUsers->ovrUserArrayHandle = ovr_Party_GetInvitedUsers(ovrPartyHandle);
	return InvitedUsers;
}

UOBP_User* UOBP_Party::GetLeader()
{
	auto PartyLeader = NewObject<UOBP_User>();
	PartyLeader->ovrUserHandle = ovr_Party_GetLeader(ovrPartyHandle);
	return PartyLeader;
}

UOBP_Room* UOBP_Party::GetRoom()
{
	auto PartyRoom = NewObject<UOBP_Room>();
	PartyRoom->ovrRoomHandle = ovr_Party_GetRoom(ovrPartyHandle);
	return PartyRoom;
}

UOBP_UserArray* UOBP_Party::GetUsers()
{
	auto UsersInParty = NewObject<UOBP_UserArray>();
	UsersInParty->ovrUserArrayHandle = ovr_Party_GetUsers(ovrPartyHandle);
	return UsersInParty;
}

FString UOBP_Party::GetID()
{
	return OBP_Int64ToFString(ovr_Party_GetID(ovrPartyHandle));
}
