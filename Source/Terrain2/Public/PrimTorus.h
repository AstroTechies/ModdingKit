#pragma once
#include "CoreMinimal.h"
#include "PrimTorus.generated.h"

USTRUCT(BlueprintType)
struct FPrimTorus {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MajorRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinorRadius;
    
    TERRAIN2_API FPrimTorus();
};

