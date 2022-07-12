#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "ItemCatalogCategoryDefinition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UItemCatalogCategoryDefinition : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CategoryName;
    
    UItemCatalogCategoryDefinition();
};

