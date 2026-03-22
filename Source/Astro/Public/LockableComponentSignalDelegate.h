#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "LockChangedEventMetadata.h"
#include "LockableComponentSignalDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLockableComponentSignal, FAstroDatumRef, SignallingLockableComponentRef, const FLockChangedEventMetadata&, EventData);

