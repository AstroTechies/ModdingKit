#pragma once
#include "CoreMinimal.h"
#include "EAstroTelemetryHistogram.generated.h"

UENUM(BlueprintType)
enum class EAstroTelemetryHistogram : uint8 {
    TerrianBatchLatency,
    COUNT,
};

