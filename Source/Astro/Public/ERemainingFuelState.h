#pragma once
#include "CoreMinimal.h"
#include "ERemainingFuelState.generated.h"

UENUM()
enum class ERemainingFuelState : uint8 {
    Plenty,
    LastTank,
    Critical,
};

