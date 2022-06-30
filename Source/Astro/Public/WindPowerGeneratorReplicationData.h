#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "WindPowerGeneratorReplicationData.generated.h"

USTRUCT(BlueprintType)
struct FWindPowerGeneratorReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FVector_NetQuantizeNormal WindNormal;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    uint8 WindSpeed;
    
    ASTRO_API FWindPowerGeneratorReplicationData();
};

