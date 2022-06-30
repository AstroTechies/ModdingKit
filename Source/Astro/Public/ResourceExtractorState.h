#pragma once
#include "CoreMinimal.h"
#include "EExtractorAnimStage.h"
#include "EExtractorLegStage.h"
#include "ResourceExtractorState.generated.h"

USTRUCT(BlueprintType)
struct FResourceExtractorState {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    int32 CacheIndex;
    
    UPROPERTY(SaveGame)
    int32 ProcessingIndex;
    
    UPROPERTY(SaveGame)
    float AnimProgress;
    
    UPROPERTY(SaveGame)
    TArray<int32> GroupIDs;
    
    UPROPERTY(SaveGame)
    EExtractorAnimStage AnimStage;
    
    UPROPERTY(SaveGame)
    EExtractorLegStage LegStage;
    
    UPROPERTY(SaveGame)
    int32 ActiveGroupID;
    
    UPROPERTY(SaveGame)
    float CycleProgress;
    
    UPROPERTY(SaveGame)
    float CycleProgressAtHammerLift;
    
    ASTRO_API FResourceExtractorState();
};

