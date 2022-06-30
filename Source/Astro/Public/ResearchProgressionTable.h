#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ResearchBonusTimeline.h"
#include "ResearchProgressionTable.generated.h"

UCLASS(Blueprintable, Blueprintable)
class UResearchProgressionTable : public UDataAsset
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    TArray<FResearchBonusTimeline> BonusTimelines;

public:
    UResearchProgressionTable();
};
