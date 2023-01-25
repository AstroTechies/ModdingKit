#pragma once
#include "CoreMinimal.h"
#include "EExtractorOperationStage.generated.h"

UENUM(BlueprintType)
enum class EExtractorOperationStage : uint8 {
    Paused,
    Processing,
    Finished,
};

