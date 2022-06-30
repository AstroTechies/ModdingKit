#pragma once
#include "CoreMinimal.h"
#include "TooltipStatusDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTooltipStatusDelegate, bool, hasValidTarget, int32, remainingCount, int32, maxCount);

