#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ItemProbabilityPair.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FItemProbabilityPair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Probability;
    
    ASTRO_API FItemProbabilityPair();
};

