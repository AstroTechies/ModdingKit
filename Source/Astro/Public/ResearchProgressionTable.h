#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ResearchBonusTimeline.h"
#include "ResearchProgressionTable.generated.h"

UCLASS(Blueprintable)
class UResearchProgressionTable : public UDataAsset {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FResearchBonusTimeline> BonusTimelines;
    
public:
    UResearchProgressionTable();

};

