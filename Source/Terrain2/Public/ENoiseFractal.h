#pragma once
#include "CoreMinimal.h"
#include "ENoiseFractal.generated.h"

UENUM()
enum class ENoiseFractal {
    None,
    FBM,
    Billow,
    Rigid,
};

