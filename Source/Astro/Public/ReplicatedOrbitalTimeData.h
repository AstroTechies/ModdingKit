#pragma once
#include "CoreMinimal.h"
#include "ReplicatedOrbitalTimeData.generated.h"

USTRUCT(BlueprintType)
struct FReplicatedOrbitalTimeData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LaunchTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SourceTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetTime;
    
    ASTRO_API FReplicatedOrbitalTimeData();
};

