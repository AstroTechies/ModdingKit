#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "RandomDistributionProperties.h"
#include "EPlacementMode.h"
#include "ManualPlacement.h"
#include "BoundedVoxelVolumeModifier.generated.h"

UCLASS(Blueprintable, DefaultToInstanced, EditInlineNew)
class TERRAIN2_API UBoundedVoxelVolumeModifier : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bEnabled: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 PlacementLODOffset;
    
    UPROPERTY(AdvancedDisplay, EditAnywhere)
    uint8 ExecutionLODOffset;
    
    UPROPERTY(EditAnywhere)
    uint32 Seed;
    
    UPROPERTY(EditAnywhere)
    EPlacementMode PlacementMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExclusionRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultCullingDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FManualPlacement> ManualPlacements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlacementDensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 maxCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRandomDistributionProperties DistributionOptions;
    
    UBoundedVoxelVolumeModifier();
};

