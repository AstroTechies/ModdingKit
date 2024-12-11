#pragma once
#include "CoreMinimal.h"
#include "ERemainingFuelState.generated.h"

UENUM(BlueprintType)
enum class ERemainingFuelState : uint8 {
    Plenty,
    LastTank,
    Critical,
};

