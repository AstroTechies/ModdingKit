#pragma once
#include "CoreMinimal.h"
#include "ESolarBodyIdentifier.generated.h"

UENUM(BlueprintType)
enum class ESolarBodyIdentifier : uint8 {
    None,
    Planet,
    GateStation,
    SolarControlRoom,
    OrbitalPlatform,
    CountPlusOne,
};

