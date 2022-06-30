#pragma once
#include "CoreMinimal.h"
#include "UnlockBehavior.h"
#include "SlotReference.h"
#include "SlotControlUnlockBehavior.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API USlotControlUnlockBehavior : public UUnlockBehavior
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(SaveGame)
    TArray<FSlotReference> ControlledSlotRefs;

public:
    USlotControlUnlockBehavior();
};
