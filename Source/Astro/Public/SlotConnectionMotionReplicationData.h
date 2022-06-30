#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "Engine/NetSerialization.h"
#include "Engine/NetSerialization.h"
#include "SlotConnectionMotionReplicationData.generated.h"

USTRUCT(BlueprintType)
struct FSlotConnectionMotionReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY()
    FVector_NetQuantize100 TargetLocation;
    
    UPROPERTY()
    FVector_NetQuantize10 TargetRotation;
    
    UPROPERTY()
    FVector_NetQuantizeNormal TargetNormal;
    
    ASTRO_API FSlotConnectionMotionReplicationData();
};

