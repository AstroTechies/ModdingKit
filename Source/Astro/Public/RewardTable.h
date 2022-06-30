#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/Object.h"
#include "RewardSet.h"
#include "RewardTable.generated.h"

class UItemList;

UCLASS(Blueprintable, Blueprintable)
class URewardTable : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TSubclassOf<UItemList> InitiallyUnlockedItems;

    UPROPERTY(EditAnywhere)
    TArray<FRewardSet> RewardSets;

    URewardTable();
};
