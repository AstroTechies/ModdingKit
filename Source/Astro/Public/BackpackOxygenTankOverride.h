#pragma once
#include "CoreMinimal.h"
#include "BackpackOxygenTankProperties.h"
#include "BackpackOxygenTankOverride.generated.h"

USTRUCT(BlueprintType)
struct FBackpackOxygenTankOverride {
    GENERATED_BODY()
public:
    UPROPERTY()
    bool bIsValid;
    
    UPROPERTY()
    FBackpackOxygenTankProperties OverrideProperties;
    
    ASTRO_API FBackpackOxygenTankOverride();
};

