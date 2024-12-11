#pragma once
#include "CoreMinimal.h"
#include "IndicatorCollection.generated.h"

class AResourceInfo;

USTRUCT(BlueprintType)
struct FIndicatorCollection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AResourceInfo*> Indicators;
    
    ASTRO_API FIndicatorCollection();
};

