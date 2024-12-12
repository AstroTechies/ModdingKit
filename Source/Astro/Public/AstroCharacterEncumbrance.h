#pragma once
#include "CoreMinimal.h"
#include "AstroCharacterEncumbrance.generated.h"

USTRUCT(BlueprintType)
struct FAstroCharacterEncumbrance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSpeedMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AirControlMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bSprintingSuppressed: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bJumpingSuppressed: 1;
    
    ASTRO_API FAstroCharacterEncumbrance();
};

