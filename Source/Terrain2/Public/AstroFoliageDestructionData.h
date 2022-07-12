#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "FoliageDestructionInfo.h"
#include "AstroFoliageDestructionData.generated.h"

class UAstroFoliageDestructionGroup;

UCLASS()
class TERRAIN2_API UAstroFoliageDestructionData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    FFoliageDestructionInfo DefaultFoliageDestructionInfo;
    
    UPROPERTY(EditDefaultsOnly)
    TArray<UAstroFoliageDestructionGroup*> DestructionGroups;
    
    UAstroFoliageDestructionData();
};

