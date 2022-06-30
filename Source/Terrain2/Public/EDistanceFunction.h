#pragma once
#include "CoreMinimal.h"
#include "EDistanceFunction.generated.h"

UENUM()
enum class EDistanceFunction : uint8 {
    Euclidean,
    Manhattan,
    Natural,
};

