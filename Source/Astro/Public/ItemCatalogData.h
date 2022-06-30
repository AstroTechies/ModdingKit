#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Engine/DataAsset.h"
#include "EItemVariantType.h"
#include "ItemCatalogData.generated.h"

class UStaticMesh;
class UItemCatalogCategoryDefinition;
class UItemType;

UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class ASTRO_API UItemCatalogData : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    uint8 bIsCreativeModeOnly : 1;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    uint8 bCreativeSpawnPackaged : 1;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    uint8 bPlayFabAccountBound : 1;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    uint8 bHiddenUntilUnlocked : 1;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    uint8 bHiddenUntilUnlockedCreativeMode : 1;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    int32 UnlockCost;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    uint8 bIsBaseItem : 1;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    UItemCatalogCategoryDefinition *Category;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    int32 CategorySequenceNumber;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    TSubclassOf<UItemType> BaseItemType;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    EItemVariantType VariantType;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    int32 VariationSequenceNumber;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    UStaticMesh *CatalogMesh;

    UItemCatalogData();
};
