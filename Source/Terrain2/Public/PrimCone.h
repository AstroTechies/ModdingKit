#pragma once
#include "CoreMinimal.h"
#include "PrimCone.generated.h"

USTRUCT(BlueprintType)
struct FPrimCone {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Height;
    
    TERRAIN2_API FPrimCone();
};

