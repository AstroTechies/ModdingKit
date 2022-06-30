#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDFTransform.generated.h"

USTRUCT()
struct FSDFTransform {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FVector Translation;
    
    UPROPERTY(EditAnywhere)
    FRotator Rotation;
    
    UPROPERTY(EditAnywhere)
    FVector Scale;
    
    TERRAIN2_API FSDFTransform();
};

