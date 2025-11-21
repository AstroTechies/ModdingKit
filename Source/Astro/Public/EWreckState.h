#pragma once
#include "CoreMinimal.h"
#include "EWreckState.generated.h"

UENUM(BlueprintType)
enum class EWreckState : uint8 {
    Unloaded,
    Loaded,
    Launching,
    Restocking,
    Unpowered,
};

