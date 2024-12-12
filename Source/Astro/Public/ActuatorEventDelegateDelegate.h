#pragma once
#include "CoreMinimal.h"
#include "SlotReference.h"
#include "ActuatorEventDelegateDelegate.generated.h"

class APlayController;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActuatorEventDelegate, FSlotReference, Slot, APlayController*, Instigator);

