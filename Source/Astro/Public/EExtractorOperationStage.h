#pragma once
#include "CoreMinimal.h"
#include "EExtractorOperationStage.generated.h"

UENUM()
enum class EExtractorOperationStage : uint8 {
    Paused,
    Processing,
    Finished,
};

