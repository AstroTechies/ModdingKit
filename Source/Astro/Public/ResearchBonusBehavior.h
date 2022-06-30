#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ResearchBonusBehavior.generated.h"

UCLASS(Blueprintable, Abstract, EditInlineNew)
class UResearchBonusBehavior : public UObject
{
    GENERATED_BODY()
public:
    UResearchBonusBehavior();
};
