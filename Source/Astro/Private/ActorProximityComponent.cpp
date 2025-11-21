#include "ActorProximityComponent.h"
#include "Net/UnrealNetwork.h"

UActorProximityComponent::UActorProximityComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ProximityEventTriggerDistance = 0.00f;
    this->ProximitySphereComponent = NULL;
}

void UActorProximityComponent::OnRep_ReplicationData() {
}

void UActorProximityComponent::OnProximitySphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void UActorProximityComponent::OnProximitySphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void UActorProximityComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UActorProximityComponent, ReplicationData);
}


