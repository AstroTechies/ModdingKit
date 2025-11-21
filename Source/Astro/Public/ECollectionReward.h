#pragma once
#include "CoreMinimal.h"
#include "ECollectionReward.generated.h"

UENUM(BlueprintType)
enum class ECollectionReward : uint8 {
    None,
    SoilEfficiencyIncrease,
    HardTerrainEffectivenessIncrease,
    RunSpeedIncrease,
    JumpHeightIncrease,
    ResearchSpeedIncrease,
    RoverSpeedIncrease,
    PrintSpeedIncrease,
    MAX = 32,
};

