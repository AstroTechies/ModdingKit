#pragma once
#include "CoreMinimal.h"
#include "AstroCharacterMovementOverrideComponent.h"
#include "SnailBuffMovementOverrideComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API USnailBuffMovementOverrideComponent : public UAstroCharacterMovementOverrideComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    float AddedSprintMaxSpeedScalar;

    UPROPERTY(EditDefaultsOnly)
    float AddedJumpImpulse;

    UPROPERTY(EditDefaultsOnly)
    float AddedBoostImpulse;

    UPROPERTY(EditDefaultsOnly)
    float AddedJumpImpulseScalar;

    UPROPERTY(EditDefaultsOnly)
    uint8 bIgnoreCarryEncumbrance : 1;

    USnailBuffMovementOverrideComponent();
};
