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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ATetherManager* Manager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FTetherEdgeState> StableEdgeArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FTetherGraphEdge, int32> AcceleratorTable;
    
public:
    ASTRO_API FTetherReplicatedState();
};

