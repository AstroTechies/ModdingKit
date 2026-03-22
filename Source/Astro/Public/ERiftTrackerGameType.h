#pragma once
#include "CoreMinimal.h"
#include "ERiftTrackerGameType.generated.h"

UENUM(BlueprintType)
enum class ERiftTrackerGameType : uint8 {
    Eva,
    Gather,
    Position,
    Unbury,
    Random,
};

