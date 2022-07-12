#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EPhysicalSurface -FallbackName=EPhysicalSurface
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

