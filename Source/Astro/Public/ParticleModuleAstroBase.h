#pragma once
#include "CoreMinimal.h"
#include "Particles/ParticleModule.h"
#include "ParticleModuleAstroBase.generated.h"

class ASolarBody;

UCLASS(Blueprintable, Abstract, EditInlineNew)
class ASTRO_API UParticleModuleAstroBase : public UParticleModule
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    uint8 bApplyOwnerScale : 1;

protected:
    UPROPERTY(Transient)
    TWeakObjectPtr<ASolarBody> CurrentSolarBody;

public:
    UParticleModuleAstroBase();
};
