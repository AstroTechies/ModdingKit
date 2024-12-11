#pragma once
#include "CoreMinimal.h"
#include "MovementOverrideNetData.h"
#include "AstroCharacterActiveOverrides.generated.h"

USTRUCT(BlueprintType)
struct FAstroCharacterActiveOverrides {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMovementOverrideNetData> NetData;
    
public:
    ASTRO_API FAstroCharacterActiveOverrides();
};

