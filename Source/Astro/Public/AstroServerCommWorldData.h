#pragma once
#include "CoreMinimal.h"
#include "PlayerList.h"
#include "AstroServerCommWorldData.generated.h"

USTRUCT(BlueprintType)
struct FAstroServerCommWorldData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerList PlayerListCache;
    
    ASTRO_API FAstroServerCommWorldData();
};

