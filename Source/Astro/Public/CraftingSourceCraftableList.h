#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "CraftingSourceCraftableList.generated.h"

class UItemList;
class UItemType;

USTRUCT(BlueprintType)
struct FCraftingSourceCraftableList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> CraftingSourceItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemList> Craftables;
    
    ASTRO_API FCraftingSourceCraftableList();
};

