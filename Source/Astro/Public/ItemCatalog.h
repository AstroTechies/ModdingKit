#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ItemCatalogCategory.h"
#include "ItemCatalog.generated.h"

class UItemCatalogCategoryDefinition;

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UItemCatalog : public UObject
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY()
    TMap<UItemCatalogCategoryDefinition *, FItemCatalogCategory> Catalog;

    UPROPERTY()
    uint8 bIsCreativeCatalog : 1;

    UPROPERTY()
    UItemCatalogCategoryDefinition *AllCatalogItemsCategory;

public:
    UItemCatalog();
};
