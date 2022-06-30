#pragma once
#include "CoreMinimal.h"
#include "EFoliageDestructionBehavior.h"
#include "FoliageDestructionInfo.generated.h"

class UParticleSystem;

USTRUCT(BlueprintType)
struct FFoliageDestructionInfo {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    FName DestructionAudioEvent;
    
    UPROPERTY(EditDefaultsOnly)
    UParticleSystem* DestructionParticleEffect;
    
    UPROPERTY(EditDefaultsOnly)
    EFoliageDestructionBehavior FoliageDestructionBehavior;
    
    TERRAIN2_API FFoliageDestructionInfo();
};

