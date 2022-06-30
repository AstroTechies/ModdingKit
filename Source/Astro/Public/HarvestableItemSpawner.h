#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SlotReference.h"
#include "EHarvestableItemSpawnerType.h"
#include "AstroDatumRef.h"
#include "HarvestableItemSpawner.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FHarvestableItemSpawner {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    FSlotReference SlotRef;
    
    UPROPERTY(SaveGame)
    TSubclassOf<UItemType> ItemType;
    
    UPROPERTY(SaveGame)
    FAstroDatumRef EntityAwaitingHarvest;
    
    UPROPERTY(SaveGame)
    float SecondsUntilRespawn;
    
    UPROPERTY(SaveGame)
    EHarvestableItemSpawnerType SpawnerType;
    
    ASTRO_API FHarvestableItemSpawner();
};

