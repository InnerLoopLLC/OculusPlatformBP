// OculusPlatformBP plugin by InnerLoop LLC 2020

#include "OBP_Requests_IAP.h"

// --------------------
// Initializers
// --------------------

UOBP_IAP_ConsumePurchase::UOBP_IAP_ConsumePurchase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_IAP_GetNextProductArrayPage::UOBP_IAP_GetNextProductArrayPage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_IAP_GetNextPurchaseArrayPage::UOBP_IAP_GetNextPurchaseArrayPage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_IAP_GetProductsBySKU::UOBP_IAP_GetProductsBySKU(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_IAP_GetViewerPurchases::UOBP_IAP_GetViewerPurchases(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_IAP_GetViewerPurchasesDurableCache::UOBP_IAP_GetViewerPurchasesDurableCache(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOBP_IAP_LaunchCheckoutFlow::UOBP_IAP_LaunchCheckoutFlow(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// --------------------
// OVR_Requests_IAP.h
// --------------------

//---ConsumePurchase---
void UOBP_IAP_ConsumePurchase::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_IAP_ConsumePurchase(TCHAR_TO_ANSI(*SKU));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("IAP::ConsumePurchase", Message);
				OnFailure.Broadcast();
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_IAP_ConsumePurchase)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully consumed purchase."));
					OnSuccess.Broadcast();
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to consume purchase."));
					OnFailure.Broadcast();
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("IAP::ConsumePurchase");
		OnFailure.Broadcast();
	}
}

UOBP_IAP_ConsumePurchase* UOBP_IAP_ConsumePurchase::ConsumePurchase(UObject* WorldContextObject, FString SKU)
{
	auto PurchaseToConsume = NewObject<UOBP_IAP_ConsumePurchase>();
	PurchaseToConsume->SKU = SKU;
	return PurchaseToConsume;
}

//---GetNextProductArrayPage---
void UOBP_IAP_GetNextProductArrayPage::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_IAP_GetNextProductArrayPage(ProductArray->ovrProductArrayHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("IAP::GetNextProductArrayPage", Message);
				OnFailure.Broadcast(TArray<UOBP_Product*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_IAP_GetNextProductArrayPage)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got next product array page."));
					auto NextProductArray = NewObject<UOBP_ProductArray>();
					NextProductArray->ovrProductArrayHandle = ovr_Message_GetProductArray(Message);

					TArray<UOBP_Product*> Products;

					for (size_t i = 0; i < ovr_ProductArray_GetSize(NextProductArray->ovrProductArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_Product>();
						ThisElement->ovrProductHandle = ovr_ProductArray_GetElement(NextProductArray->ovrProductArrayHandle, i);
						Products.Add(ThisElement);
					}

					OnSuccess.Broadcast(Products, NextProductArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get next product array page."));
					OnFailure.Broadcast(TArray<UOBP_Product*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("IAP::GetNextProductArrayPage");
		OnFailure.Broadcast(TArray<UOBP_Product*>(), nullptr);
	}
}

UOBP_IAP_GetNextProductArrayPage* UOBP_IAP_GetNextProductArrayPage::GetNextProductArrayPage(UObject* WorldContextObject, UOBP_ProductArray* ProductArray)
{
	auto NextProductArrayPage = NewObject<UOBP_IAP_GetNextProductArrayPage>();
	NextProductArrayPage->ProductArray = ProductArray;
	return NextProductArrayPage;
}

//---GetNextPurchaseArrayPage---
void UOBP_IAP_GetNextPurchaseArrayPage::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_IAP_GetNextPurchaseArrayPage(PurchaseArray->ovrPurchaseArrayHandle);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("IAP::GetNextPurchaseArrayPage", Message);
				OnFailure.Broadcast(TArray<UOBP_Purchase*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_IAP_GetNextPurchaseArrayPage)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got next purchase array page."));
					auto NextPurchaseArray = NewObject<UOBP_PurchaseArray>();
					NextPurchaseArray->ovrPurchaseArrayHandle = ovr_Message_GetPurchaseArray(Message);

					TArray<UOBP_Purchase*> Purchases;

					for (size_t i = 0; i < ovr_PurchaseArray_GetSize(NextPurchaseArray->ovrPurchaseArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_Purchase>();
						ThisElement->ovrPurchaseHandle = ovr_PurchaseArray_GetElement(NextPurchaseArray->ovrPurchaseArrayHandle, i);
						Purchases.Add(ThisElement);
					}

					OnSuccess.Broadcast(Purchases, NextPurchaseArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get next purchase array page."));
					OnFailure.Broadcast(TArray<UOBP_Purchase*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("IAP::GetNextPurchaseArrayPage");
		OnFailure.Broadcast(TArray<UOBP_Purchase*>(), nullptr);
	}
}

UOBP_IAP_GetNextPurchaseArrayPage* UOBP_IAP_GetNextPurchaseArrayPage::GetNextPurchaseArrayPage(UObject* WorldContextObject, UOBP_PurchaseArray* PurchaseArray)
{
	auto NextPurchaseArrayPage = NewObject<UOBP_IAP_GetNextPurchaseArrayPage>();
	NextPurchaseArrayPage->PurchaseArray = PurchaseArray;
	return NextPurchaseArrayPage;
}

//---GetProductsBySKU---
void UOBP_IAP_GetProductsBySKU::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		char* SKUsArray = NULL; // initialize an array pointer
		SKUsArray = new char[ProductSKUs.Num()]; // dynamically size the array
		for (size_t i = 0; i < ProductSKUs.Num(); i++)
		{
			SKUsArray[i] = FCString::Atoi64(*ProductSKUs[i]); // copy data to the new array
		}

		const char** SKUsArray2 = NULL; // initialize an array pointer
		SKUsArray2 = new const char* [ProductSKUs.Num()]; // dynamically size the array
		for (size_t i = 0; i < ProductSKUs.Num(); i++)
		{
			SKUsArray2[i] = &SKUsArray[i]; // copy data to the new array
		}
		
		ovrRequest RequestId = ovr_IAP_GetProductsBySKU(SKUsArray2, Count);

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("IAP::GetProductsBySKU", Message);
				OnFailure.Broadcast(TArray<UOBP_Product*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_IAP_GetProductsBySKU)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got products by SKU."));
					auto NextProductArray = NewObject<UOBP_ProductArray>();
					NextProductArray->ovrProductArrayHandle = ovr_Message_GetProductArray(Message);
					
					TArray<UOBP_Product*> Products;

					for (size_t i = 0; i < ovr_ProductArray_GetSize(NextProductArray->ovrProductArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_Product>();
						ThisElement->ovrProductHandle = ovr_ProductArray_GetElement(NextProductArray->ovrProductArrayHandle, i);
						Products.Add(ThisElement);
					}

					OnSuccess.Broadcast(Products, NextProductArray);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get products by SKU."));
					OnFailure.Broadcast(TArray<UOBP_Product*>(), nullptr);
				}
			}
		}));
		delete[] SKUsArray;
		delete[] SKUsArray2;
	}
	else
	{
		OBP_SubsystemError("IAP::GetProductsBySKU");
		OnFailure.Broadcast(TArray<UOBP_Product*>(), nullptr);
	}
}

