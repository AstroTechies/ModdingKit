#pragma once
#include "CoreMinimal.h"
#include "EMicroTxnStoreTileState.generated.h"

UENUM(BlueprintType)
enum class EMicroTxnStoreTileState : uint8 {
    Available,
    Owned,
    Active,
    Locked,
    Filler,
};

