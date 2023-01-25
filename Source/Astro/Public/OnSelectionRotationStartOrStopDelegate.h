#pragma once
#include "CoreMinimal.h"
#include "OnSelectionRotationStartOrStopDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSelectionRotationStartOrStop, bool, IsRotating);

