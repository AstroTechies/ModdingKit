#pragma once
#include "CoreMinimal.h"
#include "ECollectionReward.h"
#include "Templates/SubclassOf.h"
#include "CollectionData.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FCollectionData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> RequiredItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECollectionReward rewardType;
    
    ASTRO_API FCollectionData();
};

