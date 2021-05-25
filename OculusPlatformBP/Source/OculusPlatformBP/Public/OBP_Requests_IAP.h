// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBP_ProductArray.h"
#include "OBP_Purchase.h"
#include "OBP_PurchaseArray.h"
#include "OBP_Requests_IAP.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FIAP_ConsumePurchase);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FIAP_GetNextProductArrayPage, const TArray<UOBP_Product*>&, Products, UOBP_ProductArray*, ProductArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FIAP_GetNextPurchaseArrayPage, const TArray<UOBP_Purchase*>&, Purchases, UOBP_PurchaseArray*, PurchaseArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FIAP_GetProductsBySKU, const TArray<UOBP_Product*>&, Products, UOBP_ProductArray*, ProductArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FIAP_GetViewerPurchases, const TArray<UOBP_Purchase*>&, Purchases, UOBP_PurchaseArray*, PurchaseArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FIAP_GetViewerPurchasesDurableCache, const TArray<UOBP_Purchase*>&, Purchases, UOBP_PurchaseArray*, PurchaseArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIAP_LaunchCheckoutFlow, UOBP_Purchase*, Purchase);

// --------------------
// OVR_Requests_IAP.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_IAP_ConsumePurchase : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString SKU;

	UPROPERTY(BlueprintAssignable)
		FIAP_ConsumePurchase OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FIAP_ConsumePurchase OnFailure;

	/* Allow the consumable IAP product to be purchased again. Conceptually, this indicates that the item was used or consumed. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_IAP_ConsumePurchase* ConsumePurchase(UObject* WorldContextObject, FString SKU);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_IAP_GetNextProductArrayPage : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_ProductArray* ProductArray;

	UPROPERTY(BlueprintAssignable)
		FIAP_GetNextProductArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FIAP_GetNextProductArrayPage OnFailure;

	/* Get the next page of entries */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_IAP_GetNextProductArrayPage* GetNextProductArrayPage(UObject* WorldContextObject, UOBP_ProductArray* ProductArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_IAP_GetNextPurchaseArrayPage : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UOBP_PurchaseArray* PurchaseArray;

	UPROPERTY(BlueprintAssignable)
		FIAP_GetNextPurchaseArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FIAP_GetNextPurchaseArrayPage OnFailure;

	/* Get the next page of entries */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_IAP_GetNextPurchaseArrayPage* GetNextPurchaseArrayPage(UObject* WorldContextObject, UOBP_PurchaseArray* PurchaseArray);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_IAP_GetProductsBySKU : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	TArray<FString> ProductSKUs;
	int32 Count;

		UPROPERTY(BlueprintAssignable)
		FIAP_GetProductsBySKU OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FIAP_GetProductsBySKU OnFailure;

	/* Retrieve a list of IAP products that can be purchased. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_IAP_GetProductsBySKU* GetProductsBySKU(UObject* WorldContextObject, TArray<FString> ProductSKUs, int32 Count);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_IAP_GetViewerPurchases : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FIAP_GetViewerPurchases OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FIAP_GetViewerPurchases OnFailure;

	/* Retrieve a list of Purchase that the Logged-In-User has made. 
	This list will also contain consumable purchases that have not been consumed. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_IAP_GetViewerPurchases* GetViewerPurchases(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_IAP_GetViewerPurchasesDurableCache : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FIAP_GetViewerPurchasesDurableCache OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FIAP_GetViewerPurchasesDurableCache OnFailure;

	/* Retrieve a list of Purchase that the Logged-In-User has made. 
	This list will only contain durable purchase (non-consumable) and is populated from a device cache.
	It is recommended in all cases to use ovr_User_GetViewerPurchases first and only check the cache if that fails. 
	Requires OculusPlatfromSDK 1.40 or later*/
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_IAP_GetViewerPurchasesDurableCache* GetViewerPurchasesDurableCache(UObject* WorldContextObject);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_IAP_LaunchCheckoutFlow : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString SKU;

	UPROPERTY(BlueprintAssignable)
		FIAP_LaunchCheckoutFlow OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FIAP_LaunchCheckoutFlow OnFailure;

	/* Launch the checkout flow to purchase the existing product. Oculus Home tries handle and fix as many errors as possible. 
	Home returns the appropriate error message and how to resolveit, if possible. 
	Returns a purchase on success, empty purchase on cancel, and an error on error. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_IAP_LaunchCheckoutFlow* LaunchCheckoutFlow(UObject* WorldContextObject, FString SKU);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};