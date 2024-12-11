#pragma once
#include "CoreMinimal.h"
#include "SelectionWheelOption.h"
#include "SelectionWheelEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSelectionWheelEvent, const FSelectionWheelOption&, Selection);

