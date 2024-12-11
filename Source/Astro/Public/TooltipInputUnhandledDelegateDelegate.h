#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "TooltipInputUnhandledDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTooltipInputUnhandledDelegate, TEnumAsByte<EInputEvent>, InputType, FName, ActionOrAxisName);

