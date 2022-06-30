#pragma once
#include "CoreMinimal.h"
#include "SlotReference.h"
#include "UObject/NoExportTypes.h"
#include "ActuatorConnector.generated.h"

class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct FActuatorConnector {
    GENERATED_BODY()
public:
    UPROPERTY(Export, SaveGame)
    UPrimitiveComponent* TargetComponent;
    
    UPROPERTY(SaveGame)
    FSlotReference TargetSlot;
    
    UPROPERTY(SaveGame)
    FTransform WorldTransform;
    
    UPROPERTY(SaveGame)
    FTransform TargetRelativeTransform;
    
    UPROPERTY(SaveGame)
    int32 ParentCable;
    
    UPROPERTY(SaveGame)
    TArray<int32> ChildCables;
    
    UPROPERTY(SaveGame)
    uint8 bInUse: 1;
    
    ASTRO_API FActuatorConnector();
};

