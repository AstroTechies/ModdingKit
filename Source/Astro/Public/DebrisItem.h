#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "DebrisItem.generated.h"

class AActor;
class UItemType;

USTRUCT(BlueprintType)
struct FDebrisItem {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<AActor> ActorClass;
    
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UItemType> ActorItemType;
    
    UPROPERTY(EditDefaultsOnly)
    float SpawnChance;
    
    UPROPERTY(EditDefaultsOnly)
    float RandomOffset;
    
    ASTRO_API FDebrisItem();
};

