#pragma once
#include "CoreMinimal.h"
#include "AstroCharacterEncumbrance.generated.h"

USTRUCT(BlueprintType)
struct FAstroCharacterEncumbrance {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    float MaxSpeedMultiplier;
    
    UPROPERTY(EditDefaultsOnly)
    float AirControlMultiplier;
    
    UPROPERTY(EditDefaultsOnly)
    uint8 bSprintingSuppressed: 1;
    
    UPROPERTY(EditDefaultsOnly)
    uint8 bJumpingSuppressed: 1;
    
    ASTRO_API FAstroCharacterEncumbrance();
};

