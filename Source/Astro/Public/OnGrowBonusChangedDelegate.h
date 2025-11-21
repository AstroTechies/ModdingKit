#pragma once
#include "CoreMinimal.h"
#include "OnGrowBonusChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGrowBonusChanged, bool, IsActive);

