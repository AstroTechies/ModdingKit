#pragma once
#include "CoreMinimal.h"
#include "EMegastructureType.generated.h"

UENUM(BlueprintType)
enum class EMegastructureType : uint8 {
    None,
    Wreck,
    Biodome,
    LogisticsComplex,
    Museum,
    OrbitalPlatform,
};

