#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "Engine/NetSerialization.h"
#include "Engine/NetSerialization.h"
#include "SlotConnectionClientMotionData.generated.h"

USTRUCT(BlueprintType)
struct FSlotConnectionClientMotionData {
    GENERATED_BODY()
public:
    UPROPERTY()
    FVector_NetQuantize100 TargetLocation;
    
    UPROPERTY()
    FVector_NetQuantize10 TargetRotation;
    
    UPROPERTY()
    FVector_NetQuantizeNormal TargetNormal;
    
    UPROPERTY()
    bool bIsHoveringOverSlot;
    
    ASTRO_API FSlotConnectionClientMotionData();
};

