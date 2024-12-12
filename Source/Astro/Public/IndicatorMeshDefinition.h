#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IndicatorMeshDefinition.generated.h"

class UStaticMesh;

USTRUCT(BlueprintType)
struct FIndicatorMeshDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* IndicatorMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IndicatorScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator RotationOffset;
    
    ASTRO_API FIndicatorMeshDefinition();
};

