#include "PhysicsComponent.h"
#include "Net/UnrealNetwork.h"

class AActor;
class UPhysicsComponent;

void UPhysicsComponent::SetTraceEnabled(bool Enabled) {
}

void UPhysicsComponent::SetPhysicsEnabled(bool Enabled) {
}

void UPhysicsComponent::SetCollisionEnabled(bool Enabled) {
}

void UPhysicsComponent::OnRep_PhysicsState() {
}

UPhysicsComponent* UPhysicsComponent::GetActorPhysicsComponent(AActor* Actor) {
    return NULL;
}

void UPhysicsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UPhysicsComponent, PhysicsState);
}

UPhysicsComponent::UPhysicsComponent() {
}

