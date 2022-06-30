#pragma once
#include "CoreMinimal.h"
#include "ESunlightDetectorState.generated.h"

UENUM()
enum class ESunlightDetectorState {
    Unknown,
    AboveThreshold,
    BelowThreshold,
};

