#pragma once
#include "CoreMinimal.h"
#include "TetherGraphEdge.h"
#include "TetherEdgeState.h"
#include "TetherReplicatedState.generated.h"

class ATetherManager;

static uint32 GetTypeHash(const FTetherGraphEdge& TypeVar) {
    return 0;
}

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

