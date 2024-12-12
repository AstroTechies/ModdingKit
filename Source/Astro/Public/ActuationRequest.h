#pragma once
#include "CoreMinimal.h"
#include "EAuxSlotType.h"
#include "EFullnessActuatorEventType.h"
#include "ActuationRequest.generated.h"

class UActuatorComponent;
class UObject;

USTRUCT(BlueprintType)
struct FActuationRequest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 DelayTicks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UActuatorComponent> Actuator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EFullnessActuatorEventType FullnessActuatorEventType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObject> UniqueReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EAuxSlotType slotType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool addedDuringQueueIteration;
    
    ASTRO_API FActuationRequest();
};

