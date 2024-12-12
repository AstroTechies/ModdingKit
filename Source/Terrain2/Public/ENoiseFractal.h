#pragma once
#include "CoreMinimal.h"
#include "ENoiseFractal.generated.h"

UENUM(BlueprintType)
enum class ENoiseFractal : uint8 {
    None,
    FBM,
    Billow,
    Rigid,
};

