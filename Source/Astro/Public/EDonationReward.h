#pragma once
#include "CoreMinimal.h"
#include "EDonationReward.generated.h"

UENUM(BlueprintType)
enum class EDonationReward : uint8 {
    None,
    BackpackBatteryCapacity,
    BackpackOxygenTankCapacity,
    BackpackBatteryRechargeSpeed,
    DrillSpeedIncrease,
    MAX = 32,
};

