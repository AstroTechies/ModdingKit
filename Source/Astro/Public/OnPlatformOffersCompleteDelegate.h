#pragma once
#include "CoreMinimal.h"
#include "OnPlatformOffersCompleteDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlatformOffersComplete, bool, bSuccess, bool, bShowHold);

