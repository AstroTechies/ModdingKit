#pragma once
#include "CoreMinimal.h"
#include "BoundedVoxelVolumeModifier.h"
#include "GlobalSurfaceActorPlacementModifier.generated.h"

class AActor;

UCLASS(EditInlineNew)
class TERRAIN2_API UGlobalSurfaceActorPlacementModifier : public UBoundedVoxelVolumeModifier {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TSoftClassPtr<AActor> actorType;
    
    UPROPERTY(EditAnywhere)
    TArray<FString> AllowedBiomes;
    
    UPROPERTY(EditAnywhere)
    float MinimumBiomeWeight;
    
    UPROPERTY(EditAnywhere)
    int32 MinimumCount;
    
    UPROPERTY(EditAnywhere)
    int32 MaximumCount;
    
    UPROPERTY(EditAnywhere)
    float Radius;
    
    UGlobalSurfaceActorPlacementModifier();
};

