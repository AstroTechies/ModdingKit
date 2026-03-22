#pragma once
#include "CoreMinimal.h"
#include "InputDeviceChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInputDeviceChanged, bool, UsingGamepad);

