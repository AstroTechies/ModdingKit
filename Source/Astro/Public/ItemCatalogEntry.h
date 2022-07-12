#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ItemVariantList.h"
#include "EItemVariantType.h"
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

