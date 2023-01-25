#pragma once
#include "CoreMinimal.h"
#include "SlotIndicatorDefinition.h"
#include "SlotReference.h"
#include "SlotIndicatorLocation.generated.h"

USTRUCT(BlueprintType)
struct FSlotIndicatorLocation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SubslotIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference SlotForIndicator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotIndicatorDefinition IndicatorDef;
    
    ASTRO_API FSlotIndicatorLocation();
};

