#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EInputEvent -FallbackName=EInputEvent
#include "TooltipInputUnhandledDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTooltipInputUnhandledDelegate, TEnumAsByte<EInputEvent>, InputType, FName, ActionOrAxisName);

