#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RewardSet.h"
#include "Templates/SubclassOf.h"
#include "RewardTable.generated.h"

class UItemList;

UCLASS(Blueprintable)
class URewardTable : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemList> InitiallyUnlockedItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRewardSet> RewardSets;
    
    URewardTable();

};

