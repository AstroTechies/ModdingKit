#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "ResearchBonusBehavior.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UResearchBonusBehavior : public UObject {
    GENERATED_BODY()
public:
    UResearchBonusBehavior();
};

