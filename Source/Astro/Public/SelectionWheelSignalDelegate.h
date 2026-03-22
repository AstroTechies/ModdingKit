#pragma once
#include "CoreMinimal.h"
#include "SelectionWheelSignalDelegate.generated.h"

class APlayController;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSelectionWheelSignal, bool, bIsOpened, APlayController*, Player);

