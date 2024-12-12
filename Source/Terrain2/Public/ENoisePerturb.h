#pragma once
#include "CoreMinimal.h"
#include "ENoisePerturb.generated.h"

UENUM(BlueprintType)
enum class ENoisePerturb : uint8 {
    None,
    Gradient,
    GradientFractal,
};

