#pragma once
#include "CoreMinimal.h"
#include "EMiniPlanetIdentifier.generated.h"

UENUM(BlueprintType)
enum class EMiniPlanetIdentifier : uint8 {
    None,
    Terran,
    TerranMoon,
    Exotic,
    ExoticMoon,
    Arid,
    Tundra,
    Radiated,
    GlitchPlanet,
    Sphere,
    Cube,
    FlatBox,
    Torus,
    Cylinder,
    Cone,
    Asteroid,
    AsteroidField,
    Compound,
    Resin,
    Count,
};

