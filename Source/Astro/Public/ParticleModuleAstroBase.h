#pragma once
#include "CoreMinimal.h"
#include "Particles/ParticleModule.h"
#include "ParticleModuleAstroBase.generated.h"

class ASolarBody;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ASTRO_API UParticleModuleAstroBase : public UParticleModule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bApplyOwnerScale: 1;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ASolarBody> CurrentSolarBody;
    
public:
    UParticleModuleAstroBase();

};

