#pragma once
#include "CoreMinimal.h"
#include "EFullnessActuatorEventType.h"
#include "ActuationRequest.generated.h"

class UActuatorComponent;
class UObject;

USTRUCT(BlueprintType)
struct FActuationRequest {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    int32 DelayTicks;
    
    UPROPERTY(Export, SaveGame)
    TWeakObjectPtr<UActuatorComponent> Actuator;
    
    UPROPERTY(SaveGame)
    EFullnessActuatorEventType FullnessActuatorEventType;
    
    UPROPERTY(SaveGame)
    TWeakObjectPtr<UObject> UniqueReference;
    
    UPROPERTY(SaveGame)
    bool addedDuringQueueIteration;
    
    ASTRO_API FActuationRequest();
};

