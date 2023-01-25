#pragma once
#include "CoreMinimal.h"
#include "ERiftTrackerState.generated.h"

UENUM(BlueprintType)
enum class ERiftTrackerState : uint8 {
    Standby,
    Tracking,
    MemoryGame,
    MemoryGameComplete,
    CollectingMemory,
};

