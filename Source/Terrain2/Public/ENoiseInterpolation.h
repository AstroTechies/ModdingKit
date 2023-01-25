#pragma once
#include "CoreMinimal.h"
#include "ENoiseInterpolation.generated.h"

UENUM(BlueprintType)
enum class ENoiseInterpolation : uint8 {
    Linear,
    Hermite,
    Quintic,
};

