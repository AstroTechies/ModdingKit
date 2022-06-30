#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FoliageDestructionInfo.h"
#include "AstroFoliageDestructionGroup.generated.h"

class UStaticMesh;
class AActor;

UCLASS(Blueprintable, Blueprintable)
class TERRAIN2_API UAstroFoliageDestructionGroup : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    FFoliageDestructionInfo FoliageDestructionInfo;

    UPROPERTY(EditDefaultsOnly)
    TArray<TSoftObjectPtr<UStaticMesh>> BatchingMeshes;

    UPROPERTY(EditDefaultsOnly)
    TArray<TSoftClassPtr<AActor>> PlacementActors;

    UAstroFoliageDestructionGroup();
};
