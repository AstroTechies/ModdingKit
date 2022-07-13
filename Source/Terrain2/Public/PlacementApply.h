#pragma once
#include "CoreMinimal.h"
#include "PlacementApply.generated.h"

class UProceduralPlacement;

USTRUCT(Blueprintable, BlueprintType)
struct FPlacementApply {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UProceduralPlacement* m_placementType;
    
    TERRAIN2_API FPlacementApply();
};

