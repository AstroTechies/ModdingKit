#pragma once
#include "CoreMinimal.h"
#include "ItemProbabilityPairList.h"
#include "HarvestableItemSpawnerDefinition.generated.h"

USTRUCT(BlueprintType)
struct FHarvestableItemSpawnerDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemProbabilityPairList SpawnedItemTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bItemCanBeUsedBeforeHarvest: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bItemRespawns: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bSlotRemainsUsableAfterItemHarvested: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bItemRespawnsAtEndOfDelay: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RespawnDelay;
    
    ASTRO_API FHarvestableItemSpawnerDefinition();
};

