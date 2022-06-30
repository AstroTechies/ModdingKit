#pragma once
#include "CoreMinimal.h"
#include "EAtmosphericCondenserReadiness.generated.h"

UENUM()
enum class EAtmosphericCondenserReadiness {
    ReadyToCondense,
    OuputSlotFull,
    Invalid,
};

