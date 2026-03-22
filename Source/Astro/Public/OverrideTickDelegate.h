#pragma once
#include "CoreMinimal.h"
#include "OverrideTickDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOverrideTick, float, DeltaTime);

