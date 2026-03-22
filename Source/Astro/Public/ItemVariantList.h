#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ItemVariantList.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FItemVariantList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> Variants;
    
    ASTRO_API FItemVariantList();
};

