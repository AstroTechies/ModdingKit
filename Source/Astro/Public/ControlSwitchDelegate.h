#pragma once
#include "CoreMinimal.h"
#include "ControlSwitchDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FControlSwitch, int32, Index);

