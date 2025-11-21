#pragma once
#include "CoreMinimal.h"
#include "PrimCylinder.generated.h"

USTRUCT(BlueprintType)
struct FPrimCylinder {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HalfHeight;
    
    TERRAIN2_API FPrimCylinder();
};

