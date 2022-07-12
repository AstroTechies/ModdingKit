#pragma once
#include "CoreMinimal.h"
#include "ParticleModuleAstroBase.h"
#include "Distributions/DistributionFloat.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=RawDistributionFloat -FallbackName=RawDistributionFloat
#include "ParticleModuleAstroGravity.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UParticleModuleAstroGravity : public UParticleModuleAstroBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bPerturbGravity: 1;
    
    UPROPERTY( EditAnywhere, meta=(AllowPrivateAccess=true))
    FRawDistributionFloat PerturbAngleDegrees;
    
    UPROPERTY( EditAnywhere, meta=(AllowPrivateAccess=true))
    FRawDistributionFloat GravityScale;
    
    UParticleModuleAstroGravity();
};

