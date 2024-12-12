#pragma once
#include "CoreMinimal.h"
#include "EnableSignalDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnableSignal, bool, Enable);

