#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SlotOrganizationRule.h"
#include "BlueprintableSlotOrganizationRule.generated.h"

class UItemType;
class APhysicalItem;

UCLASS(Blueprintable, EditInlineNew)
class UBlueprintableSlotOrganizationRule : public USlotOrganizationRule {
    GENERATED_BODY()
public:
    UBlueprintableSlotOrganizationRule();
protected:
    UFUNCTION(BlueprintImplementableEvent)
    TArray<APhysicalItem*> AuthorityGetWantedItems_Blueprint(const TArray<APhysicalItem*>& availableItems) const;
    
    UFUNCTION(BlueprintImplementableEvent)
    TArray<APhysicalItem*> AuthorityGetUnwantedItemsInManagedSlots_Blueprint() const;
    
    UFUNCTION(BlueprintImplementableEvent)
    TArray<TSubclassOf<UItemType>> AuthorityGetDesiredIndicators_Blueprint() const;
    
};

