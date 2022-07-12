#pragma once
#include "CoreMinimal.h"
#include "SlotOrganizationRule.h"
#include "TierOrganizationRule.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UTierOrganizationRule : public USlotOrganizationRule {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    uint8 RequestedItemTier;
    
public:
    UTierOrganizationRule();
};

