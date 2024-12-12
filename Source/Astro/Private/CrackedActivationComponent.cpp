#include "CrackedActivationComponent.h"
#include "Activation.h"

UCrackedActivationComponent::UCrackedActivationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Activation = CreateDefaultSubobject<UActivation>(TEXT("Activation"));
    this->CrackedValue = 0.00f;
}

void UCrackedActivationComponent::OnCracked() {
}

void UCrackedActivationComponent::OnClosed() {
}

UCrackedActivationComponent* UCrackedActivationComponent::ActorCrackedActivationComponent(AActor* Actor) {
    return NULL;
}


