#pragma once
#include "CoreMinimal.h"
#include "SlotOrganizationRule.h"
#include "PushTierOrganizationRule.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UPushTierOrganizationRule : public USlotOrganizationRule {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 RequestedItemTier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bShouldAllowLowerTiers: 1;
    
public:
    UPushTierOrganizationRule();

};

