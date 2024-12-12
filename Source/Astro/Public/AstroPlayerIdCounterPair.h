#pragma once
#include "CoreMinimal.h"
#include "AstroPlayerIdCounterPair.generated.h"

USTRUCT(BlueprintType)
struct FAstroPlayerIdCounterPair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString PlayerId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float CounterSeconds;
    
    ASTRO_API FAstroPlayerIdCounterPair();
};

