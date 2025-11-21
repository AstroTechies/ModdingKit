#include "PickUpOnSpawnComponent.h"

UPickUpOnSpawnComponent::UPickUpOnSpawnComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

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


