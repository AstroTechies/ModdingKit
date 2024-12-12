#pragma once
#include "CoreMinimal.h"
#include "EAtmosphericCondenserState.generated.h"

UENUM(BlueprintType)
enum class EAtmosphericCondenserState : uint8 {
    Invalid,
    Inactive,
    Ready,
    Producing,
    Paused,
};

