#pragma once
#include "CoreMinimal.h"
#include "ENoiseInterpolation.generated.h"

UENUM()
enum class ENoiseInterpolation {
    Linear,
    Hermite,
    Quintic,
};

