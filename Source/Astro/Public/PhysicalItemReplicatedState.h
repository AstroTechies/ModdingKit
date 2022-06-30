#pragma once
#include "CoreMinimal.h"
#include "EPhysicalItemMotionState.h"
#include "SlotReference.h"
#include "PhysicalItemReplicatedState.generated.h"

USTRUCT(BlueprintType)
struct FPhysicalItemReplicatedState {
    GENERATED_BODY()
public:
    UPROPERTY()
    EPhysicalItemMotionState MotionState;
    
    UPROPERTY()
    FSlotReference ItemSlot;
    
    UPROPERTY()
    FSlotReference PreviousItemSlot;
    
    UPROPERTY()
    int32 SubslotIndex;
    
    UPROPERTY()
    uint8 SlotFacingCardinalDirection;
    
    UPROPERTY()
    uint8 LastSlotFromTool: 1;
    
    UPROPERTY()
    uint8 LastSlotOnInitialization: 1;
    
    UPROPERTY()
    uint8 PartOfSwap: 1;
    
    ASTRO_API FPhysicalItemReplicatedState();
};

