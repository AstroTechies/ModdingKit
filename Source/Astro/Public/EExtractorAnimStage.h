#pragma once
#include "CoreMinimal.h"
#include "EExtractorAnimStage.generated.h"

UENUM()
enum class EExtractorAnimStage : uint8 {
    Holding,
    Falling,
    Resting,
    Rising,
    Reset,
    ClientSync,
};

