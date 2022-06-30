#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ResearchPhase.h"
#include "ResearchSubjectDefinition.generated.h"

UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class UResearchSubjectDefinition : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    TArray<FResearchPhase> Phases;

    UPROPERTY(EditDefaultsOnly)
    TArray<FName> BonusTimelinesAffected;

    UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, meta = (AllowPrivateAccess = true))
    float TotalPointsPerInstance;

    UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, meta = (AllowPrivateAccess = true))
    float TotalResearchSecondsPerInstance;

    UResearchSubjectDefinition();
};
