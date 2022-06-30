#pragma once
#include "CoreMinimal.h"
#include "EPlacementType.h"
#include "EPlacementOrientation.h"
#include "UObject/NoExportTypes.h"
#include "RandomDistributionProperties.generated.h"

USTRUCT(BlueprintType)
struct TERRAIN2_API FRandomDistributionProperties {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    int32 VarianceLevel;
    
    UPROPERTY(EditAnywhere)
    float Radius;
    
    UPROPERTY(EditAnywhere)
    EPlacementType SurfaceType;
    
    UPROPERTY(EditAnywhere)
    float SurfaceOffset;
    
    UPROPERTY(EditAnywhere)
    EPlacementOrientation OrientationMode;
    
    UPROPERTY(EditAnywhere)
    float RandomPitch;
    
    UPROPERTY(EditAnywhere)
    float RandomYaw;
    
    UPROPERTY(EditAnywhere)
    bool UniformScale;
    
    UPROPERTY(EditAnywhere)
    FFloatInterval ScaleX;
    
    UPROPERTY(EditAnywhere)
    FFloatInterval ScaleY;
    
    UPROPERTY(EditAnywhere)
    FFloatInterval ScaleZ;
    
    UPROPERTY(EditAnywhere)
    float MaxAlignmentThresholdDegrees;
    
    UPROPERTY(EditAnywhere)
    float MinAlignmentThresholdDegrees;
    
    UPROPERTY(EditAnywhere)
    float MaxProjectionDistance;
    
    UPROPERTY(EditAnywhere)
    float DensityThreshold;
    
    FRandomDistributionProperties();
};

