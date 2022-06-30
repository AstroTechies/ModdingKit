#pragma once
#include "CoreMinimal.h"
#include "PackedParameterValue.generated.h"

USTRUCT(BlueprintType)
struct FPackedParameterValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    int32 PackedSlotIndex;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    int32 PackedValue;
    
    ASTRO_API FPackedParameterValue();
};

