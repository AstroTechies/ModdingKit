#pragma once
#include "CoreMinimal.h"
#include "ResearchBonus.generated.h"

class UResearchBonusBehavior;

USTRUCT(BlueprintType)
struct FResearchBonus {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Threshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UResearchBonusBehavior* Behavior;
    
    ASTRO_API FResearchBonus();
};

