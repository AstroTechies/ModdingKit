#pragma once
#include "CoreMinimal.h"
#include "ENoiseDimension.generated.h"

UENUM()
enum class ENoiseDimension {
    eND_1D,
    eND_2D,
    eND_3D,
    eND_4D,
    eND_MAX UMETA(Hidden),
};

