#pragma once
#include "CoreMinimal.h"
#include "EActuatorChannel.h"
#include "ActuatorConnectorRef.generated.h"

USTRUCT(BlueprintType)
struct FActuatorConnectorRef {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ConnectorIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsRerouteNode: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EActuatorChannel ActuatorChannel;
    
    ASTRO_API FActuatorConnectorRef();
};

