#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
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

