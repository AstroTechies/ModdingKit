#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EPhysicalSurface -FallbackName=EPhysicalSurface
#include "VoxelMaterial.generated.h"

class UMaterialInterface;
class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct TERRAIN2_API FVoxelMaterial {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FLinearColor Color;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TEnumAsByte<EPhysicalSurface> SurfaceType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 HardnessLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UMaterialInterface* CustomMaterial;
    
    UPROPERTY(Transient)
    UMaterialInstanceDynamic* MaterialInstance;
    
    FVoxelMaterial();
};

