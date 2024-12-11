#pragma once
#include "CoreMinimal.h"
#include "SublistItem.h"
#include "RewardSublist.generated.h"

USTRUCT(BlueprintType)
struct FRewardSublist {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FSublistItem> Items;
    
    ASTRO_API FRewardSublist();
};

