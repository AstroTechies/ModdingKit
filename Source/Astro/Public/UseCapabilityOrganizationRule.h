#pragma once
#include "CoreMinimal.h"
#include "SlotOrganizationRule.h"
#include "EUseType.h"
#include "UseCapabilityOrganizationRule.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UUseCapabilityOrganizationRule : public USlotOrganizationRule
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    EUseType RequestedUseType;

    UUseCapabilityOrganizationRule();
};
