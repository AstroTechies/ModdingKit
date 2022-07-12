#include "PickUpOnSpawnComponent.h"

class APlayController;

void UPickUpOnSpawnComponent::ServerOnHandledLocalPickUp_Implementation() {
}
bool UPickUpOnSpawnComponent::ServerOnHandledLocalPickUp_Validate() {
    return true;
}

void UPickUpOnSpawnComponent::MulticastSetOwningPlayer_Implementation(APlayController* Player) {
}
bool UPickUpOnSpawnComponent::MulticastSetOwningPlayer_Validate(APlayController* Player) {
    return true;
}

void UPickUpOnSpawnComponent::HandleOwnerChanged() {
}

UPickUpOnSpawnComponent::UPickUpOnSpawnComponent() {
}

