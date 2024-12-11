#pragma once
#include "CoreMinimal.h"
#include "BoundedVoxelVolumeModifier.h"
#include "EPlacementPhysicsMode.h"
#include "WeightedActorSelection.h"
#include "ActorDistributionShapeModifier.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class TERRAIN2_API UActorDistributionShapeModifier : public UBoundedVoxelVolumeModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShapeRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPlacementPhysicsMode PhysicsMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeightedActorSelection> Actors;
    
    UActorDistributionShapeModifier();

};

