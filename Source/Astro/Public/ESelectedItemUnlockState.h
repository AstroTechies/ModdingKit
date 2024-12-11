#pragma once
#include "CoreMinimal.h"
#include "ESelectedItemUnlockState.generated.h"

UENUM(BlueprintType)
enum class ESelectedItemUnlockState : uint8 {
    Unlocked,
    Unlockable,
    Locked,
    Hacked,
};

