#pragma once
#include "CoreMinimal.h"
#include "EDistanceFunction.generated.h"

UENUM(BlueprintType)
enum class EDistanceFunction : uint8 {
    Euclidean,
    Manhattan,
    Natural,
};

