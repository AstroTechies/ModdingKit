#pragma once
#include "CoreMinimal.h"
#include "EFoliageDestructionBehavior.generated.h"

UENUM()
enum class EFoliageDestructionBehavior : uint8 {
    ThresholdCheck,
    AlwaysDestroy,
    NeverDestroy,
};

