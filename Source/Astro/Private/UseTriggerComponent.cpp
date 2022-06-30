#include "UseTriggerComponent.h"

class UPrimitiveComponent;
class AActor;

void UUseTriggerComponent::OnTriggerVolumeOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void UUseTriggerComponent::OnCooldownCompleted() {
}

UUseTriggerComponent::UUseTriggerComponent() {
    this->bTriggeredByPlayers = false;
    this->TriggerItems = NULL;
    this->CooldownTime = 1.00f;
    this->TriggerItemList = NULL;
    this->CurrentInstigator = NULL;
}

