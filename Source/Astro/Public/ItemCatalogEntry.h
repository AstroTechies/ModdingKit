#pragma once
#include "CoreMinimal.h"
#include "EItemVariantType.h"
#include "ItemVariantList.h"
#include "Templates/SubclassOf.h"
#include "ItemCatalogEntry.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FItemCatalogEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> BaseItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EItemVariantType, FItemVariantList> VariantsByType;
    
    ASTRO_API FItemCatalogEntry();
};

