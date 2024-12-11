#pragma once
#include "CoreMinimal.h"
#include "OnPlatformStoreUIClosedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlatformStoreUIClosed, const FString&, Category, const FString&, productId, bool, bPurchased);

