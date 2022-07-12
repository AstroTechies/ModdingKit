#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "FoliageDestructionInfo.h"
#include "AstroFoliageDestructionGroup.generated.h"

class AActor;
class UStaticMesh;

UCLASS()
class TERRAIN2_API UAstroFoliageDestructionGroup : public UDataAsset {
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

