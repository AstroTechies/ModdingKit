#pragma once
#include "CoreMinimal.h"
#include "ActuatorCable.h"
#include "ActuatorConnector.h"
#include "ActuatorConnections.generated.h"

USTRUCT(BlueprintType)
struct FActuatorConnections {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FActuatorCable> Cables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FActuatorConnector> Connectors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FActuatorConnector> RerouteNodes;
    
    ASTRO_API FActuatorConnections();
};

