#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AstroResearchCatalogItem.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FAstroResearchCatalogItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> Item;
    
    ASTRO_API FAstroResearchCatalogItem();
};

