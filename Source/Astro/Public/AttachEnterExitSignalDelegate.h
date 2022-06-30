#pragma once
#include "CoreMinimal.h"
#include "AttachEnterExitSignalDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttachEnterExitSignal, bool, Entered);

