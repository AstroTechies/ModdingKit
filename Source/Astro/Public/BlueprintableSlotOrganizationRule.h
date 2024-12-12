#pragma once
#include "CoreMinimal.h"
#include "SlotOrganizationRule.h"
#include "Templates/SubclassOf.h"
#include "BlueprintableSlotOrganizationRule.generated.h"

class APhysicalItem;
class UItemType;

UCLASS(Blueprintable, EditInlineNew)
class UBlueprintableSlotOrganizationRule : public USlotOrganizationRule {
    GENERATED_BODY()
public:
    UBlueprintableSlotOrganizationRule();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    TArray<APhysicalItem*> AuthorityGetWantedItems_Blueprint(const TArray<APhysicalItem*>& availableItems) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    TArray<APhysicalItem*> AuthorityGetUnwantedItemsInManagedSlots_Blueprint() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    TArray<TSubclassOf<UItemType>> AuthorityGetDesiredIndicators_Blueprint() const;
    
};

