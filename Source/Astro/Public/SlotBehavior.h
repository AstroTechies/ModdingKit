#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SlotReference.h"
#include "SlotBehavior.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USlotBehavior : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference Slot;
    
    USlotBehavior();

};

