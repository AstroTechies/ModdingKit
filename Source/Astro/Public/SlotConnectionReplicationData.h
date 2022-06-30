#pragma once
#include "CoreMinimal.h"
#include "SlotReference.h"
#include "Engine/NetSerialization.h"
#include "SlotConnectionReplicationData.generated.h"

class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct FSlotConnectionReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY()
    FVector_NetQuantizeNormal ComponentHitNormal;
    
    UPROPERTY()
    float TargetScale;
    
    UPROPERTY()
    FSlotReference SourceSlot;
    
    UPROPERTY()
    FSlotReference TargetSlot;
    
    UPROPERTY(Export)
    UPrimitiveComponent* ConnectedComponent;
    
    UPROPERTY()
    bool Destroying;
    
    UPROPERTY()
    bool bIsRetracting;
    
    UPROPERTY()
    bool bIsCarryingOxygen;
    
    ASTRO_API FSlotConnectionReplicationData();
};

