#pragma once
#include "CoreMinimal.h"
#include "TetherGraphEdge.h"
#include "EdgeVisualComponent.h"
#include "TetherEdgeState.generated.h"

USTRUCT(BlueprintType)
struct FTetherEdgeState {
    GENERATED_BODY()
public:
    UPROPERTY()
    FTetherGraphEdge Edge;
    
    UPROPERTY()
    FEdgeVisualComponent View;
    
    ASTRO_API FTetherEdgeState();
};

