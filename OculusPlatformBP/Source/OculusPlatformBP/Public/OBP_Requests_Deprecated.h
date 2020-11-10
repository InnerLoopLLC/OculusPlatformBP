// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_RichPresenceOptions.h"
#include "OBP_DestinationArray.h"
#include "OBP_LeaderboardEntryArray.h"
#include "OBP_User.h"
#include "OBP_UserArray.h"
#include "OBP_UserAndRoomArray.h"
#include "OBP_UserOptions.h"
#include "OBP_SdkAccountArray.h"
#include "OBP_Requests_Deprecated.generated.h"

// --------------------
//	THIS FILE CONSISTS OF DEPRECATED FUNCTIONS ONLY!
//	These allow projects that have not yet been updated to open without crashing. Mostly these are functions which have been moved and renamed.
//	This will all be deleted in a future update.
// --------------------

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetUser, UOBP_User*, User);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetAccessToken, FString, AccessToken);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetLoggedInUser, UOBP_User*, LoggedInUser);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetLoggedInUserFriends, UOBP_UserArray*, LoggedInUserFriends);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetLoggedInUserFriendsAndRooms, UOBP_UserAndRoomArray*, LoggedInUserFriendsAndRooms);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetLoggedInUserRecentlyMetUsersAndRooms, UOBP_UserAndRoomArray*, LoggedInUserRecentlyMetUsersAndRooms);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetNextUserAndRoomArrayPage, UOBP_UserAndRoomArray*, NextUserAndRoomArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetNextUserArrayPage, UOBP_UserArray*, NextUserArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetOrgScopedID, FString, OrgScopedID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetSdkAccounts, UOBP_SdkAccountArray*, SdkAccounts);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetUserProof, FString, UserProof);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLaunchFriendRequestFlow, bool, bDidCancel, bool, bDidSendRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLaunchProfile);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetEntries, UOBP_LeaderboardEntryArray*, LeaderboardEntryArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetEntriesAfterRank, UOBP_LeaderboardEntryArray*, LeaderboardEntryArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetEntriesByIds, UOBP_LeaderboardEntryArray*, LeaderboardEntryArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetNextEntries, UOBP_LeaderboardEntryArray*, LeaderboardEntryArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetPreviousEntries, UOBP_LeaderboardEntryArray*, LeaderboardEntryArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWriteEntry, bool, bDidUpdate);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FClearRichPresence);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetDestinations, UOBP_DestinationArray*, DestinationArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetDestinationsArrayPage, UOBP_DestinationArray*, DestinationArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSetRichPresence);

// --------------------
// OVR_Requests_User.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetUser : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetUser OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetUser OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetUser* GetUser(UObject* WorldContextObject, FString UserId);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetAccessToken : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetAccessToken OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetAccessToken OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetAccessToken* GetAccessToken(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetLoggedInUser : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetLoggedInUser OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetLoggedInUser OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetLoggedInUser* GetLoggedInUser(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetLoggedInUserFriends : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetLoggedInUserFriends OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetLoggedInUserFriends OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetLoggedInUserFriends* GetLoggedInUserFriends(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetLoggedInUserFriendsAndRooms : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetLoggedInUserFriendsAndRooms OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetLoggedInUserFriendsAndRooms OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetLoggedInUserFriendsAndRooms* GetLoggedInUserFriendsAndRooms(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetLoggedInUserRecentlyMetUsersAndRooms : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetLoggedInUserRecentlyMetUsersAndRooms OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetLoggedInUserRecentlyMetUsersAndRooms OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetLoggedInUserRecentlyMetUsersAndRooms* GetLoggedInUserRecentlyMetUsersAndRooms(UObject* WorldContextObject, UOBP_UserOptions* UserOptions);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetNextUserAndRoomArrayPage : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetNextUserAndRoomArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetNextUserAndRoomArrayPage OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetNextUserAndRoomArrayPage* GetNextUserAndRoomArrayPage(UObject* WorldContextObject, UOBP_UserAndRoomArray* UserAndRoomArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetNextUserArrayPage : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetNextUserArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetNextUserArrayPage OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetNextUserArrayPage* GetNextUserArrayPage(UObject* WorldContextObject, UOBP_UserArray* UserArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetOrgScopedID : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetOrgScopedID OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetOrgScopedID OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetOrgScopedID* GetOrgScopedID(UObject* WorldContextObject, FString UserID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetSdkAccounts : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetSdkAccounts OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetSdkAccounts OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetSdkAccounts* GetSdkAccounts(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetUserProof : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetUserProof OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetUserProof OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetUserProof* GetUserProof(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_LaunchFriendRequestFlow : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FLaunchFriendRequestFlow OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FLaunchFriendRequestFlow OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_LaunchFriendRequestFlow* LaunchFriendRequestFlow(UObject* WorldContextObject, FString UserID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_LaunchProfile : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FLaunchProfile OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FLaunchProfile OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_LaunchProfile* LaunchProfile(UObject* WorldContextObject, FString UserID);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};


// --------------------
// ovr_Requests_Leaderboard.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetEntries : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetEntries OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetEntries OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage="This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetEntries* GetEntries(UObject* WorldContextObject, FString LeaderboardName, int32 Limit, EOBP_LeaderboardFilterType Filter, EOBP_LeaderboardStartAt StartAt);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetEntriesAfterRank : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetEntriesAfterRank OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetEntriesAfterRank OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetEntriesAfterRank* GetEntriesAfterRank(UObject* WorldContextObject, FString LeaderboardName, int32 Limit, int32 AfterRank);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetEntriesByIds : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetEntriesByIds OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetEntriesByIds OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetEntriesByIds* GetEntriesByIds(UObject* WorldContextObject, FString LeaderboardName, int32 Limit, EOBP_LeaderboardStartAt StartAt, TArray<FString> UserIds, int32 UserIdLength);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetNextEntries : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetNextEntries OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetNextEntries OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetNextEntries* GetNextEntries(UObject* WorldContextObject, UOBP_LeaderboardEntryArray* LeaderboardEntryArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetPreviousEntries : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetPreviousEntries OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetPreviousEntries OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetPreviousEntries* GetPreviousEntries(UObject* WorldContextObject, UOBP_LeaderboardEntryArray* LeaderboardEntryArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_WriteEntry : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FWriteEntry OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FWriteEntry OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_WriteEntry* WriteEntry(UObject* WorldContextObject, FString LeaderboardName, int32 Score, FString ExtraData, int32 ExtraDataLength, bool bForceUpdate);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

// --------------------
// OVR_Requests_RichPresence.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_ClearRichPresence : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FClearRichPresence OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FClearRichPresence OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_ClearRichPresence* ClearRichPresence(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetDestinations : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetDestinations OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetDestinations OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetDestinations* GetDestinations(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_GetNextDestinationArrayPage : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FGetDestinationsArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FGetDestinationsArrayPage OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_GetNextDestinationArrayPage* GetNextDestinationArrayPage(UObject* WorldContextObject, UOBP_DestinationArray* DestinationArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_SetRichPresence : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FSetRichPresence OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FSetRichPresence OnFailure;

	/*WARNING: This function has been deprecated! Please update OculusPlatformBP request nodes to new versions! */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|Deprecated", meta = (DeprecatedFunction, DeprecationMessage = "This function has been deprecated! Please update OculusPlatformBP request nodes to new versions!", BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_SetRichPresence* SetRichPresence(UObject* WorldContextObject, UOBP_RichPresenceOptions* RichPresenceObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};