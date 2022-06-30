#include "DamageComponent.h"

class UDamageComponent;
class AActor;

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

UDamageComponent::UDamageComponent() {
    this->Indestructible = false;
}

