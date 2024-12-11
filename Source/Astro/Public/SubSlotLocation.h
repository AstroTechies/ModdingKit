#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SubSlotLocation.generated.h"

USTRUCT(BlueprintType)
struct FSubSlotLocation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform RelativeOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 Tier;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int8 ParentSubslotIndex;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int8 LeftChildSubslotIndex;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int8 RightChildSubslotIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 NumChildren;
    
    ASTRO_API FSubSlotLocation();
};

