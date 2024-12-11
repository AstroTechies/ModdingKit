#pragma once
#include "CoreMinimal.h"
#include "LightValuesChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLightValuesChanged, float, Intensity);

