#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
#include "ManualPlacement.generated.h"

USTRUCT(BlueprintType)
struct TERRAIN2_API FManualPlacement {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FVector Position;
    
    UPROPERTY(EditAnywhere)
    FRotator Rotation;
    
    UPROPERTY(EditAnywhere)
    float Scale;
    
    FManualPlacement();
};

