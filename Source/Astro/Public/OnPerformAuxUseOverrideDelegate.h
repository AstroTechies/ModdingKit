#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "OnPerformAuxUseOverrideDelegate.generated.h"

class UActuatorComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPerformAuxUseOverride, TEnumAsByte<EInputEvent>, InputEvent, const UActuatorComponent*, InActuatorComponent);

