#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ItemQuantityPair.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FItemQuantityPair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ItemAmount;
    
    ASTRO_API FItemQuantityPair();
};

