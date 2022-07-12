#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
#include "SubSlotLocation.generated.h"

USTRUCT(BlueprintType)
struct FSubSlotLocation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform RelativeOffset;
    
    UPROPERTY(EditAnywhere)
    uint8 Tier;
    
    UPROPERTY(EditAnywhere)
    int8 ParentSubslotIndex;
    
    UPROPERTY(EditAnywhere)
    int8 LeftChildSubslotIndex;
    
    UPROPERTY(EditAnywhere)
    int8 RightChildSubslotIndex;
    
    UPROPERTY(EditAnywhere)
    uint8 NumChildren;
    
    ASTRO_API FSubSlotLocation();
};

