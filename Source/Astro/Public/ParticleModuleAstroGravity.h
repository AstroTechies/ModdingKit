#pragma once
#include "CoreMinimal.h"
#include "Distributions/DistributionFloat.h"
#include "ParticleModuleAstroBase.h"
#include "ParticleModuleAstroGravity.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UParticleModuleAstroGravity : public UParticleModuleAstroBase
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    uint8 bPerturbGravity : 1;

    UPROPERTY(EditAnywhere)
    FRawDistributionFloat PerturbAngleDegrees;

    UPROPERTY(EditAnywhere)
    FRawDistributionFloat GravityScale;

    UParticleModuleAstroGravity();
};
