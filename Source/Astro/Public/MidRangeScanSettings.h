#pragma once
#include "CoreMinimal.h"
#include "MidRangeScanSettings.generated.h"

USTRUCT(BlueprintType)
struct FMidRangeScanSettings {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    float StrongSignalArcPercent;
    
    UPROPERTY(EditDefaultsOnly)
    float WeakSignalArcPercent;
    
    UPROPERTY(EditDefaultsOnly)
    float StrongSignalRotationSpeed;
    
    UPROPERTY(EditDefaultsOnly)
    float NoSignalRotationSpeed;
    
    UPROPERTY(EditDefaultsOnly)
    float PingIntervalSeconds;
    
    ASTRO_API FMidRangeScanSettings();
};

