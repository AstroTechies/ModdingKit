#pragma once
#include "CoreMinimal.h"
#include "AstroActivityChain.generated.h"

class UAstroMissionDataAsset;

USTRUCT(BlueprintType)
struct FAstroActivityChain {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<UAstroMissionDataAsset*> MissionChains;
    
    ASTRO_API FAstroActivityChain();
};

