#pragma once
#include "CoreMinimal.h"
#include "ESelectedItemUnlockState.generated.h"

UENUM()
enum class ESelectedItemUnlockState : uint8 {
    Unlocked,
    Unlockable,
    Locked,
};

