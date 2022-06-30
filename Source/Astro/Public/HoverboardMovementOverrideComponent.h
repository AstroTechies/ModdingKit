#pragma once
#include "CoreMinimal.h"
#include "AstroCharacterMovementOverrideComponent.h"
#include "HoverboardMovementOverrideComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UHoverboardMovementOverrideComponent : public UAstroCharacterMovementOverrideComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    float MaxSpeedScalar;

    UPROPERTY(EditDefaultsOnly)
    float MaxThrust;

    UPROPERTY(EditDefaultsOnly)
    float DismountDelayTime;

    UPROPERTY(EditDefaultsOnly)
    float FlatFallDamageScalar;

    UPROPERTY(EditDefaultsOnly)
    uint8 bFallDamageExponentialDecay : 1;

    UPROPERTY(EditDefaultsOnly)
    float MinImpactSlopeAngle;

    UPROPERTY(EditDefaultsOnly)
    uint8 bImmuneToFallDamage : 1;

    UHoverboardMovementOverrideComponent();
};
