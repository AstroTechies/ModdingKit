#pragma once
#include "CoreMinimal.h"
#include "ActuatorCable.h"
#include "ActuatorConnector.h"
#include "ActuatorConnections.generated.h"

USTRUCT(BlueprintType)
struct FActuatorConnections {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    TArray<FActuatorCable> Cables;
    
    UPROPERTY(SaveGame)
    TArray<FActuatorConnector> Connectors;
    
    UPROPERTY(SaveGame)
    TArray<FActuatorConnector> RerouteNodes;
    
    ASTRO_API FActuatorConnections();
};

