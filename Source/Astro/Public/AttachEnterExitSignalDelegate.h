#pragma once
#include "CoreMinimal.h"
#include "AttachEnterExitSignalDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttachEnterExitSignal, bool, Entered);

