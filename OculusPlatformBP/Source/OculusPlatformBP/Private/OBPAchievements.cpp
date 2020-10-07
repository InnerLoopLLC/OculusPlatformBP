// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBPAchievements.h"

// --------------------
// Initializers
// --------------------

UOBP_Achievements_AddCount::UOBP_Achievements_AddCount(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Achievements_AddFields::UOBP_Achievements_AddFields(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Achievements_GetAllDefinitions::UOBP_Achievements_GetAllDefinitions(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Achievements_GetAllProgress::UOBP_Achievements_GetAllProgress(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Achievements_GetDefinitionsByName::UOBP_Achievements_GetDefinitionsByName(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Achievements_GetNextAchievementDefinitionArrayPage::UOBP_Achievements_GetNextAchievementDefinitionArrayPage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Achievements_GetNextAchievementProgressArrayPage::UOBP_Achievements_GetNextAchievementProgressArrayPage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Achievements_GetProgressByName::UOBP_Achievements_GetProgressByName(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_Achievements_Unlock::UOBP_Achievements_Unlock(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_AchievementDefinition::UOBP_AchievementDefinition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_AchievementDefinitionArray::UOBP_AchievementDefinitionArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_AchievementProgress::UOBP_AchievementProgress(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_AchievementProgressArray::UOBP_AchievementProgressArray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// ovr_Requests_Achievements.h
// --------------------

//---AddCount---
void UOBP_Achievements_AddCount::Activate()
{
	ovrRequest RequestId = ovr_Achievements_AddCount(TCHAR_TO_ANSI(*AchievementName), Count);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("Achievements::AddCount", Message);
			OnFailure.Broadcast("", false);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_Achievements_AddCount)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully added count to achievement."));
				auto ThisAchievementName = ovr_AchievementUpdate_GetName(ovr_Message_GetAchievementUpdate(Message));
				auto bDidJustUnlock = ovr_AchievementUpdate_GetJustUnlocked(ovr_Message_GetAchievementUpdate(Message));
				OnSuccess.Broadcast(ThisAchievementName, bDidJustUnlock);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to add count to achievement."));
				OnFailure.Broadcast("", false);
			}
		}
	}));
}

UOBP_Achievements_AddCount* UOBP_Achievements_AddCount::AddCount(UObject* WorldContextObject, FString AchievementName, int32 Count)
{
	auto AchievementAddCount = NewObject<UOBP_Achievements_AddCount>();
	AchievementAddCount->AchievementName = AchievementName;
	AchievementAddCount->Count = Count;
	return AchievementAddCount;
}

//---AddFields---
void UOBP_Achievements_AddFields::Activate()
{
	ovrRequest RequestId = ovr_Achievements_AddFields(TCHAR_TO_ANSI(*AchievementName), TCHAR_TO_ANSI(*Fields));

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("Achievements::AddFields", Message);
			OnFailure.Broadcast("", false);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_Achievements_AddFields)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully added fields to achievement."));
				auto ThisAchievementName = ovr_AchievementUpdate_GetName(ovr_Message_GetAchievementUpdate(Message));
				auto bDidJustUnlock = ovr_AchievementUpdate_GetJustUnlocked(ovr_Message_GetAchievementUpdate(Message));
				OnSuccess.Broadcast(ThisAchievementName, bDidJustUnlock);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to add fields to achievement."));
				OnFailure.Broadcast("", false);
			}
		}
	}));
}

UOBP_Achievements_AddFields* UOBP_Achievements_AddFields::AddFields(UObject* WorldContextObject, FString AchievementName, FString Fields)
{
	auto AchievementAddFields = NewObject<UOBP_Achievements_AddFields>();
	AchievementAddFields->AchievementName = AchievementName;
	AchievementAddFields->Fields = Fields;
	return AchievementAddFields;
}

//---GetAllDefinitions---
void UOBP_Achievements_GetAllDefinitions::Activate()
{
	ovrRequest RequestId = ovr_Achievements_GetAllDefinitions();

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("Achievements::GetAllDefinitions", Message);
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_Achievements_GetAllDefinitions)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got all definitions."));
				auto ThisAchievementDefinitionArray = NewObject<UOBP_AchievementDefinitionArray>(); 
				ThisAchievementDefinitionArray->ovrAchievementDefinitionArrayHandle = ovr_Message_GetAchievementDefinitionArray(Message);
				OnSuccess.Broadcast(ThisAchievementDefinitionArray);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get all definitions."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
}

