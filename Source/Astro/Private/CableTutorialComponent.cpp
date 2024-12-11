#include "CableTutorialComponent.h"

UCableTutorialComponent::UCableTutorialComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CableTutorialIsComplete = false;
    this->receiverItem = NULL;
    this->providerItem = NULL;
    this->ReceiverSlotComponent = NULL;
    this->ProviderSlotComponent = NULL;
    this->CurrentGrabTooltipComponent = NULL;
    this->CurrentAttachTooltipComponent = NULL;
}

void UCableTutorialComponent::StopCableTutorial() {
}

void UCableTutorialComponent::SetupCableTutorial(APhysicalItem* NewReceiverItem, APhysicalItem* NewProviderItem, bool completeIfReceiverAlreadyPowered) {
}

void UCableTutorialComponent::OnReceiverItemSlotted() {
}

void UCableTutorialComponent::OnReceiverItemPickedUp(bool physicalMovementOrNewOwner) {
}

void UCableTutorialComponent::OnReceiverItemPadSpawned() {
}

void UCableTutorialComponent::OnReceiverItemDropped(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal) {
}

void UCableTutorialComponent::OnProviderItemSlotted() {
}

void UCableTutorialComponent::OnProviderItemPickedUp(bool physicalMovementOrNewOwner) {
}

void UCableTutorialComponent::OnProviderItemPadSpawned() {
}

void UCableTutorialComponent::OnProviderItemDropped(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal) {
}

void UCableTutorialComponent::OnCablePulled(FSlotReference cableSlot, ASlotConnection* cable) {
}

void UCableTutorialComponent::OnCableDestroyed(FSlotReference cableSlot, ASlotConnection* cable) {
}

void UCableTutorialComponent::OnCableConnected(FSlotReference cableSlot, ASlotConnection* cable) {
}


