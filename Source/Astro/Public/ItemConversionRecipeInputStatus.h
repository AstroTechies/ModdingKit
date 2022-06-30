#pragma once
#include "CoreMinimal.h"
#include "ItemConversionInputItemStatus.h"
#include "ItemConversionRecipeInputStatus.generated.h"

USTRUCT(BlueprintType)
struct FItemConversionRecipeInputStatus {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TArray<FItemConversionInputItemStatus> InputItemStatuses;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool IsSatisfied;
    
    ASTRO_API FItemConversionRecipeInputStatus();
};
