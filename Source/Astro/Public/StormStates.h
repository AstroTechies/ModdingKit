#pragma once
#include "CoreMinimal.h"
#include "StormSpawnHistoryContainer.h"
#include "StormState.h"
#include "StormStates.generated.h"

USTRUCT(BlueprintType)
struct FStormStates {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStormState> StormStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> ActiveStormIndexes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, FStormSpawnHistoryContainer> PerStormIDSpawnHistories;
    
    ASTRO_API FStormStates();
};

