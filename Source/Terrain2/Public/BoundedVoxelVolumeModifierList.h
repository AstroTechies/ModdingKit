#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "BoundedVoxelVolumeModifierList.generated.h"

class UBoundedVoxelVolumeModifier;

UCLASS()
class TERRAIN2_API UBoundedVoxelVolumeModifierList : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export)
    TArray<UBoundedVoxelVolumeModifier*> Modifiers;
    
    UBoundedVoxelVolumeModifierList();
};

