#pragma once
#include "CoreMinimal.h"
#include "OnTerrainDeformationDensityDeltaReceivedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTerrainDeformationDensityDeltaReceived, float, DensityDelta);

