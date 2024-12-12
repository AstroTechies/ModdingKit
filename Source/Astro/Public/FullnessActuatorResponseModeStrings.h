#pragma once
#include "CoreMinimal.h"
#include "FullnessActuatorResponseModeStrings.generated.h"

USTRUCT(BlueprintType)
struct FFullnessActuatorResponseModeStrings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ModeDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText HighThresholdStatusString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText LowThresholdStatusString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText NotTriggeredStatusString;
    
    ASTRO_API FFullnessActuatorResponseModeStrings();
};

