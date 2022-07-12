#pragma once
#include "CoreMinimal.h"
#include "SlotOrganizationRule.h"
#include "PushTierOrganizationRule.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UPushTierOrganizationRule : public USlotOrganizationRule {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    uint8 RequestedItemTier;
    
public:
    UPushTierOrganizationRule();
};

