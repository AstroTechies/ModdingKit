#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Engine/DataAsset.h"
#include "OverrideCustomPackageItemList.h"
#include "DeployableItemPackageCatalog.generated.h"

class APhysicalItem;
class UItemType;

UCLASS(Blueprintable, Blueprintable)
class UDeployableItemPackageCatalog : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TMap<int32, TSubclassOf<APhysicalItem>> DefaultPackagesForItemTiers;

    UPROPERTY(EditDefaultsOnly)
    TMap<TSubclassOf<APhysicalItem>, TSubclassOf<APhysicalItem>> OverrideCustomPackagesForItems;

    UPROPERTY(EditDefaultsOnly)
    TArray<FOverrideCustomPackageItemList> OverrideItemTypeCustomPackagesForItems;

    UPROPERTY(EditDefaultsOnly)
    TMap<TSubclassOf<UItemType>, TSubclassOf<UItemType>> PackagedItemTypeUpgradeMapping;

    UDeployableItemPackageCatalog();
};
