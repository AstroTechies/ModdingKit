#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SublistItem.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FSublistItem {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    TSubclassOf<UItemType> DurableType;
    
    UPROPERTY(SaveGame)
    TSubclassOf<UItemType> ConsumableType;
    
    ASTRO_API FSublistItem();
};

