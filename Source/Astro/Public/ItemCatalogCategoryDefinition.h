#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemCatalogCategoryDefinition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UItemCatalogCategoryDefinition : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CategoryName;
    
    UItemCatalogCategoryDefinition();

};

