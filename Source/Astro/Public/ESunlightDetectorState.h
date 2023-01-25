#pragma once
#include "CoreMinimal.h"
#include "ESunlightDetectorState.generated.h"

UENUM(BlueprintType)
enum class ESunlightDetectorState : uint8 {
    Unknown,
    AboveThreshold,
    BelowThreshold,
};

