#pragma once
#include "CoreMinimal.h"
#include "SpawnPointList.generated.h"

class UStorageChassisComponent;

USTRUCT(BlueprintType)
struct FSpawnPointList {
    GENERATED_BODY()
public:
    UPROPERTY(Export)
    TArray<UStorageChassisComponent*> SpawnPoints;
    
    ASTRO_API FSpawnPointList();
};

