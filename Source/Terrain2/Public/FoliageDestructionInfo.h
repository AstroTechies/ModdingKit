#pragma once
#include "CoreMinimal.h"
#include "EFoliageDestructionBehavior.h"
#include "FoliageDestructionInfo.generated.h"

class UParticleSystem;

USTRUCT(BlueprintType)
struct FFoliageDestructionInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DestructionAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* DestructionParticleEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFoliageDestructionBehavior FoliageDestructionBehavior;
    
    TERRAIN2_API FFoliageDestructionInfo();
};

