#pragma once
#include "CoreMinimal.h"
#include "CrackedReplicationData.generated.h"

USTRUCT(BlueprintType)
struct FCrackedReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY()
    uint8 bCracked: 1;
    
    ASTRO_API FCrackedReplicationData();
};

