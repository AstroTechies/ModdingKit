#pragma once
#include "CoreMinimal.h"
#include "TetherGraphEdge.h"
#include "TetherEdgeArray.generated.h"

USTRUCT(BlueprintType)
struct FTetherEdgeArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTetherGraphEdge> Array;
    
    ASTRO_API FTetherEdgeArray();
};

