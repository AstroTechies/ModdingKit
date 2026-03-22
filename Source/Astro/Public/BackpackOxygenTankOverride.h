#pragma once
#include "CoreMinimal.h"
#include "BackpackOxygenTankProperties.h"
#include "BackpackOxygenTankOverride.generated.h"

USTRUCT(BlueprintType)
struct FBackpackOxygenTankOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsValid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBackpackOxygenTankProperties OverrideProperties;
    
    ASTRO_API FBackpackOxygenTankOverride();
};

