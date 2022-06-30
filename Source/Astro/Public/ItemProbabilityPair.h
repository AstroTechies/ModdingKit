#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ItemProbabilityPair.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FItemProbabilityPair {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TSubclassOf<UItemType> ItemType;
    
    UPROPERTY(EditAnywhere)
    float Probability;
    
    ASTRO_API FItemProbabilityPair();
};

