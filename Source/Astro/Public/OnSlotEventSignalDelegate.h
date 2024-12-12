#pragma once
#include "CoreMinimal.h"
#include "OnSlotEventSignalDelegate.generated.h"

class APhysicalItem;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSlotEventSignal, APhysicalItem*, Item);

