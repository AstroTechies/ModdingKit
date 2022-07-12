#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SublistItem.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FSublistItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> DurableType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ConsumableType;
    
    ASTRO_API FSublistItem();
};

