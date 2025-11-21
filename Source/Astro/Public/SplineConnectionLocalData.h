#pragma once
#include "CoreMinimal.h"
#include "SplineConnectionLocalData.generated.h"

class UMaterialInstanceDynamic;
class USplineMeshComponent;

USTRUCT(BlueprintType)
struct FSplineConnectionLocalData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineMeshComponent* Spline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* BaseDynamicMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* PowerDynamicMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* IndicatorDynamicMaterial;
    
    ASTRO_API FSplineConnectionLocalData();
};

