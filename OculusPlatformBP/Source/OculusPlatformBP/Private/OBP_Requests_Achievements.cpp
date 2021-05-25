// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Requests_Achievements.h"

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

// --------------------
// OVR_Requests_Achievements.h
// --------------------

//---AddCount---
void UOBP_Achievements_AddCount::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Achievements_AddCount(TCHAR_TO_ANSI(*AchievementName), Count);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
	else
	{
		OBP_SubsystemError("Achievements::AddCount");
		OnFailure.Broadcast("", false);
	}
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
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Achievements_AddFields(TCHAR_TO_ANSI(*AchievementName), TCHAR_TO_ANSI(*Fields));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
	else
	{
		OBP_SubsystemError("Achievements::AddFields");
		OnFailure.Broadcast("", false);
	}
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
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Achievements_GetAllDefinitions();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Achievements::GetAllDefinitions", Message);
				OnFailure.Broadcast(TArray<UOBP_AchievementDefinition*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Achievements_GetAllDefinitions)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got all definitions."));
					auto ThisAchievementDefinitionArray = NewObject<UOBP_AchievementDefinitionArray>();
					ThisAchievementDefinitionArray->ovrAchievementDefinitionArrayHandle = ovr_Message_GetAchievementDefinitionArray(Message);

					TArray<UOBP_AchievementDefinition*> ArrayOfAchievementDefinitions;

					for (size_t i = 0; i < ovr_AchievementDefinitionArray_GetSize(ThisAchievementDefinitionArray->ovrAchievementDefinitionArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_AchievementDefinition>();
						ThisElement->ovrAchievementDefinitionHandle = ovr_AchievementDefinitionArray_GetElement(ThisAchievementDefinitionArray->ovrAchievementDefinitionArrayHandle, i);
						ArrayOfAchievementDefinitions.Add(ThisElement);
					}

					OnSuccess.Broadcast(ArrayOfAchievementDefinitions, ThisAchievementDefinitionArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get all definitions."));
					OnFailure.Broadcast(TArray<UOBP_AchievementDefinition*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Achievements::GetAllDefinitions");
		OnFailure.Broadcast(TArray<UOBP_AchievementDefinition*>(), nullptr);
	}
}

UOBP_Achievements_GetAllDefinitions* UOBP_Achievements_GetAllDefinitions::GetAllDefinitions(UObject* WorldContextObject)
{
	return NewObject<UOBP_Achievements_GetAllDefinitions>();
}

//---GetAllProgress---
void UOBP_Achievements_GetAllProgress::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Achievements_GetAllProgress();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Achievements::GetAllProgress", Message);
				OnFailure.Broadcast(TArray<UOBP_AchievementProgress*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Achievements_GetAllProgress)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got all progress."));
					auto ThisAchievementProgressArray = NewObject<UOBP_AchievementProgressArray>();
					ThisAchievementProgressArray->ovrAchievementProgressArrayHandle = ovr_Message_GetAchievementProgressArray(Message);

					TArray<UOBP_AchievementProgress*> ArrayOfAchievementProgress;

					for (size_t i = 0; i < ovr_AchievementProgressArray_GetSize(ThisAchievementProgressArray->ovrAchievementProgressArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_AchievementProgress>();
						ThisElement->ovrAchievementProgressHandle = ovr_AchievementProgressArray_GetElement(ThisAchievementProgressArray->ovrAchievementProgressArrayHandle, i);
						ArrayOfAchievementProgress.Add(ThisElement);
					}

					OnSuccess.Broadcast(ArrayOfAchievementProgress, ThisAchievementProgressArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get all progress."));
					OnFailure.Broadcast(TArray<UOBP_AchievementProgress*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Achievements::GetAllProgress");
		OnFailure.Broadcast(TArray<UOBP_AchievementProgress*>(), nullptr);
	}
}

UOBP_Achievements_GetAllProgress* UOBP_Achievements_GetAllProgress::GetAllProgress(UObject* WorldContextObject)
{
	return NewObject<UOBP_Achievements_GetAllProgress>();
}

//---GetDefinitionsByName---
void UOBP_Achievements_GetDefinitionsByName::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		char* NamesArray = NULL; // initialize an array pointer
		NamesArray = new char[Names.Num()]; // dynamically size the array
		for (size_t i = 0; i < Names.Num(); i++)
		{
			NamesArray[i] = FCString::Atoi64(*Names[i]); // copy data to the new array
		}

		const char** NamesArray2 = NULL; // initialize an array pointer
		NamesArray2 = new const char* [Names.Num()]; // dynamically size the array
		for (size_t i = 0; i < Names.Num(); i++)
		{
			NamesArray2[i] = &NamesArray[i]; // copy data to the new array
		}

		ovrRequest RequestId = ovr_Achievements_GetDefinitionsByName(NamesArray2, Count);
		//ovrRequest RequestId = ovr_Achievements_GetDefinitionsByName(OBP_FStringArrayToChar(Names), Count);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Achievements::GetDefinitionsByName", Message);
				OnFailure.Broadcast(TArray<UOBP_AchievementDefinition*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Achievements_GetDefinitionsByName)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got achievement definitions by name."));
					auto ThisAchievementDefinitionArray = NewObject<UOBP_AchievementDefinitionArray>();
					ThisAchievementDefinitionArray->ovrAchievementDefinitionArrayHandle = ovr_Message_GetAchievementDefinitionArray(Message);

					TArray<UOBP_AchievementDefinition*> ArrayOfAchievementDefinitions;

					for (size_t i = 0; i < ovr_AchievementDefinitionArray_GetSize(ThisAchievementDefinitionArray->ovrAchievementDefinitionArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_AchievementDefinition>();
						ThisElement->ovrAchievementDefinitionHandle = ovr_AchievementDefinitionArray_GetElement(ThisAchievementDefinitionArray->ovrAchievementDefinitionArrayHandle, i);
						ArrayOfAchievementDefinitions.Add(ThisElement);
					}

					OnSuccess.Broadcast(ArrayOfAchievementDefinitions, ThisAchievementDefinitionArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get achievement definitions by name."));
					OnFailure.Broadcast(TArray<UOBP_AchievementDefinition*>(), nullptr);
				}
			}
		}));
		delete[] NamesArray; // this is important or memory will leak
		delete[] NamesArray2;
	}
	else
	{
		OBP_SubsystemError("Achievements::GetDefinitionsByName");
		OnFailure.Broadcast(TArray<UOBP_AchievementDefinition*>(), nullptr);
	}
}

