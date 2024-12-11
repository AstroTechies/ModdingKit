#include "DamageComponent.h"

UDamageComponent::UDamageComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Indestructible = false;
}

bool UDamageComponent::Kill(bool ignoreIndestructible) {
    return false;
}

void UDamageComponent::DealDamage(float Amount) {
}

void UDamageComponent::AuthoritySetIndestructible(bool bIndestructible) {
}

UDamageComponent* UDamageComponent::ActorDamageComponent(AActor* Actor) {
    return NULL;
}


