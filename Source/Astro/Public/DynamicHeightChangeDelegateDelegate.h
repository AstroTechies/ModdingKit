#pragma once
#include "CoreMinimal.h"
#include "DynamicHeightChangeDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDynamicHeightChangeDelegate, float, Height);

