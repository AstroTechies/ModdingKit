#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EItemVariantType.h"
#include "Templates/SubclassOf.h"
#include "ItemCatalogData.generated.h"

class UItemCatalogCategoryDefinition;
class UItemType;
class UStaticMesh;

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UItemCatalogData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Does this item only show up in the catalog in creative mode?
    uint8 bIsCreativeModeOnly: 1;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Does this item spawn as a package when spawned in from the catalog in creative mode?
    uint8 bCreativeSpawnPackaged: 1;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bPlayFabAccountBound: 1;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bHiddenUntilUnlocked: 1;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bHiddenUntilUnlockedCreativeMode: 1;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // How many bytes are needed to unlock this entry in the catalog?
    int32 UnlockCost;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Is this item the base of its catalog row?
    uint8 bIsBaseItem: 1;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // If this item is the base of the catalog row, this is the tab of the catalog that the entry is in; otherwise, this is None
    UItemCatalogCategoryDefinition* Category;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Y value (0 = first row of the tab, 1 = second row of the tab, etc.)
    int32 CategorySequenceNumber;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // A reference to the item that is the base of the catalog row (If this is the base item, leave this as None)
    TSubclassOf<UItemType> BaseItemType;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Is this entry to the left or the right of the base item in the catalog row? (If this is the base item, leave this as Left)
    EItemVariantType VariantType;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // |X| (0 = the base entry, 1 = directly before or after the base entry, etc.)
    int32 VariationSequenceNumber;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // The model that shows in the catalog to represent this item
    UStaticMesh* CatalogMesh;
    
    UItemCatalogData();

};

