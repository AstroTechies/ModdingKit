#include "AuxSlotItemTooltipComponent.h"

UAuxSlotItemTooltipComponent::UAuxSlotItemTooltipComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TooltipTimeoutDuration = 2.00f;
    this->bOverrideInputActionName = false;
}

void UAuxSlotItemTooltipComponent::TooltipTimeout() {
}

void UAuxSlotItemTooltipComponent::MulticastOnOwnerItemAuxUsed_Implementation(AAstroPlayerController* controllingPlayer) {
}
bool UAuxSlotItemTooltipComponent::MulticastOnOwnerItemAuxUsed_Validate(AAstroPlayerController* controllingPlayer) {
    return true;
}

void UAuxSlotItemTooltipComponent::HandleVehicleUnmanned(AAstroPlayerController* OldPilot) {
}

void UAuxSlotItemTooltipComponent::HandleVehicleManned(AAstroPlayerController* NewPilot) {
}

void UAuxSlotItemTooltipComponent::HandleReleasedFromSlot(bool NewOwner) {
}

void UAuxSlotItemTooltipComponent::HandlePlacedInSlot() {
}


