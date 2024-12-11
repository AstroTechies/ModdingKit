#pragma once
#include "CoreMinimal.h"
#include "StormSpawnHistoryContainer.generated.h"

USTRUCT(BlueprintType)
struct FStormSpawnHistoryContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> SpawnCandidateHistory;
    
    ASTRO_API FStormSpawnHistoryContainer();
};

