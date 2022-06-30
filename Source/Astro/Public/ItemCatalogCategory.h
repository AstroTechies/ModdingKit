#pragma once
#include "CoreMinimal.h"
#include "ItemCatalogEntry.h"
#include "ItemCatalogCategory.generated.h"

USTRUCT(BlueprintType)
struct FItemCatalogCategory {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TArray<FItemCatalogEntry> Entries;
    
    ASTRO_API FItemCatalogCategory();
};

