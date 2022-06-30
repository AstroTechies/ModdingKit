#pragma once
#include "CoreMinimal.h"
#include "TooltipInteractionActiveDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTooltipInteractionActiveDelegate, FName, ActionOrAxisName);

