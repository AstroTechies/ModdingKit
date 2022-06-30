#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "CacheResourceGroup.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FCacheResourceGroup {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    uint32 ID;
    
    UPROPERTY(SaveGame)
    TSubclassOf<UItemType> ItemType;
    
    ASTRO_API FCacheResourceGroup();
};

