#pragma once
#include "CoreMinimal.h"
#include "ActuatorConnectorRef.generated.h"

USTRUCT(BlueprintType)
struct FActuatorConnectorRef {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    int32 ConnectorIndex;
    
    UPROPERTY(SaveGame)
    uint8 bIsRerouteNode: 1;
    
    ASTRO_API FActuatorConnectorRef();
};

