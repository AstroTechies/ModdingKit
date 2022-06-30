#pragma once
#include "CoreMinimal.h"
#include "SlotReference.h"
#include "SlotIndicatorDefinition.h"
#include "SlotIndicatorLocation.generated.h"

USTRUCT(BlueprintType)
struct FSlotIndicatorLocation {
    GENERATED_BODY()
public:
    UPROPERTY()
    int32 SubslotIndex;
    
    UPROPERTY()
    FSlotReference SlotForIndicator;
    
    UPROPERTY()
    FSlotIndicatorDefinition IndicatorDef;
    
    ASTRO_API FSlotIndicatorLocation();
};

