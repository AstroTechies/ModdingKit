#pragma once
#include "CoreMinimal.h"
#include "ActuatorConnectorRef.h"
#include "EActuatorChannel.h"
#include "SlotReference.h"
#include "ActuatorCable.generated.h"

USTRUCT(BlueprintType)
struct FActuatorCable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FSlotReference SourceSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FActuatorConnectorRef SourceConnector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FActuatorConnectorRef TargetConnector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bInUse: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EActuatorChannel ActuatorChannel;
    
    ASTRO_API FActuatorCable();
};