UOBP_Achievements_GetAllDefinitions* UOBP_Achievements_GetAllDefinitions::GetAllDefinitions(UObject* WorldContextObject)
{
	return NewObject<UOBP_Achievements_GetAllDefinitions>();
}

//---GetAllProgress---
void UOBP_Achievements_GetAllProgress::Activate()
{
	ovrRequest RequestId = ovr_Achievements_GetAllProgress();

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("Achievements::GetAllProgress", Message);
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_Achievements_GetAllProgress)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got all progress."));
				auto ThisAchievementProgressArray = NewObject<UOBP_AchievementProgressArray>();
				ThisAchievementProgressArray->ovrAchievementProgressArrayHandle = ovr_Message_GetAchievementProgressArray(Message);
				OnSuccess.Broadcast(ThisAchievementProgressArray);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get all progress."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
}

UOBP_Achievements_GetAllProgress* UOBP_Achievements_GetAllProgress::GetAllProgress(UObject* WorldContextObject)
{
	return NewObject<UOBP_Achievements_GetAllProgress>();
}

//---GetDefinitionsByName---
void UOBP_Achievements_GetDefinitionsByName::Activate()
{
	const char* ThisName = TCHAR_TO_ANSI(*Names);
	const char** ThisNewName = &ThisName;

	if(Count > 1)
	{ 
		Count = 1;
	}
	else if (Count < 0)
	{
		Count = 0;
	}

	ovrRequest RequestId = ovr_Achievements_GetDefinitionsByName(ThisNewName, Count);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("Achievements::GetDefinitionsByName", Message);
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_Achievements_GetDefinitionsByName)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got achievement definitions by name."));
				auto ThisAchievementDefinitionArray = NewObject<UOBP_AchievementDefinitionArray>();
				ThisAchievementDefinitionArray->ovrAchievementDefinitionArrayHandle = ovr_Message_GetAchievementDefinitionArray(Message);
				OnSuccess.Broadcast(ThisAchievementDefinitionArray);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get achievement definitions by name."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
}

UOBP_Achievements_GetDefinitionsByName* UOBP_Achievements_GetDefinitionsByName::GetDefinitionsByName(UObject* WorldContextObject, FString Names, int32 Count)
{
	auto AchievementDefinitionByName = NewObject<UOBP_Achievements_GetDefinitionsByName>();
	AchievementDefinitionByName->Names = Names;
	AchievementDefinitionByName->Count = Count;
	return AchievementDefinitionByName;
}

//---GetNextAchievementDefinitionArrayPage---
void UOBP_Achievements_GetNextAchievementDefinitionArrayPage::Activate()
{
	ovrRequest RequestId = ovr_Achievements_GetNextAchievementDefinitionArrayPage(AchievementDefinitionArray->ovrAchievementDefinitionArrayHandle);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("Achievements::GetNextAchievementDefinitionArrayPage", Message);
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_Achievements_GetNextAchievementDefinitionArrayPage)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got next achievement definition array page."));
				auto ThisAchievementDefinitionArray = NewObject<UOBP_AchievementDefinitionArray>();
				ThisAchievementDefinitionArray->ovrAchievementDefinitionArrayHandle = ovr_Message_GetAchievementDefinitionArray(Message);
				OnSuccess.Broadcast(ThisAchievementDefinitionArray);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get next achievement definition array page."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
}

UOBP_Achievements_GetNextAchievementDefinitionArrayPage* UOBP_Achievements_GetNextAchievementDefinitionArrayPage::GetNextAchievementDefinitionArrayPage(UObject* WorldContextObject, UOBP_AchievementDefinitionArray* AchievementDefinitionArray)
{
	auto NextAchievementDefinitionArrayPage = NewObject<UOBP_Achievements_GetNextAchievementDefinitionArrayPage>();
	NextAchievementDefinitionArrayPage->AchievementDefinitionArray = AchievementDefinitionArray;
	return NextAchievementDefinitionArrayPage;
}

