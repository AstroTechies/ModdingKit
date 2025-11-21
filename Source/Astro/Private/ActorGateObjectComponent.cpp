#include "ActorGateObjectComponent.h"
#include "Net/UnrealNetwork.h"

UActorGateObjectComponent::UActorGateObjectComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bHasPlayerProximityEvent = false;
    this->bAnimatesInOutroCinematic = false;
    this->PlayerProximityEventTriggerDistance = 0.00f;
    this->ProximitySphereComponent = NULL;
}

void UActorGateObjectComponent::OnRep_ReplicationData() {
}

void UActorGateObjectComponent::OnPlayerProximitySphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void UActorGateObjectComponent::OnPlayerProximitySphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void UActorGateObjectComponent::OnOutroCinematicStarted() {
}

void UActorGateObjectComponent::OnOutroCinematicCompleted() {
}

void UActorGateObjectComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UActorGateObjectComponent, ReplicationData);
}


