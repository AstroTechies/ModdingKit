#pragma once
#include "CoreMinimal.h"
#include "AstroPlayerIdRespawnTokenCountPair.h"
#include "AstroRespawnTokenState.generated.h"

USTRUCT(BlueprintType)
struct FAstroRespawnTokenState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FAstroPlayerIdRespawnTokenCountPair> RespawnTokenCounts;
    
    ASTRO_API FAstroRespawnTokenState();
};

