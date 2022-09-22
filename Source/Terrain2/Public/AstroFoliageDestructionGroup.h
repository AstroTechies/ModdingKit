#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "FoliageDestructionInfo.h"
#include "AstroFoliageDestructionGroup.generated.h"

class AActor;
class UStaticMesh;

UCLASS(Blueprintable)
class TERRAIN2_API UAstroFoliageDestructionGroup : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFoliageDestructionInfo FoliageDestructionInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UStaticMesh>> BatchingMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> PlacementActors;
    
    UAstroFoliageDestructionGroup();
};

