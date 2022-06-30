#pragma once
#include "CoreMinimal.h"
#include "LockChangedEventMetadata.h"
#include "AstroDatumRef.h"
#include "LockableComponentSignalDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLockableComponentSignal, FAstroDatumRef, SignallingLockableComponentRef, const FLockChangedEventMetadata&, EventData);
