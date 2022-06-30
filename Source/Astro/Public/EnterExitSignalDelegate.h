#pragma once
#include "CoreMinimal.h"
#include "EnterExitSignalDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnterExitSignal, bool, Entered);

