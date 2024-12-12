#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BoundedVoxelVolumeModifierList.generated.h"

class UBoundedVoxelVolumeModifier;

UCLASS(Blueprintable)
class TERRAIN2_API UBoundedVoxelVolumeModifierList : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UBoundedVoxelVolumeModifier*> Modifiers;
    
    UBoundedVoxelVolumeModifierList();

};

