#include "UseTriggerComponent.h"

UUseTriggerComponent::UUseTriggerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bTriggeredByPlayers = false;
    this->TriggerItems = NULL;
    this->CooldownTime = 1.00f;
    this->TriggerItemList = NULL;
    this->CurrentInstigator = NULL;
}

void UUseTriggerComponent::OnTriggerVolumeOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void UUseTriggerComponent::OnCooldownCompleted() {
}


