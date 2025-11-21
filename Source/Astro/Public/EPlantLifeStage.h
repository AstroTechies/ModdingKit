#pragma once
#include "CoreMinimal.h"
#include "EPlantLifeStage.generated.h"

UENUM(BlueprintType)
enum class EPlantLifeStage : uint8 {
    Seedling,
    Growing,
    FullyGrown,
    Wilting,
    Dead,
};

