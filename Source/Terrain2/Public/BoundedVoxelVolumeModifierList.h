#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BoundedVoxelVolumeModifierList.generated.h"

class UBoundedVoxelVolumeModifier;

UCLASS(Blueprintable, Blueprintable)
class TERRAIN2_API UBoundedVoxelVolumeModifierList : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export)
    TArray<UBoundedVoxelVolumeModifier *> Modifiers;

    UBoundedVoxelVolumeModifierList();
};
