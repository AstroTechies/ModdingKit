#include "HangingSlotComponent.h"

UHangingSlotComponent::UHangingSlotComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->HangingSlotDistance = 250.00f;
    this->IsReadyActor = false;
    this->RingTargeter = NULL;
}

void UHangingSlotComponent::PositionConnection(ASlotConnection* Connection, APlayController* Controller, FVector& outNormal, FVector& OutLocation) {
}

void UHangingSlotComponent::ConnectAndTargetSlot(FSlotReference Slot) {
}

void UHangingSlotComponent::ConnectAndTarget(ASlotConnection* Connection) {
}


