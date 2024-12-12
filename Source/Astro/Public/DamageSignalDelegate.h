#pragma once
#include "CoreMinimal.h"
#include "DamageSignalDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDamageSignal, float, Amount);

