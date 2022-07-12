#pragma once
#include "CoreMinimal.h"
#include "ProceduralExpressionInput.h"
#include "PlacementTypeExpPair.generated.h"

class UProceduralPlacement;

USTRUCT(BlueprintType)
struct FPlacementTypeExpPair {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FProceduralExpressionInput Density;
    
    UPROPERTY(EditAnywhere)
    UProceduralPlacement* Type;
    
    TERRAIN2_API FPlacementTypeExpPair();
};

