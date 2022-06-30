#pragma once
#include "CoreMinimal.h"
#include "EUseType.h"
#include "UseSuppression.generated.h"

USTRUCT()
struct FUseSuppression {
    GENERATED_BODY()
public:
    UPROPERTY()
    FName SuppressionId;
    
    UPROPERTY()
    EUseType SuppressionTypeFlags;
    
    ASTRO_API FUseSuppression();
};

