#pragma once
#include "CoreMinimal.h"
#include "PlacementApply.generated.h"

class UProceduralPlacement;

USTRUCT(BlueprintType)
struct FPlacementApply {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UProceduralPlacement* m_placementType;
    
    TERRAIN2_API FPlacementApply();
};

