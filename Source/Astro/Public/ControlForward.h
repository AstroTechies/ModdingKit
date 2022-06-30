#pragma once
#include "CoreMinimal.h"
#include "SlotReference.h"
#include "ControlForward.generated.h"

USTRUCT(BlueprintType)
struct FControlForward {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FSlotReference Slot;
    
    ASTRO_API FControlForward();
};