UOBP_IAP_GetProductsBySKU* UOBP_IAP_GetProductsBySKU::GetProductsBySKU(UObject* WorldContextObject, TArray<FString> ProductSKUs, int32 Count)
{
	auto GetProductsBySKU = NewObject<UOBP_IAP_GetProductsBySKU>();
	GetProductsBySKU->ProductSKUs = ProductSKUs;
	GetProductsBySKU->Count = Count;
	return GetProductsBySKU;
}

//---GetViewerPurchases---
void UOBP_IAP_GetViewerPurchases::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_IAP_GetViewerPurchases();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("IAP::GetViewerPurchases", Message);
				OnFailure.Broadcast(TArray<UOBP_Purchase*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_IAP_GetViewerPurchases)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got viewer purchases."));
					auto ViewerPurchases = NewObject<UOBP_PurchaseArray>();
					ViewerPurchases->ovrPurchaseArrayHandle = ovr_Message_GetPurchaseArray(Message);
					
					TArray<UOBP_Purchase*> Purchases;

					for (size_t i = 0; i < ovr_PurchaseArray_GetSize(ViewerPurchases->ovrPurchaseArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_Purchase>();
						ThisElement->ovrPurchaseHandle = ovr_PurchaseArray_GetElement(ViewerPurchases->ovrPurchaseArrayHandle, i);
						Purchases.Add(ThisElement);
					}

					OnSuccess.Broadcast(Purchases, ViewerPurchases);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get viewer purchases."));
					OnFailure.Broadcast(TArray<UOBP_Purchase*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("IAP::GetViewerPurchases");
		OnFailure.Broadcast(TArray<UOBP_Purchase*>(), nullptr);
	}
}

