#pragma once
#include "CoreMinimal.h"
#include "EPlanetIdentifier.h"
#include "StormSpawnHistoryContainer.h"
#include "StormState.h"
#include "StormStates.generated.h"

USTRUCT(BlueprintType)
struct FStormStates {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EPlanetIdentifier planetID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FStormState> StormStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<int32> ActiveStormIndexes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FStormSpawnHistoryContainer> PerStormIDSpawnHistories;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<int32> AvailableStormIDs;
    
    ASTRO_API FStormStates();
};

