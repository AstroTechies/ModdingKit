#include "HangingSlotComponent.h"

class APlayController;
class ASlotConnection;

void UHangingSlotComponent::PositionConnection(ASlotConnection* Connection, APlayController* Controller, FVector& outNormal, FVector& OutLocation) {
}

void UHangingSlotComponent::ConnectAndTargetSlot(FSlotReference Slot) {
}

void UHangingSlotComponent::ConnectAndTarget(ASlotConnection* Connection) {
}

UHangingSlotComponent::UHangingSlotComponent() {
    this->HangingSlotDistance = 250.00f;
    this->IsReadyActor = false;
    this->RingTargeter = NULL;
}

