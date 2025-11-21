#pragma once
#include "CoreMinimal.h"
#include "CrackedReplicationData.generated.h"

USTRUCT(BlueprintType)
struct FCrackedReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bCracked: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bExaminable: 1;
    
    ASTRO_API FCrackedReplicationData();
};

