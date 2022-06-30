#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SlotReference.h"
#include "SlotTransition.generated.h"

class APhysicalItem;

USTRUCT(BlueprintType)
struct FSlotTransition {
    GENERATED_BODY()
public:
    UPROPERTY()
    FName ThisSlot;
    
    UPROPERTY()
    float Alpha;
    
    UPROPERTY()
    FTransform InitialTransform;
    
    UPROPERTY()
    FSlotReference SourceSlot;
    
    UPROPERTY()
    int32 SubslotIndex;
    
    UPROPERTY()
    int32 SourceSubSlotIndex;
    
    UPROPERTY()
    APhysicalItem* ItemIncomingToBundle;
    
    ASTRO_API FSlotTransition();
};

