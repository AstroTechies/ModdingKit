#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FoliageDestructionInfo.h"
#include "AstroFoliageDestructionData.generated.h"

class UAstroFoliageDestructionGroup;

UCLASS(Blueprintable, Blueprintable)
class TERRAIN2_API UAstroFoliageDestructionData : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    FFoliageDestructionInfo DefaultFoliageDestructionInfo;

    UPROPERTY(EditDefaultsOnly)
    TArray<UAstroFoliageDestructionGroup *> DestructionGroups;

    UAstroFoliageDestructionData();
};
