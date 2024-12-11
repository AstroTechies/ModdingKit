#pragma once
#include "CoreMinimal.h"
#include "LockChangedEventMetadata.h"
#include "LockingMechanismSignalDelegate.generated.h"

class ULockingMechanism;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLockingMechanismSignal, ULockingMechanism*, SignallingLockingMechanism, const FLockChangedEventMetadata&, EventData);

