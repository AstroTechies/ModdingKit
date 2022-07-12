#pragma once
#include "CoreMinimal.h"
#include "BoundedVoxelVolumeModifier.h"
#include "CratersModifier.generated.h"

UCLASS(EditInlineNew)
class TERRAIN2_API UCratersModifier : public UBoundedVoxelVolumeModifier {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float CraterRadius;
    
    UPROPERTY(EditAnywhere)
    float CraterRimThickness;
    
    UPROPERTY(EditAnywhere)
    float RimIntensity;
    
    UCratersModifier();
};

