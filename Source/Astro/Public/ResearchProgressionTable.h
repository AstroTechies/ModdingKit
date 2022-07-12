#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
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

