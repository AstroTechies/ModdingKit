#pragma once
#include "CoreMinimal.h"
#include "StormSpawnConfigurationState.generated.h"

USTRUCT(BlueprintType)
struct FStormSpawnConfigurationState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float Lifetime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool ChooseClosestNonExcludedSpawnLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 MinSpawnLocationHistoricalExclusionCount;
    
    ASTRO_API FStormSpawnConfigurationState();
};

