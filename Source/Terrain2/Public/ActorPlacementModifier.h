#pragma once
#include "CoreMinimal.h"
#include "BoundedVoxelVolumeModifier.h"
#include "ActorPlacementModifier.generated.h"

class AActor;

UCLASS(Blueprintable, EditInlineNew)
class TERRAIN2_API UActorPlacementModifier : public UBoundedVoxelVolumeModifier
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TSoftClassPtr<AActor> actorType;

    UActorPlacementModifier();
};
