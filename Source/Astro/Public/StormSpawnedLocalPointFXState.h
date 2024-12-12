#pragma once
#include "CoreMinimal.h"
#include "StormSpawnedLocalPointFXData.h"
#include "StormSpawnedLocalPointFXState.generated.h"

USTRUCT(BlueprintType)
struct FStormSpawnedLocalPointFXState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeSinceLastSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsRubyHarvestPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RubyHarvestRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStormSpawnedLocalPointFXData> ParticleSystemInstancesData;
    
    ASTRO_API FStormSpawnedLocalPointFXState();
};

