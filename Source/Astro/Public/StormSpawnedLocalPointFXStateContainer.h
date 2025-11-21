#pragma once
#include "CoreMinimal.h"
#include "StormSpawnedLocalPointFXStateData.h"
#include "StormSpawnedLocalPointFXStateContainer.generated.h"

USTRUCT(BlueprintType)
struct FStormSpawnedLocalPointFXStateContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float SpawnDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float TimeSinceLastSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool IsRubyHarvestPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float RubyHarvestRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FStormSpawnedLocalPointFXStateData> ParticleSystemInstancesData;
    
    ASTRO_API FStormSpawnedLocalPointFXStateContainer();
};

