#pragma once
#include "CoreMinimal.h"
#include "TetherGraphEdge.h"
#include "EdgeVisualComponent.h"
#include "TetherEdgeState.generated.h"

USTRUCT(BlueprintType)
struct FTetherEdgeState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTetherGraphEdge Edge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEdgeVisualComponent View;
    
    ASTRO_API FTetherEdgeState();
};

