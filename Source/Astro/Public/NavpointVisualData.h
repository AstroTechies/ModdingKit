#pragma once
#include "CoreMinimal.h"
#include "NavpointVisualData.generated.h"

class UStaticMeshComponent;
class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct FNavpointVisualData {
    GENERATED_BODY()
public:
    UPROPERTY(Export)
    UStaticMeshComponent* IconMesh;
    
    UPROPERTY(Export)
    UStaticMeshComponent* ElevationLineMesh;
    
    UPROPERTY()
    UMaterialInstanceDynamic* IconMaterial;
    
    UPROPERTY()
    UMaterialInstanceDynamic* ElevationLineMaterial;
    
    ASTRO_API FNavpointVisualData();
};

