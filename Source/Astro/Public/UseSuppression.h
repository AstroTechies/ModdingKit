#pragma once
#include "CoreMinimal.h"
#include "EUseType.h"
#include "UseSuppression.generated.h"

USTRUCT(BlueprintType)
struct FUseSuppression {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SuppressionId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUseType SuppressionTypeFlags;
    
    ASTRO_API FUseSuppression();
};

