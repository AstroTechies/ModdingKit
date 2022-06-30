#pragma once
#include "CoreMinimal.h"
#include "PrimSphere.generated.h"

USTRUCT()
struct FPrimSphere {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float Radius;
    
    TERRAIN2_API FPrimSphere();
};

