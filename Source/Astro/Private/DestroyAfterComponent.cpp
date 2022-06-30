#include "DestroyAfterComponent.h"

class UParticleSystemComponent;

void UDestroyAfterComponent::StartTimer() {
}

void UDestroyAfterComponent::PlayDestroyParticlesAndDelete(UParticleSystemComponent* particles, float playParticlesAfter, float destroyAfter) {
}

UDestroyAfterComponent::UDestroyAfterComponent() {
    this->bStartTimerOnBeginPlay = true;
    this->bTimerStarted = false;
    this->MinLife = 1.00f;
    this->MaxLife = 2.00f;
    this->DestroyParticles = NULL;
}

