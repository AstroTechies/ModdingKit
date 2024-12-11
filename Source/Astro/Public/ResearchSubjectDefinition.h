#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ResearchPhase.h"
#include "ResearchSubjectDefinition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UResearchSubjectDefinition : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FResearchPhase> Phases;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> BonusTimelinesAffected;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TotalPointsPerInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TotalResearchSecondsPerInstance;
    
    UResearchSubjectDefinition();

};

