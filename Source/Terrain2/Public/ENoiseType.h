#pragma once
#include "CoreMinimal.h"
#include "ENoiseType.generated.h"

UENUM(BlueprintType)
enum class ENoiseType : uint8 {
    Value,
    Perlin,
    Simplex,
    Cellular,
    White,
    Cubic,
};

