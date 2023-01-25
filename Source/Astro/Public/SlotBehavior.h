#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
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

