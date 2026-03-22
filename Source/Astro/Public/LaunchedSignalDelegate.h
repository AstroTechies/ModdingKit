#pragma once
#include "CoreMinimal.h"
#include "LaunchedSignalDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLaunchedSignal, float, LaunchLength);