UOBP_Achievements_GetDefinitionsByName* UOBP_Achievements_GetDefinitionsByName::GetDefinitionsByName(UObject* WorldContextObject, TArray<FString> Names, int32 Count)
{
	auto AchievementDefinitionByName = NewObject<UOBP_Achievements_GetDefinitionsByName>();
	AchievementDefinitionByName->Names = Names;
	AchievementDefinitionByName->Count = Count;
	return AchievementDefinitionByName;
}

//---GetNextAchievementDefinitionArrayPage---
void UOBP_Achievements_GetNextAchievementDefinitionArrayPage::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Achievements_GetNextAchievementDefinitionArrayPage(AchievementDefinitionArray->ovrAchievementDefinitionArrayHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Achievements::GetNextAchievementDefinitionArrayPage", Message);
				OnFailure.Broadcast(TArray<UOBP_AchievementDefinition*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Achievements_GetNextAchievementDefinitionArrayPage)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got next achievement definition array page."));
					auto ThisAchievementDefinitionArray = NewObject<UOBP_AchievementDefinitionArray>();
					ThisAchievementDefinitionArray->ovrAchievementDefinitionArrayHandle = ovr_Message_GetAchievementDefinitionArray(Message);
					
					TArray<UOBP_AchievementDefinition*> ArrayOfAchievementDefinitions;

					for (size_t i = 0; i < ovr_AchievementDefinitionArray_GetSize(ThisAchievementDefinitionArray->ovrAchievementDefinitionArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_AchievementDefinition>();
						ThisElement->ovrAchievementDefinitionHandle = ovr_AchievementDefinitionArray_GetElement(ThisAchievementDefinitionArray->ovrAchievementDefinitionArrayHandle, i);
						ArrayOfAchievementDefinitions.Add(ThisElement);
					}

					OnSuccess.Broadcast(ArrayOfAchievementDefinitions, ThisAchievementDefinitionArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get next achievement definition array page."));
					OnFailure.Broadcast(TArray<UOBP_AchievementDefinition*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Achievements::GetNextAchievementDefinitionArrayPage");
		OnFailure.Broadcast(TArray<UOBP_AchievementDefinition*>(), nullptr);
	}
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
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Achievements_GetNextAchievementProgressArrayPage(AchievementProgressArray->ovrAchievementProgressArrayHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Achievements::GetNextAchievementProgressArrayPage", Message);
				OnFailure.Broadcast(TArray<UOBP_AchievementProgress*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Achievements_GetNextAchievementProgressArrayPage)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got next achievement progress array page."));
					auto ThisAchievementProgressArray = NewObject<UOBP_AchievementProgressArray>();
					ThisAchievementProgressArray->ovrAchievementProgressArrayHandle = ovr_Message_GetAchievementProgressArray(Message);
					
					TArray<UOBP_AchievementProgress*> ArrayOfAchievementProgress;

					for (size_t i = 0; i < ovr_AchievementProgressArray_GetSize(ThisAchievementProgressArray->ovrAchievementProgressArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_AchievementProgress>();
						ThisElement->ovrAchievementProgressHandle = ovr_AchievementProgressArray_GetElement(ThisAchievementProgressArray->ovrAchievementProgressArrayHandle, i);
						ArrayOfAchievementProgress.Add(ThisElement);
					}

					OnSuccess.Broadcast(ArrayOfAchievementProgress, ThisAchievementProgressArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get next achievement progress array page."));
					OnFailure.Broadcast(TArray<UOBP_AchievementProgress*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("Achievements::GetNextAchievementProgressArrayPage");
		OnFailure.Broadcast(TArray<UOBP_AchievementProgress*>(), nullptr);
	}
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
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		char* NamesArray = NULL; // initialize an array pointer
		NamesArray = new char[Names.Num()]; // dynamically size the array
		for (size_t i = 0; i < Names.Num(); i++)
		{
			NamesArray[i] = FCString::Atoi64(*Names[i]); // copy data to the new array
		}

		const char** NamesArray2 = NULL; // initialize an array pointer
		NamesArray2 = new const char* [Names.Num()]; // dynamically size the array
		for (size_t i = 0; i < Names.Num(); i++)
		{
			NamesArray2[i] = &NamesArray[i]; // copy data to the new array
		}

		ovrRequest RequestId = ovr_Achievements_GetProgressByName(NamesArray2, Count);
		//ovrRequest RequestId = ovr_Achievements_GetProgressByName(OBP_FStringArrayToChar(Names), Count);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("Achievements::GetProgressByName", Message);
				OnFailure.Broadcast(TArray<UOBP_AchievementProgress*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_Achievements_GetProgressByName)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got achievement progress by name."));
					auto ThisAchievementProgressArray = NewObject<UOBP_AchievementProgressArray>();
					ThisAchievementProgressArray->ovrAchievementProgressArrayHandle = ovr_Message_GetAchievementProgressArray(Message);
					
					TArray<UOBP_AchievementProgress*> ArrayOfAchievementProgress;

					for (size_t i = 0; i < ovr_AchievementProgressArray_GetSize(ThisAchievementProgressArray->ovrAchievementProgressArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_AchievementProgress>();
						ThisElement->ovrAchievementProgressHandle = ovr_AchievementProgressArray_GetElement(ThisAchievementProgressArray->ovrAchievementProgressArrayHandle, i);
						ArrayOfAchievementProgress.Add(ThisElement);
					}

					OnSuccess.Broadcast(ArrayOfAchievementProgress, ThisAchievementProgressArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get achievement progress by name."));
					OnFailure.Broadcast(TArray<UOBP_AchievementProgress*>(), nullptr);
				}
			}
		}));
		delete[] NamesArray; // this is important or memory will leak
		delete[] NamesArray2;
	}
	else
	{
		OBP_SubsystemError("Achievements::GetProgressByName");
		OnFailure.Broadcast(TArray<UOBP_AchievementProgress*>(), nullptr);
	}
}

UOBP_Achievements_GetProgressByName* UOBP_Achievements_GetProgressByName::GetProgressByName(UObject* WorldContextObject, TArray<FString> Names, int32 Count)
{
	auto AchievementProgressByName = NewObject<UOBP_Achievements_GetProgressByName>();
	AchievementProgressByName->Names = Names;
	AchievementProgressByName->Count = Count;
	return AchievementProgressByName;
}

//---UnlockAchievement---
void UOBP_Achievements_Unlock::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_Achievements_Unlock(TCHAR_TO_ANSI(*AchievementName));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
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
	else
	{
		OBP_SubsystemError("Achievements::Unlock");
		OnFailure.Broadcast("", false);
	}
}

UOBP_Achievements_Unlock* UOBP_Achievements_Unlock::UnlockAchievement(UObject* WorldContextObject, FString AchievementName)
{
	auto AchievementToUnlock = NewObject<UOBP_Achievements_Unlock>();
	AchievementToUnlock->AchievementName = AchievementName;
	return AchievementToUnlock;
}