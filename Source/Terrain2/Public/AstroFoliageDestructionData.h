#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
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

