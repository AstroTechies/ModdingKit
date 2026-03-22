#pragma once
#include "CoreMinimal.h"
#include "OxygenLevelThresholdChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOxygenLevelThresholdChanged, float, NewLevel);

