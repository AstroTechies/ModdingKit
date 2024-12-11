#pragma once
#include "CoreMinimal.h"
#include "NavpointVisualData.generated.h"

class UMaterialInstanceDynamic;
class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct FNavpointVisualData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* IconMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ElevationLineMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* IconMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* ElevationLineMaterial;
    
    ASTRO_API FNavpointVisualData();
};

