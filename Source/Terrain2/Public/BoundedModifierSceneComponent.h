#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
#include "BoundedModifierSceneComponent.generated.h"

class AActor;
class UBoundedVoxelVolumeModifier;

USTRUCT(BlueprintType)
struct FBoundedModifierSceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY()
    FTransform RelativeTransform;
    
    UPROPERTY(Export)
    UBoundedVoxelVolumeModifier* Modifier;
    
    UPROPERTY()
    TSoftClassPtr<AActor> ParentClass;
    
    TERRAIN2_API FBoundedModifierSceneComponent();
};

