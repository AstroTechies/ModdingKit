#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "ItemCatalogCategory.h"
#include "ItemCatalog.generated.h"

class UItemCatalogCategoryDefinition;

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UItemCatalog : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UItemCatalogCategoryDefinition*, FItemCatalogCategory> Catalog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bIsCreativeCatalog: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemCatalogCategoryDefinition* AllCatalogItemsCategory;
    
public:
    UItemCatalog();
};

