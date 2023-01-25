#pragma once
#include "CoreMinimal.h"
#include "SpawnPointList.generated.h"

class UStorageChassisComponent;

USTRUCT(BlueprintType)
struct FSpawnPointList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStorageChassisComponent*> SpawnPoints;
    
    ASTRO_API FSpawnPointList();
};

