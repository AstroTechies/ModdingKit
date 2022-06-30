#pragma once
#include "CoreMinimal.h"
#include "ENoisePerturb.generated.h"

UENUM()
enum class ENoisePerturb {
    None,
    Gradient,
    GradientFractal,
};

