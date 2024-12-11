#include "DestroyAfterComponent.h"

UDestroyAfterComponent::UDestroyAfterComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bStartTimerOnBeginPlay = true;
    this->bTimerStarted = false;
    this->MinLife = 1.00f;
    this->MaxLife = 2.00f;
    this->DestroyParticles = NULL;
}

void UDestroyAfterComponent::StartTimer() {
}

void UDestroyAfterComponent::PlayDestroyParticlesAndDelete(UParticleSystemComponent* particles, float playParticlesAfter, float destroyAfter) {
}


