#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "EHarvestableItemSpawnerType.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "HarvestableItemSpawner.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FHarvestableItemSpawner {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FSlotReference SlotRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroDatumRef EntityAwaitingHarvest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float SecondsUntilRespawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EHarvestableItemSpawnerType SpawnerType;
    
    ASTRO_API FHarvestableItemSpawner();
};

