#pragma once
#include "CoreMinimal.h"
#include "MouseZoomChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMouseZoomChanged, float, ZoomLevel);

