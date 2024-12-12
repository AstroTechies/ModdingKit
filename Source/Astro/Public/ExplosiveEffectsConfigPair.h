#pragma once
#include "CoreMinimal.h"
#include "ExplosiveEffectsConfigPair.generated.h"

class UParticleSystem;

USTRUCT(BlueprintType)
struct FExplosiveEffectsConfigPair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinPower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* Effect;
    
    ASTRO_API FExplosiveEffectsConfigPair();
};

