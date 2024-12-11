#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FoliageDestructionInfo.h"
#include "AstroFoliageDestructionData.generated.h"

class UAstroFoliageDestructionGroup;

UCLASS(Blueprintable)
class TERRAIN2_API UAstroFoliageDestructionData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFoliageDestructionInfo DefaultFoliageDestructionInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAstroFoliageDestructionGroup*> DestructionGroups;
    
    UAstroFoliageDestructionData();

};

