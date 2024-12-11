#pragma once
#include "CoreMinimal.h"
#include "EScannerTargetDistance.generated.h"

UENUM(BlueprintType)
enum class EScannerTargetDistance : uint8 {
    NoTarget,
    LongRange,
    MidRange,
    ShortRange,
};

