#include "SlotOrganizationRule.h"
#include "Net/UnrealNetwork.h"

USlotOrganizationRule::USlotOrganizationRule() {
    this->AllowedStorageChassis = NULL;
    this->Priority = 3;
    this->IndicatorType = EIndicatorTooltipType::ResourceRequest;
    this->bPushUnwantedItems = true;
    this->bEjectUnwantedItems = false;
    this->bIsEnabled = true;
    this->bShouldFillAllSlots = false;
    this->UnwantedItemEjectionForce = 25000.00f;
}

void USlotOrganizationRule::SetUnwantedItemsEjectionForce(float ejectionForce) {
}

void USlotOrganizationRule::SetPushUnwantedItems(bool push) {
}

void USlotOrganizationRule::SetEnabled(bool Enabled, bool broadcastSettingsChanged) {
}

void USlotOrganizationRule::SetEjectUnwantedItems(bool eject) {
}

void USlotOrganizationRule::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(USlotOrganizationRule, bIsEnabled);
    DOREPLIFETIME(USlotOrganizationRule, ManagedSlotRefs);
}


