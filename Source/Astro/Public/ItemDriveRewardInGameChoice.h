#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ItemDriveRewardInGameChoice.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FItemDriveRewardInGameChoice {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> InGameRewardItemTypes;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    int32 Weight;
    
    ASTRO_API FItemDriveRewardInGameChoice();
};

