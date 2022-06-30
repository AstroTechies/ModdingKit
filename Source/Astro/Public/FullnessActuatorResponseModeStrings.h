#pragma once
#include "CoreMinimal.h"
#include "FullnessActuatorResponseModeStrings.generated.h"

USTRUCT(BlueprintType)
struct FFullnessActuatorResponseModeStrings {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    FText ModeDescription;
    
    UPROPERTY(EditDefaultsOnly)
    FText HighThresholdStatusString;
    
    UPROPERTY(EditDefaultsOnly)
    FText LowThresholdStatusString;
    
    UPROPERTY(EditDefaultsOnly)
    FText NotTriggeredStatusString;
    
    ASTRO_API FFullnessActuatorResponseModeStrings();
};

