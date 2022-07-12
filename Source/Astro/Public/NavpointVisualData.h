#pragma once
#include "CoreMinimal.h"
#include "NavpointVisualData.generated.h"

class UStaticMeshComponent;
class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct FNavpointVisualData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* IconMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ElevationLineMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* IconMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* ElevationLineMaterial;
    
    ASTRO_API FNavpointVisualData();
};

