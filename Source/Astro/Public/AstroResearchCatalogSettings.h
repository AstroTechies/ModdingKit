#pragma once
#include "CoreMinimal.h"
#include "AstroResearchCatalogItem.h"
#include "AstroResearchCatalogItemBundle.h"
#include "Templates/SubclassOf.h"
#include "AstroResearchCatalogSettings.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FAstroResearchCatalogSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FAstroResearchCatalogItemBundle> ResearchCatalogItemBundles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FAstroResearchCatalogItem> BackpackPrinterCatalogOptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FAstroResearchCatalogItem> SmallPrinterCatalogOptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FAstroResearchCatalogItem> MediumPrinterCatalogOptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FAstroResearchCatalogItem> LargePrinterCatalogOptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> DisabledCatalogItems;
    
    ASTRO_API FAstroResearchCatalogSettings();
};