UOBP_IAP_GetViewerPurchases* UOBP_IAP_GetViewerPurchases::GetViewerPurchases(UObject* WorldContextObject)
{
	return NewObject<UOBP_IAP_GetViewerPurchases>();
}

//---GetViewerPurchasesDurableCache---
void UOBP_IAP_GetViewerPurchasesDurableCache::Activate()
{
#if PLATFORM_MINOR_VERSION >= 40
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_IAP_GetViewerPurchasesDurableCache();

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("IAP::GetViewerPurchasesDurableCache", Message);
				OnFailure.Broadcast(TArray<UOBP_Purchase*>(), nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_IAP_GetViewerPurchasesDurableCache)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully got viewer purchases from durable cache."));
					auto ViewerPurchasesDurableCache = NewObject<UOBP_PurchaseArray>();
					ViewerPurchasesDurableCache->ovrPurchaseArrayHandle = ovr_Message_GetPurchaseArray(Message);
					
					TArray<UOBP_Purchase*> Purchases;

					for (size_t i = 0; i < ovr_PurchaseArray_GetSize(ViewerPurchasesDurableCache->ovrPurchaseArrayHandle); i++)
					{
						auto ThisElement = NewObject<UOBP_Purchase>();
						ThisElement->ovrPurchaseHandle = ovr_PurchaseArray_GetElement(ViewerPurchasesDurableCache->ovrPurchaseArrayHandle, i);
						Purchases.Add(ThisElement);
					}

					OnSuccess.Broadcast(Purchases, ViewerPurchasesDurableCache);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to get viewer purchases from durable cache."));
					OnFailure.Broadcast(TArray<UOBP_Purchase*>(), nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("IAP::GetViewerPurchasesDurableCache");
		OnFailure.Broadcast(TArray<UOBP_Purchase*>(), nullptr);
	}
#else
	OBP_PlatformVersionError("IAP::GetViewerPurchasesDurableCache", "1.40");
	OnFailure.Broadcast(TArray<UOBP_Purchase*>(), nullptr);
#endif
}

UOBP_IAP_GetViewerPurchasesDurableCache* UOBP_IAP_GetViewerPurchasesDurableCache::GetViewerPurchasesDurableCache(UObject* WorldContextObject)
{
	return NewObject<UOBP_IAP_GetViewerPurchasesDurableCache>();
}

//---LaunchCheckoutFlow---
void UOBP_IAP_LaunchCheckoutFlow::Activate()
{
	auto OculusIdentityInterface = Online::GetIdentityInterface(OCULUS_SUBSYSTEM);

	if (OculusIdentityInterface.IsValid())
	{
		ovrRequest RequestId = ovr_IAP_LaunchCheckoutFlow(TCHAR_TO_ANSI(*SKU));

		FOnlineSubsystemOculus* OSS = static_cast<FOnlineSubsystemOculus*>(IOnlineSubsystem::Get(OCULUS_SUBSYSTEM));
		OSS->AddRequestDelegate(RequestId, FOculusMessageOnCompleteDelegate::CreateLambda(
			[this](ovrMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				OBP_MessageError("IAP::LaunchCheckoutFlow", Message);
				OnFailure.Broadcast(nullptr);
			}
			else
			{
				ovrMessageType messageType = ovr_Message_GetType(Message);

				if (messageType == ovrMessage_IAP_LaunchCheckoutFlow)
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Successfully launched checkout flow."));
					auto Purchase = NewObject<UOBP_Purchase>();
					Purchase->ovrPurchaseHandle = ovr_Message_GetPurchase(Message);
					OnSuccess.Broadcast(Purchase);
				}
				else
				{
					UE_LOG(LogOculusPlatformBP, Log, TEXT("Failed to launch checkout flow."));
					OnFailure.Broadcast(nullptr);
				}
			}
		}));
	}
	else
	{
		OBP_SubsystemError("IAP::LaunchCheckoutFlow");
		OnFailure.Broadcast(nullptr);
	}
}

UOBP_IAP_LaunchCheckoutFlow* UOBP_IAP_LaunchCheckoutFlow::LaunchCheckoutFlow(UObject* WorldContextObject, FString SKU)
{
	auto LaunchCheckoutFlow = NewObject<UOBP_IAP_LaunchCheckoutFlow>();
	LaunchCheckoutFlow->SKU = SKU;
	return LaunchCheckoutFlow;
}