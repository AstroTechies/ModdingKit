#pragma once
#include "CoreMinimal.h"
#include "SlotOrganizationRule.h"
#include "OutputOrganizationRule.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UOutputOrganizationRule : public USlotOrganizationRule
{
    GENERATED_BODY()
public:
    UOutputOrganizationRule();
};
