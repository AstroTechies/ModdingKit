#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "TooltipInputUnhandledDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTooltipInputUnhandledDelegate, EInputEvent, InputType, FName, ActionOrAxisName);

