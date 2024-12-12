#pragma once
#include "CoreMinimal.h"
#include "ActuatorConnectorRef.generated.h"

USTRUCT(BlueprintType)
struct FActuatorConnectorRef {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ConnectorIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsRerouteNode: 1;
    
    ASTRO_API FActuatorConnectorRef();
};

