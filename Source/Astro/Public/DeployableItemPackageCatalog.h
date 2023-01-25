#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "OverrideCustomPackageItemList.h"
#include "Templates/SubclassOf.h"
#include "DeployableItemPackageCatalog.generated.h"

class APhysicalItem;
class UItemType;

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

