#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "RailPostCarSlot.generated.h"

USTRUCT(BlueprintType)
struct FRailPostCarSlot {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    FName CarSlotName;
    
    UPROPERTY(EditDefaultsOnly)
    FName FrontRailSlotName;
    
    UPROPERTY(EditDefaultsOnly)
    FName BackRailSlotName;
    
    UPROPERTY(EditDefaultsOnly)
    uint8 bFrontRailSlotAcceptsGeneratedConnections: 1;
    
    UPROPERTY(EditDefaultsOnly)
    uint8 bBackRailSlotAcceptsGeneratedConnections: 1;
    
    UPROPERTY(EditDefaultsOnly)
    FName CaravanSlotName;
    
protected:
    UPROPERTY(EditDefaultsOnly)
    FComponentReference CaravanSlotPosition;
    
public:
    ASTRO_API FRailPostCarSlot();
};

