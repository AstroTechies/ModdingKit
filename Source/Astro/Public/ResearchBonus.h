#pragma once
#include "CoreMinimal.h"
#include "ResearchBonus.generated.h"

class UResearchBonusBehavior;

USTRUCT(BlueprintType)
struct FResearchBonus {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    float Threshold;
    
    UPROPERTY(EditDefaultsOnly, Instanced)
    UResearchBonusBehavior* Behavior;
    
    ASTRO_API FResearchBonus();
};

