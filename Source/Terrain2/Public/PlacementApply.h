#pragma once
#include "CoreMinimal.h"
#include "PlacementApply.generated.h"

class UProceduralPlacement;

USTRUCT(BlueprintType)
struct FPlacementApply {
    GENERATED_BODY()
public:
    UPROPERTY()
    UProceduralPlacement* m_placementType;
    
    TERRAIN2_API FPlacementApply();
};

