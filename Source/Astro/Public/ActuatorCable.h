#pragma once
#include "CoreMinimal.h"
#include "SlotReference.h"
#include "ActuatorConnectorRef.h"
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
    
    ASTRO_API FActuatorCable();
};

