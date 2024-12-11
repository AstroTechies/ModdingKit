#pragma once
#include "CoreMinimal.h"
#include "BoundedVoxelVolumeModifier.h"
#include "ActorPlacementModifier.generated.h"

class AActor;

UCLASS(Blueprintable, EditInlineNew)
class TERRAIN2_API UActorPlacementModifier : public UBoundedVoxelVolumeModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> actorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOrientActorToPlanetUp: 1;
    
    UActorPlacementModifier();

};

