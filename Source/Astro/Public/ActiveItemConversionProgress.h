#pragma once
#include "CoreMinimal.h"
#include "ActiveItemConversionProgress.generated.h"

class APhysicalItem;

USTRUCT(BlueprintType)
struct FActiveItemConversionProgress {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<APhysicalItem*> InputItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FinalOutputAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProgressRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ID;
    
    ASTRO_API FActiveItemConversionProgress();
};

