#pragma once
#include "CoreMinimal.h"
#include "EnableSignalDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnableSignal, bool, Enable);

