#include "CrackedActivationComponent.h"
#include "Activation.h"

class AActor;
class UCrackedActivationComponent;

void UCrackedActivationComponent::OnCracked() {
}

void UCrackedActivationComponent::OnClosed() {
}

UCrackedActivationComponent* UCrackedActivationComponent::ActorCrackedActivationComponent(AActor* Actor) {
    return NULL;
}

UCrackedActivationComponent::UCrackedActivationComponent() {
    this->Activation = CreateDefaultSubobject<UActivation>(TEXT("Activation"));
    this->CrackedValue = 0.00f;
}

