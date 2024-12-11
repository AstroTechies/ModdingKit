#pragma once
#include "CoreMinimal.h"
#include "EAtmosphericCondenserReadiness.generated.h"

UENUM(BlueprintType)
enum class EAtmosphericCondenserReadiness : uint8 {
    ReadyToCondense,
    OuputSlotFull,
    Invalid,
};

