#pragma once
#include "CoreMinimal.h"
#include "FlightModeMovementOverrideComponent.h"
#include "OrbitalPlatformMovementOverrideComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UOrbitalPlatformMovementOverrideComponent : public UFlightModeMovementOverrideComponent {
    GENERATED_BODY()
public:
    UOrbitalPlatformMovementOverrideComponent(const FObjectInitializer& ObjectInitializer);

};

