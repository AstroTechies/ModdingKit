#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
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

