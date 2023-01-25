#pragma once
#include "CoreMinimal.h"
#include "SlotOrganizationRule.h"
#include "Templates/SubclassOf.h"
#include "T2CanisterOrganizationRule.generated.h"

class UItemType;

UCLASS(Blueprintable, EditInlineNew)
class UT2CanisterOrganizationRule : public USlotOrganizationRule {
    GENERATED_BODY()
public:
    UT2CanisterOrganizationRule();
    UFUNCTION(BlueprintCallable)
    void SetStoredItemTypeWhitelist(TArray<TSubclassOf<UItemType>> ItemTypes);
    
    UFUNCTION(BlueprintCallable)
    void SetMode(bool isDispensing);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentStoredItemType(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable)
    void OnSlottedItemDrainedOrFilled();
    
};

