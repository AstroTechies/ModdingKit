#pragma once
#include "CoreMinimal.h"
#include "CraftingSourceCraftableList.h"
#include "ECraftingOrgin.h"
#include "Templates/SubclassOf.h"
#include "CraftingOriginDependencyMap.generated.h"

class UItemList;

USTRUCT(BlueprintType)
struct FCraftingOriginDependencyMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECraftingOrgin CraftingDependency;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TooltipDescriptionTemplate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasCraftingSources;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCraftingSourceCraftableList> CraftingSources;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemList> UnsourcedCraftables;
    
    ASTRO_API FCraftingOriginDependencyMap();
};