//---GetNextAchievementProgressArrayPage---
void UOBP_Achievements_GetNextAchievementProgressArrayPage::Activate()
{
	ovrRequest RequestId = ovr_Achievements_GetNextAchievementProgressArrayPage(AchievementProgressArray->ovrAchievementProgressArrayHandle);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("Achievements::GetNextAchievementProgressArrayPage", Message);
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_Achievements_GetNextAchievementProgressArrayPage)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got next achievement progress array page."));
				auto ThisAchievementProgressArray = NewObject<UOBP_AchievementProgressArray>();
				ThisAchievementProgressArray->ovrAchievementProgressArrayHandle = ovr_Message_GetAchievementProgressArray(Message);
				OnSuccess.Broadcast(ThisAchievementProgressArray);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get next achievement progress array page."));
				OnFailure.Broadcast(nullptr);
			}
		}
	}));
}

UOBP_Achievements_GetNextAchievementProgressArrayPage* UOBP_Achievements_GetNextAchievementProgressArrayPage::GetNextAchievementProgressArrayPage(UObject* WorldContextObject, UOBP_AchievementProgressArray* AchievementProgressArray)
{
	auto NextAchievementProgressArrayPage = NewObject<UOBP_Achievements_GetNextAchievementProgressArrayPage>();
	NextAchievementProgressArrayPage->AchievementProgressArray = AchievementProgressArray;
	return NextAchievementProgressArrayPage;
}

//---GetProgressByName---
void UOBP_Achievements_GetProgressByName::Activate()
{
	const char* ThisName = TCHAR_TO_ANSI(*Names);
	const char** ThisNewName = &ThisName;

	if (Count > 1)
	{
		Count = 1;
	}
	else if (Count < 0)
	{
		Count = 0;
	}

	ovrRequest RequestId = ovr_Achievements_GetProgressByName(ThisNewName, Count);

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("Achievements::GetProgressByName", Message);
			OnFailure.Broadcast(nullptr);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_Achievements_GetProgressByName)
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got achievement progress by name."));
				auto ThisAchievementProgressArray = NewObject<UOBP_AchievementProgressArray>();
				ThisAchievementProgressArray->ovrAchievementProgressArrayHandle = ovr_Message_GetAchievementProgressArray(Message);
				OnSuccess.Broadcast(ThisAchievementProgressArray);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get achievement progress by name."));
				OnFailure.Broadcast(nullptr);
			}
		}
	})); 
}

UOBP_Achievements_GetProgressByName* UOBP_Achievements_GetProgressByName::GetProgressByName(UObject* WorldContextObject, FString Names, int32 Count)
{
	auto AchievementProgressByName = NewObject<UOBP_Achievements_GetProgressByName>();
	AchievementProgressByName->Names = Names;
	AchievementProgressByName->Count = Count;
	return AchievementProgressByName;
}

//---UnlockAchievement---
void UOBP_Achievements_Unlock::Activate()
{
	ovrRequest RequestId = ovr_Achievements_Unlock(TCHAR_TO_ANSI(*AchievementName));

	FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get());
	OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
		[this](ovrMessageHandle Message, bool bIsError)
	{
		if (bIsError)
		{
			OBP_MessageError("Achievements::Unlock", Message);
			OnFailure.Broadcast("", false);
		}
		else
		{
			ovrMessageType messageType = ovr_Message_GetType(Message);

			if (messageType == ovrMessage_Achievements_Unlock)
			{
				auto ThisAchievementName = ovr_AchievementUpdate_GetName(ovr_Message_GetAchievementUpdate(Message));
				auto bDidJustUnlock = ovr_AchievementUpdate_GetJustUnlocked(ovr_Message_GetAchievementUpdate(Message));
				auto UnlockString = bDidJustUnlock ? TEXT("TRUE") : TEXT("FALSE");
				auto LogString = FString("Successfully unlocked achievement: ") + ThisAchievementName + FString(" - Just unlocked: ") + UnlockString;
				UE_LOG(LogOculusPlatformBP, Log, TEXT("%s"), *LogString);
				OnSuccess.Broadcast(ThisAchievementName, bDidJustUnlock);
			}
			else
			{
				UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to unlock achievement."));
				OnFailure.Broadcast("", false);
			}
		}
	}));
}

UOBP_Achievements_Unlock* UOBP_Achievements_Unlock::UnlockAchievement(UObject* WorldContextObject, FString AchievementName)
{
	auto AchievementToUnlock = NewObject<UOBP_Achievements_Unlock>();
	AchievementToUnlock->AchievementName = AchievementName;
	return AchievementToUnlock;
}

