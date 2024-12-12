#pragma once
#include "CoreMinimal.h"
#include "LockdownEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLockdownEvent, bool, lockdownEnabled);

