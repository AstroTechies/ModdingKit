#pragma once
#include "CoreMinimal.h"
#include "ItemProbabilityPair.h"
#include "ItemProbabilityPairList.generated.h"

USTRUCT(BlueprintType)
struct FItemProbabilityPairList {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<FItemProbabilityPair> ItemProbabilityPairs;
    
    ASTRO_API FItemProbabilityPairList();
};

