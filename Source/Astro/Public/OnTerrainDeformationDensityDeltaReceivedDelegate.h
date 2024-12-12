#pragma once
#include "CoreMinimal.h"
#include "OnTerrainDeformationDensityDeltaReceivedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTerrainDeformationDensityDeltaReceived, float, DensityDelta);

