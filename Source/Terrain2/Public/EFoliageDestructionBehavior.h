#pragma once
#include "CoreMinimal.h"
#include "EFoliageDestructionBehavior.generated.h"

UENUM(BlueprintType)
enum class EFoliageDestructionBehavior : uint8 {
    ThresholdCheck,
    AlwaysDestroy,
    NeverDestroy,
};

