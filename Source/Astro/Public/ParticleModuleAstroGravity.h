#pragma once
#include "CoreMinimal.h"
#include "Distributions/DistributionFloat.h"
#include "ParticleModuleAstroBase.h"
#include "ParticleModuleAstroGravity.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UParticleModuleAstroGravity : public UParticleModuleAstroBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bPerturbGravity: 1;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FRawDistributionFloat PerturbAngleDegrees;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FRawDistributionFloat GravityScale;
    
    UParticleModuleAstroGravity();

};

