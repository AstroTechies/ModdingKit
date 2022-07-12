#pragma once
#include "CoreMinimal.h"
#include "SlotReference.h"
#include "EmplacementData.generated.h"

USTRUCT(BlueprintType)
struct FEmplacementData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference Slot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SubslotIndex;
    
    ASTRO_API FEmplacementData();
};

