#pragma once
#include "CoreMinimal.h"
#include "SlotReference.h"
#include "SlottedItemRequirementRuntimeState.generated.h"

USTRUCT(BlueprintType)
struct FSlottedItemRequirementRuntimeState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    FSlotReference SlotRef;
    
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsRequirementSatisfied: 1;
    
    ASTRO_API FSlottedItemRequirementRuntimeState();
};

