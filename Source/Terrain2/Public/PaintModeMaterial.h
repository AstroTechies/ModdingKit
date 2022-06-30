#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "PaintModeMaterial.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct TERRAIN2_API FPaintModeMaterial {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FLinearColor Color;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EPhysicalSurface> SurfaceType;
    
    UPROPERTY(EditAnywhere)
    int32 HardnessLevel;
    
    UPROPERTY(EditAnywhere)
    UMaterialInterface* CustomMaterial;
    
    UPROPERTY(EditAnywhere)
    UMaterialInterface* ButtonMaterial;
    
    FPaintModeMaterial();
};

