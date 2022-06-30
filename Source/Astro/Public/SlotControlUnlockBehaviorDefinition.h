#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentSubobjectDefinition.h"
#include "SlotControlUnlockBehaviorDefinition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API USlotControlUnlockBehaviorDefinition : public UAstroEntityComponentSubobjectDefinition
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<FName> ControlledSlotNames;

    USlotControlUnlockBehaviorDefinition();
};
