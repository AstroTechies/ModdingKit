#pragma once
#include "CoreMinimal.h"
#include "SpawnPointList.generated.h"

class UStorageChassisComponent;

USTRUCT(BlueprintType)
struct FSpawnPointList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<UStorageChassisComponent*> SpawnPoints;
    
    ASTRO_API FSpawnPointList();
};

