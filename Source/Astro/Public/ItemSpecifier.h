#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ItemSpecifier.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FItemSpecifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> Item;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Weight;
    
    ASTRO_API FItemSpecifier();
};

