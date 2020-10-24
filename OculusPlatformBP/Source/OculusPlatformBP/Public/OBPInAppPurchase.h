// OculusPlatformBP plugin by InnerLoop LLC 2020

#pragma once

#include "OculusPlatformBP.h"
#include "OBPInAppPurchase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FIAPConsumePurchase);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIAPGetNextProductArrayPage, UOBP_ProductArray*, ProductArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIAPGetNextPurchaseArrayPage, UOBP_PurchaseArray*, PurchaseArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIAPGetProductsBySKU, UOBP_ProductArray*, ProductArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIAPGetViewerPurchases, UOBP_PurchaseArray*, PurchaseArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIAPGetViewerPurchasesDurableCache, UOBP_PurchaseArray*, PurchaseArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIAPLaunchCheckoutFlow, UOBP_Purchase*, Purchase);

// --------------------
// ovr_Requests_IAP.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_IAP_ConsumePurchase : public UBlueprintAsyncActionBase
{

	GENERATED_UCLASS_BODY()

public:

	FString SKU;

	UPROPERTY(BlueprintAssignable)
		FIAPConsumePurchase OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FIAPConsumePurchase OnFailure;

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
		FIAPGetNextProductArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FIAPGetNextProductArrayPage OnFailure;

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
		FIAPGetNextPurchaseArrayPage OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FIAPGetNextPurchaseArrayPage OnFailure;

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
		FIAPGetProductsBySKU OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FIAPGetProductsBySKU OnFailure;

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
		FIAPGetViewerPurchases OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FIAPGetViewerPurchases OnFailure;

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
		FIAPGetViewerPurchasesDurableCache OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FIAPGetViewerPurchasesDurableCache OnFailure;

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
		FIAPLaunchCheckoutFlow OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FIAPLaunchCheckoutFlow OnFailure;

	/* Launch the checkout flow to purchase the existing product. Oculus Home tries handle and fix as many errors as possible. 
	Home returns the appropriate error message and how to resolveit, if possible. 
	Returns a purchase on success, empty purchase on cancel, and an error on error. */
	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Requests", meta = (BlueprintInternalUseOnly = "true", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
		static UOBP_IAP_LaunchCheckoutFlow* LaunchCheckoutFlow(UObject* WorldContextObject, FString SKU);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
};

// --------------------
// ovr_Product.h
// --------------------
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Product : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrProduct* ovrProductHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Product")
		FString GetDescription();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Product")
		FString GetFormattedPrice();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Product")
		FString GetName();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Product")
		FString GetSKU();
};

// --------------------
// ovr_ProductArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_ProductArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrProductArray* ovrProductArrayHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Product")
		UOBP_Product* GetElement(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Product")
		FString GetNextUrl();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Product")
		int32 GetSize();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Product")
		bool HasNextPage();
};

// --------------------
// ovr_Purchase.h
// --------------------
UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_Purchase : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrPurchase* ovrPurchaseHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Purchase")
		int32 GetExpirationTime();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Purchase")
		int32 GetGrantTime();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Purchase")
		FString GetPurchaseID();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Purchase")
		FString GetSKU();
};

// --------------------
// ovr_PurchaseArray.h
// --------------------

UCLASS(BlueprintType)
class OCULUSPLATFORMBP_API UOBP_PurchaseArray : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

public:

	ovrPurchaseArray* ovrPurchaseArrayHandle;

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Purchase")
		UOBP_Purchase* GetElement(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Purchase")
		FString GetNextUrl();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Purchase")
		int32 GetSize();

	UFUNCTION(BlueprintCallable, Category = "Oculus Platform BP|IAP|Purchase")
		bool HasNextPage();
};