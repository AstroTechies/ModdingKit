#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OverrideCustomPackageItemList.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "DeployableItemPackageCatalog.generated.h"

class UItemType;
class APhysicalItem;

UCLASS(Blueprintable)
class UDeployableItemPackageCatalog : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, TSubclassOf<APhysicalItem>> DefaultPackagesForItemTiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<APhysicalItem>, TSubclassOf<APhysicalItem>> OverrideCustomPackagesForItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FOverrideCustomPackageItemList> OverrideItemTypeCustomPackagesForItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UItemType>, TSubclassOf<UItemType>> PackagedItemTypeUpgradeMapping;
    
    UDeployableItemPackageCatalog();
};

