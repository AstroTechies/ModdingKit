#pragma once
#include "CoreMinimal.h"
#include "AstroPlayerIdOneTimeTooltipStatePair.h"
#include "AstroOneTimeTooltipState.generated.h"

USTRUCT(BlueprintType)
struct FAstroOneTimeTooltipState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FAstroPlayerIdOneTimeTooltipStatePair> PlayerIdOneTimeTooltipPairs;
    
    ASTRO_API FAstroOneTimeTooltipState();
};

