#pragma once
#include "CoreMinimal.h"
#include "EPlacementMode.generated.h"

UENUM()
enum class EPlacementMode : int32 {
    RandomDistribution,
    RandomFixedCount,
    FixedLocations,
};

