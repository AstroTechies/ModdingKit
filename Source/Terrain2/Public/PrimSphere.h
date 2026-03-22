#pragma once
#include "CoreMinimal.h"
#include "PrimSphere.generated.h"

USTRUCT(BlueprintType)
struct FPrimSphere {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    TERRAIN2_API FPrimSphere();
};

