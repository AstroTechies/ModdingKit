#pragma once
#include "CoreMinimal.h"
#include "AstroPlayerIdRespawnTokenCountPair.generated.h"

USTRUCT(BlueprintType)
struct FAstroPlayerIdRespawnTokenCountPair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString PlayerId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 RespawnTokenCount;
    
    ASTRO_API FAstroPlayerIdRespawnTokenCountPair();
};

