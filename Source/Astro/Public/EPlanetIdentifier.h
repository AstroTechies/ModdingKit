#pragma once
#include "CoreMinimal.h"
#include "EPlanetIdentifier.generated.h"

UENUM(BlueprintType)
enum class EPlanetIdentifier : uint8 {
    None,
    Terran,
    TerranMoon,
    Exotic,
    ExoticMoon,
    Arid,
    Tundra,
    Radiated,
    GlitchPlanet,
    GlitchMoon,
    OrbitalPlatform,
    CountPlusOne,
};

