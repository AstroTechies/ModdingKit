#pragma once
#include "CoreMinimal.h"
#include "OnUpdatePowerSinkDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdatePowerSink, float, updatedPower);

