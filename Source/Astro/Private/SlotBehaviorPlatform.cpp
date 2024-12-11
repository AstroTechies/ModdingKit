#include "SlotBehaviorPlatform.h"

USlotBehaviorPlatform::USlotBehaviorPlatform() {
    this->AllowBodies = false;
    this->HoverHeight = 0.00f;
    this->KinematicMovementDuration = 0.50f;
    this->bDisableCollisionAfterPlace = false;
    this->Parent = NULL;
}

void USlotBehaviorPlatform::OnParentDeformed(const FDeformationParamsT2& params) {
}

void USlotBehaviorPlatform::OnActorOverlappedDuringKinematicMovement(UPrimitiveComponent* ownerRootPrimitive, AActor* OverlappedActor, UPrimitiveComponent* OverlappedComponent) {
}


