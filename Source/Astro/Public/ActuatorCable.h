#pragma once
#include "CoreMinimal.h"
#include "SlotReference.h"
#include "ActuatorConnectorRef.h"
#include "ActuatorCable.generated.h"

USTRUCT(BlueprintType)
struct FActuatorCable {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    FSlotReference SourceSlot;
    
    UPROPERTY(SaveGame)
    FActuatorConnectorRef SourceConnector;
    
    UPROPERTY(SaveGame)
    FActuatorConnectorRef TargetConnector;
    
    UPROPERTY(SaveGame)
    uint8 bInUse: 1;
    
    ASTRO_API FActuatorCable();
};

