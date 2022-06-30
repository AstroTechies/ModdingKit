#pragma once
#include "CoreMinimal.h"
#include "ENoiseType.generated.h"

UENUM()
enum class ENoiseType : uint8 {
    Value,
    Perlin,
    Simplex,
    Cellular,
    White,
    Cubic,
};

