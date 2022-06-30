#pragma once
#include "CoreMinimal.h"
#include "OnPlatformOffersCompleteDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlatformOffersComplete, bool, bSuccess);

