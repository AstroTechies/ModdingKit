#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
#include "HarvestableItemSpawner.h"
#include "HarvestableComponent.generated.h"

USTRUCT(BlueprintType)
struct FHarvestableComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FHarvestableItemSpawner> ItemSpawners;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsUprooted: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bHasPostHarvestUsableSlots: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float UprootedDestructionDelayRemaining;
    
    ASTRO_API FHarvestableComponent();
};

