#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BoundedModifierSceneComponent.generated.h"

class UBoundedVoxelVolumeModifier;
class AActor;

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

