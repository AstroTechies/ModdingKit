#pragma once
#include "CoreMinimal.h"
#include "StormsEnabledStateChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStormsEnabledStateChanged, bool, IsEnabled);

