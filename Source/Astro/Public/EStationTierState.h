#pragma once
#include "CoreMinimal.h"
#include "EStationTierState.generated.h"

UENUM(BlueprintType)
enum class EStationTierState : uint8 {
    T1,
    T2,
    T3,
    All,
};

