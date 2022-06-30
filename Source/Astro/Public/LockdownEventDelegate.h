#pragma once
#include "CoreMinimal.h"
#include "LockdownEventDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLockdownEvent, bool, lockdownEnabled);

