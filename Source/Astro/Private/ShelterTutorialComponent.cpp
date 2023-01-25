#include "ShelterTutorialComponent.h"

class APhysicalItem;
class ASlotConnection;

void UShelterTutorialComponent::StopCableTutorial() {
}

void UShelterTutorialComponent::SetupCableTutorial(TArray<FSlotReference> shelterCableSlots, APhysicalItem* Platform) {
}

void UShelterTutorialComponent::SetCableTutorialKey(FName tutorialKey) {
}

void UShelterTutorialComponent::OnCablePulled(FSlotReference cableSlot, ASlotConnection* cable) {
}

void UShelterTutorialComponent::OnCableDestroyed(FSlotReference cableSlot, ASlotConnection* cable) {
}

void UShelterTutorialComponent::OnCableConnected(FSlotReference cableSlot, ASlotConnection* cable) {
}

UShelterTutorialComponent::UShelterTutorialComponent() {
    this->GrabSlotIndicator = NULL;
    this->AttachSlotIndicator = NULL;
    this->CableTutorialIsComplete = false;
}