// --------------------
// ovr_AchievementProgress.h
// --------------------

FString UOBP_AchievementDefinition::GetName()
{
	return ovr_AchievementDefinition_GetName(ovrAchievementDefinitionHandle);
}

int32 UOBP_AchievementDefinition::GetBitfieldLength()
{
	return ovr_AchievementDefinition_GetBitfieldLength(ovrAchievementDefinitionHandle);
}

int32 UOBP_AchievementDefinition::GetTarget()
{
	return ovr_AchievementDefinition_GetTarget(ovrAchievementDefinitionHandle);
}

EOBPAchievementType UOBP_AchievementDefinition::GetType()
{
	switch (ovr_AchievementDefinition_GetType(ovrAchievementDefinitionHandle))
	{
	case ovrAchievement_TypeUnknown:
		return EOBPAchievementType::Unknown;
	case ovrAchievement_TypeSimple:
		return EOBPAchievementType::Simple;
	case ovrAchievement_TypeBitfield:
		return EOBPAchievementType::Bitfield;
	case ovrAchievement_TypeCount:
		return EOBPAchievementType::Count;
	default:
		return EOBPAchievementType::Unknown;
	}
}

// --------------------
// ovr_AchievementDefinitionArray.h
// --------------------

UOBP_AchievementDefinition* UOBP_AchievementDefinitionArray::GetElement(int32 Index)
{
	auto AchievementDefinitionToGet = NewObject<UOBP_AchievementDefinition>();
	AchievementDefinitionToGet->ovrAchievementDefinitionHandle = ovr_AchievementDefinitionArray_GetElement(ovrAchievementDefinitionArrayHandle, Index);
	return AchievementDefinitionToGet;
}

FString UOBP_AchievementDefinitionArray::GetNextUrl()
{
	return ovr_AchievementDefinitionArray_GetNextUrl(ovrAchievementDefinitionArrayHandle);
}

int32 UOBP_AchievementDefinitionArray::GetSize()
{
	return ovr_AchievementDefinitionArray_GetSize(ovrAchievementDefinitionArrayHandle);
}

bool UOBP_AchievementDefinitionArray::HasNextPage()
{
	return ovr_AchievementDefinitionArray_HasNextPage(ovrAchievementDefinitionArrayHandle);
}

// --------------------
// ovr_AchievementProgress.h
// --------------------

FString UOBP_AchievementProgress::GetBitfield()
{
	return ovr_AchievementProgress_GetBitfield(ovrAchievementProgressHandle);
}

int32 UOBP_AchievementProgress::GetCount()
{
	return ovr_AchievementProgress_GetCount(ovrAchievementProgressHandle);
}

bool UOBP_AchievementProgress::GetIsUnlocked()
{
	return ovr_AchievementProgress_GetIsUnlocked(ovrAchievementProgressHandle);
}

FString UOBP_AchievementProgress::GetName()
{
	return ovr_AchievementProgress_GetName(ovrAchievementProgressHandle);
}

int32 UOBP_AchievementProgress::GetUnlockTime()
{
	return ovr_AchievementProgress_GetUnlockTime(ovrAchievementProgressHandle);
}

// --------------------
// ovr_AchievementProgressArray.h
// --------------------

UOBP_AchievementProgress* UOBP_AchievementProgressArray::GetElement(int32 Index)
{
	auto AchievementProgressToGet = NewObject<UOBP_AchievementProgress>();
	AchievementProgressToGet->ovrAchievementProgressHandle = ovr_AchievementProgressArray_GetElement(ovrAchievementProgressArrayHandle, Index);
	return AchievementProgressToGet;
}

FString UOBP_AchievementProgressArray::GetNextUrl()
{
	return ovr_AchievementProgressArray_GetNextUrl(ovrAchievementProgressArrayHandle);
}

int32 UOBP_AchievementProgressArray::GetSize()
{
	return ovr_AchievementProgressArray_GetSize(ovrAchievementProgressArrayHandle);
}

bool UOBP_AchievementProgressArray::HasNextPage()
{
	return ovr_AchievementProgressArray_HasNextPage(ovrAchievementProgressArrayHandle);
}