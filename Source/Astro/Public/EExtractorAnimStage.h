#pragma once
#include "CoreMinimal.h"
#include "EExtractorAnimStage.generated.h"

UENUM(BlueprintType)
enum class EExtractorAnimStage : uint8 {
    Holding,
    Falling,
    Resting,
    Rising,
    Reset,
    ClientSync,
};

