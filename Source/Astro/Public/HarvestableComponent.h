#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
#include "HarvestableItemSpawner.h"
#include "HarvestableComponent.generated.h"

USTRUCT(BlueprintType)
struct FHarvestableComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    TArray<FHarvestableItemSpawner> ItemSpawners;
    
    UPROPERTY(SaveGame)
    uint8 bIsUprooted: 1;
    
    UPROPERTY(SaveGame)
    uint8 bHasPostHarvestUsableSlots: 1;
    
    UPROPERTY(SaveGame)
    float UprootedDestructionDelayRemaining;
    
    ASTRO_API FHarvestableComponent();
};

