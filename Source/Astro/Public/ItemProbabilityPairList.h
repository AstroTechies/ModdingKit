#pragma once
#include "CoreMinimal.h"
#include "ItemProbabilityPair.h"
#include "ItemProbabilityPairList.generated.h"

USTRUCT(BlueprintType)
struct FItemProbabilityPairList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemProbabilityPair> ItemProbabilityPairs;
    
    ASTRO_API FItemProbabilityPairList();
};

