#include "CableExtenderTutorialComponent.h"

class AActor;
class ASlotConnection;
class UPrimitiveComponent;

void UCableExtenderTutorialComponent::StopTutorial() {
}

void UCableExtenderTutorialComponent::SetupTutorial() {
}

void UCableExtenderTutorialComponent::SetExtenderTutorialKey(FName tutorialKey) {
}

void UCableExtenderTutorialComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void UCableExtenderTutorialComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void UCableExtenderTutorialComponent::OnCableTargetReleased(FSlotReference cableSlot, ASlotConnection* cable) {
}

void UCableExtenderTutorialComponent::OnCablePulled(FSlotReference cableSlot, ASlotConnection* cable) {
}

void UCableExtenderTutorialComponent::OnCableDestroyed(FSlotReference cableSlot, ASlotConnection* cable) {
}

void UCableExtenderTutorialComponent::OnCableConnected(FSlotReference cableSlot, ASlotConnection* cable) {
}

UCableExtenderTutorialComponent::UCableExtenderTutorialComponent() {
    this->CableSocketSearchRadius = 1000.00f;
    this->SocketIndicatorType = NULL;
    this->ExtenderIndicatorType = NULL;
    this->ExtenderItemType = NULL;
    this->CollisionSphere = NULL;
}

