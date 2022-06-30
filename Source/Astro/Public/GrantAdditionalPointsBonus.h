#pragma once
#include "CoreMinimal.h"
#include "ResearchBonusBehavior.h"
#include "GrantAdditionalPointsBonus.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UGrantAdditionalPointsBonus : public UResearchBonusBehavior
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    float AdditionalPointsGranted;

    UGrantAdditionalPointsBonus();
};
