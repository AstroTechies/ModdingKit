#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SlotReference.h"
#include "SlotBehavior.generated.h"

UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class USlotBehavior : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FSlotReference Slot;

    USlotBehavior();
};
