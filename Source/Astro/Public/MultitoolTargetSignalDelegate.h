#pragma once
#include "CoreMinimal.h"
#include "MultitoolTargetSignalDelegate.generated.h"

class APlayController;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultitoolTargetSignal, APlayController*, Controller);

