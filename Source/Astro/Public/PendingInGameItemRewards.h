#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "PendingInGameItemRewards.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FPendingInGameItemRewards {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString EventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> PendingItemRewards;
    
    ASTRO_API FPendingInGameItemRewards();
};

