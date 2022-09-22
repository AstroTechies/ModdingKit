#include "AuxSlotItemTooltipComponent.h"

class AAstroPlayerController;

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

UAuxSlotItemTooltipComponent::UAuxSlotItemTooltipComponent() {
    this->TooltipTimeoutDuration = 2.00f;
}

