#pragma once
#include "CoreMinimal.h"
#include "BodySelectionSignalDelegate.generated.h"

class ASolarBody;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBodySelectionSignal, ASolarBody*, Body);

