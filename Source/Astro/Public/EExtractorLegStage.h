#pragma once
#include "CoreMinimal.h"
#include "EExtractorLegStage.generated.h"

UENUM(BlueprintType)
enum class EExtractorLegStage : uint8 {
    Extended,
    WaitForRetraction,
    Retracting,
    Retracted,
    WaitForExtension,
    Extending,
};

