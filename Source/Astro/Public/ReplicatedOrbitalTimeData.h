#pragma once
#include "CoreMinimal.h"
#include "ReplicatedOrbitalTimeData.generated.h"

USTRUCT(BlueprintType)
struct FReplicatedOrbitalTimeData {
    GENERATED_BODY()
public:
    UPROPERTY()
    float LaunchTime;
    
    UPROPERTY()
    float CurrentTime;
    
    UPROPERTY()
    float SourceTime;
    
    UPROPERTY()
    float TargetTime;
    
    ASTRO_API FReplicatedOrbitalTimeData();
};

