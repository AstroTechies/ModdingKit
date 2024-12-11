#pragma once
#include "CoreMinimal.h"
#include "OnTooltipWantsFocusChangedDelegate.generated.h"

class UTooltipComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTooltipWantsFocusChanged, UTooltipComponent*, TooltipComponent, bool, WantsFocus);

