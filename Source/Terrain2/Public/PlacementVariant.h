#pragma once
#include "CoreMinimal.h"
#include "ItemTypeReference.h"
#include "FoliageDestructionInfo.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Int32Interval -FallbackName=Int32Interval
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=FloatInterval -FallbackName=FloatInterval
#include "EPlacementOrientation.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BodyInstance -FallbackName=BodyInstance
#include "PlacementVariant.generated.h"

class AActor;
class UMaterialInterface;
class UStaticMesh;

USTRUCT(BlueprintType)
struct TERRAIN2_API FPlacementVariant {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float SelectionWeight;
    
    UPROPERTY(EditAnywhere)
    float WeightFalloff;
    
    UPROPERTY(EditAnywhere)
    TSoftClassPtr<AActor> PlacementActor;
    
    UPROPERTY(EditAnywhere)
    FItemTypeReference ItemType;
    
    UPROPERTY(EditAnywhere)
    FName SoundRTPCName;
    
    UPROPERTY(EditAnywhere)
    FFoliageDestructionInfo FoliageDestructionInfo;
    
    UPROPERTY(EditAnywhere)
    EPlacementOrientation Orientation;
    
    UPROPERTY(EditAnywhere)
    float RandomYaw;
    
    UPROPERTY(EditAnywhere)
    float RandomPitch;
    
    UPROPERTY(EditAnywhere)
    bool bUniformScale;
    
    UPROPERTY(EditAnywhere)
    FFloatInterval ScaleX;
    
    UPROPERTY(EditAnywhere)
    FFloatInterval ScaleY;
    
    UPROPERTY(EditAnywhere)
    FFloatInterval ScaleZ;
    
    UPROPERTY(EditAnywhere)
    float ExclusionRadius;
    
    UPROPERTY(EditAnywhere)
    FFloatInterval DensityScalingSlope;
    
    UPROPERTY(EditAnywhere)
    float SurfaceOffset;
    
    UPROPERTY(EditAnywhere)
    TSoftObjectPtr<UStaticMesh> BatchingMesh;
    
    UPROPERTY(AdvancedDisplay, EditAnywhere)
    TArray<UMaterialInterface*> OverrideMaterials;
    
    UPROPERTY(EditAnywhere)
    FInt32Interval CullDistance;
    
    UPROPERTY(EditAnywhere)
    float MaxDepenetrationVelocity;
    
    UPROPERTY(EditAnywhere)
    FBodyInstance BodyInstance;
    
    UPROPERTY(AdvancedDisplay, EditAnywhere)
    uint8 bEnableDensityScaling: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bCastShadow: 1;
    
    UPROPERTY(AdvancedDisplay, EditAnywhere)
    uint8 bCastShadowAsTwoSided: 1;
    
    UPROPERTY(AdvancedDisplay, EditAnywhere)
    uint8 bReceivesDecals: 1;
    
    UPROPERTY(AdvancedDisplay, EditAnywhere)
    uint8 bUseAsOccluder: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bShouldOverrideDestructionEffects: 1;
    
    FPlacementVariant();
};

