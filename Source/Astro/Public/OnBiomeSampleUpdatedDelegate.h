#pragma once
#include "CoreMinimal.h"
#include "OnBiomeSampleUpdatedDelegate.generated.h"

class UBiomeSamplerComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBiomeSampleUpdated, UBiomeSamplerComponent*, biomeSampler);

