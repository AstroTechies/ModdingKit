#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IndicatorMeshDefinition.generated.h"

class UStaticMesh;

USTRUCT(BlueprintType)
struct FIndicatorMeshDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    UStaticMesh* IndicatorMesh;
    
    UPROPERTY(EditDefaultsOnly)
    float IndicatorScale;
    
    UPROPERTY(EditDefaultsOnly)
    FRotator RotationOffset;
    
    ASTRO_API FIndicatorMeshDefinition();
};

