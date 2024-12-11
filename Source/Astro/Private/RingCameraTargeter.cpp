#include "RingCameraTargeter.h"

URingCameraTargeter::URingCameraTargeter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AvoidRadians = 1.00f;
    this->Target = NULL;
    this->Center = NULL;
    this->CenterDistance = 250.00f;
    this->LerpSpeed = 4.00f;
    this->PlayerCameraTargetLerp = 0.50f;
}

void URingCameraTargeter::SnapToTargetLocation(const FVector& TargetLocation) {
}

void URingCameraTargeter::SnapToTarget(APlayController* Controller) {
}

void URingCameraTargeter::SetTarget(USceneComponent* TargetComponent, USceneComponent* RingCenter, FSlotReference TargetingSlot) {
}

void URingCameraTargeter::OnSlotDisconnected(FSlotReference ConnectedSlot, ASlotConnection* Connection) {
}

void URingCameraTargeter::OnSlotConnected(FSlotReference ConnectedSlot, ASlotConnection* Connection) {
}

URingCameraTargeter* URingCameraTargeter::ActorRingCameraTargeter(AActor* Actor) {
    return NULL;
}


