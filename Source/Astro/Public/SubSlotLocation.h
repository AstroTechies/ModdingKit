#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SubSlotLocation.generated.h"

USTRUCT(BlueprintType)
struct FSubSlotLocation {
    GENERATED_BODY()
public:
    UPROPERTY()
    FTransform RelativeOffset;
    
    UPROPERTY()
    uint8 Tier;
    
    UPROPERTY()
    int8 ParentSubslotIndex;
    
    UPROPERTY()
    int8 LeftChildSubslotIndex;
    
    UPROPERTY()
    int8 RightChildSubslotIndex;
    
    UPROPERTY()
    uint8 NumChildren;
    
    ASTRO_API FSubSlotLocation();
};

