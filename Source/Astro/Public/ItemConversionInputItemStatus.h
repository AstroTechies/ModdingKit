#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ItemConversionInputItemStatus.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FItemConversionInputItemStatus {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ItemType;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool IsSatisfied;
    
    ASTRO_API FItemConversionInputItemStatus();
};

