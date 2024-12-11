#pragma once
#include "CoreMinimal.h"
#include "StormSpawnConfigurationState.h"
#include "StormState.generated.h"

class AAstroStormSpawnLocationCandidate;

USTRUCT(BlueprintType)
struct FStormState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAstroStormSpawnLocationCandidate* StormCandidate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStormSpawnConfigurationState ConfigState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Age;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StormID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FixedStormID;
    
    ASTRO_API FStormState();
};

