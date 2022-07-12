#pragma once
#include "CoreMinimal.h"
#include "ECalledCarState.h"
#include "ERailCarMovementState.h"
#include "CalledCarState.generated.h"

USTRUCT(BlueprintType)
struct FCalledCarState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECalledCarState State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float StartingPathDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentPathDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LatestCarSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERailCarMovementState CarMovementState;
    
    ASTRO_API FCalledCarState();
};

