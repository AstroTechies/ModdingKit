#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OverrideCustomPackageItemList.generated.h"

class APhysicalItem;
class UItemList;

USTRUCT(BlueprintType)
struct FOverrideCustomPackageItemList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemList>> ItemLists;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<APhysicalItem> OverridePackage;
    
    ASTRO_API FOverrideCustomPackageItemList();
};

