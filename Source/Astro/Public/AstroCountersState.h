#pragma once
#include "CoreMinimal.h"
#include "AstroPlayerIdCounterPair.h"
#include "AstroCountersState.generated.h"

USTRUCT(BlueprintType)
struct FAstroCountersState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FAstroPlayerIdCounterPair> PlayerIdCounterPairs;
    
    ASTRO_API FAstroCountersState();
};

