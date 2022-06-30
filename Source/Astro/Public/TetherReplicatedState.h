#pragma once
#include "CoreMinimal.h"
#include "TetherEdgeState.h"
#include "TetherGraphEdge.h"
#include "TetherReplicatedState.generated.h"

class ATetherManager;

USTRUCT(BlueprintType)
struct FTetherReplicatedState {
    GENERATED_BODY()
public:
private:
    UPROPERTY(Transient)
    ATetherManager* Manager;
    
    UPROPERTY(Transient)
    TArray<FTetherEdgeState> StableEdgeArray;
    
    UPROPERTY(Transient)
    TMap<FTetherGraphEdge, int32> AcceleratorTable;
    
public:
    ASTRO_API FTetherReplicatedState();
};

