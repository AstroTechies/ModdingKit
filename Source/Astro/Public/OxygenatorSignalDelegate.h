#pragma once
#include "CoreMinimal.h"
#include "OxygenatorSignalDelegate.generated.h"

class UOxygenatorComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOxygenatorSignal, UOxygenatorComponent*, oxygenator);

