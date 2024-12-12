#pragma once
#include "CoreMinimal.h"
#include "ENoiseDimension.generated.h"

UENUM(BlueprintType)
enum class ENoiseDimension : uint8 {
    eND_1D,
    eND_2D,
    eND_3D,
    eND_4D,
};

