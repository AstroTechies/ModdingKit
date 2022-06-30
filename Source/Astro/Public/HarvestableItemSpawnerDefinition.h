#pragma once
#include "CoreMinimal.h"
#include "ItemProbabilityPairList.h"
#include "HarvestableItemSpawnerDefinition.generated.h"

USTRUCT(BlueprintType)
struct FHarvestableItemSpawnerDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName SlotName;
    
    UPROPERTY(EditAnywhere)
    FItemProbabilityPairList SpawnedItemTypes;
    
    UPROPERTY(EditAnywhere)
    uint8 bItemCanBeUsedBeforeHarvest: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bItemRespawns: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bSlotRemainsUsableAfterItemHarvested: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bItemRespawnsAtEndOfDelay: 1;
    
    UPROPERTY(EditAnywhere)
    float RespawnDelay;
    
    ASTRO_API FHarvestableItemSpawnerDefinition();
};

