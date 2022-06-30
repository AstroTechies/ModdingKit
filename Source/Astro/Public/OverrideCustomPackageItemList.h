#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OverrideCustomPackageItemList.generated.h"

class UItemList;
class APhysicalItem;

USTRUCT(BlueprintType)
struct FOverrideCustomPackageItemList {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TArray<TSubclassOf<UItemList>> ItemLists;
    
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<APhysicalItem> OverridePackage;
    
    ASTRO_API FOverrideCustomPackageItemList();
};

