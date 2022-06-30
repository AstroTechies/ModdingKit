#pragma once
#include "CoreMinimal.h"
#include "BoundedVoxelVolumeModifier.h"
#include "EPlacementPhysicsMode.h"
#include "WeightedActorSelection.h"
#include "ActorDistributionShapeModifier.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class TERRAIN2_API UActorDistributionShapeModifier : public UBoundedVoxelVolumeModifier
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float ShapeRadius;

    UPROPERTY(EditAnywhere)
    EPlacementPhysicsMode PhysicsMode;

    UPROPERTY(EditAnywhere)
    TArray<FWeightedActorSelection> Actors;

    UActorDistributionShapeModifier();
};
