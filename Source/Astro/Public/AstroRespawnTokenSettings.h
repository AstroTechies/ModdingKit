#pragma once
#include "CoreMinimal.h"
#include "AstroRespawnTokenSettings.generated.h"

USTRUCT(BlueprintType)
struct FAstroRespawnTokenSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool RespawnTokensActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool RespawnTokensAreShared;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 InitialRespawnTokenCount;
    
    ASTRO_API FAstroRespawnTokenSettings();
};

