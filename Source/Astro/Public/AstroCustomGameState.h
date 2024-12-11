#pragma once
#include "CoreMinimal.h"
#include "AstroCountersState.h"
#include "AstroRespawnTokenState.h"
#include "AstroCustomGameState.generated.h"

USTRUCT(BlueprintType)
struct FAstroCustomGameState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroRespawnTokenState RespawnTokenState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroCountersState CountersState;
    
    ASTRO_API FAstroCustomGameState();
};

