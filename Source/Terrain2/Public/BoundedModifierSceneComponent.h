#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BoundedModifierSceneComponent.generated.h"

class AActor;
class UBoundedVoxelVolumeModifier;

USTRUCT(BlueprintType)
struct FBoundedModifierSceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform RelativeTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoundedVoxelVolumeModifier* Modifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> ParentClass;
    
    TERRAIN2_API FBoundedModifierSceneComponent();
};

