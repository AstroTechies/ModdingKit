#include "ExplosiveComponent.h"

class AActor;
class UObject;

void UExplosiveComponent::SetDetonationTimerPaused(bool bIsPaused) {
}

void UExplosiveComponent::SetDetonationTimer(float DeltaTime) {
}

void UExplosiveComponent::MulticastWreckageDestroyAudio_Implementation(FTransform xform, UObject* contextObject) {
}

bool UExplosiveComponent::ExplosiveDestroyActor(AActor* ToDestroy, bool GetOutermostActor) {
    return false;
}

void UExplosiveComponent::DoExplosionDeformation(const FVector Location, float Radius) {
}

void UExplosiveComponent::DoBlastDamage(const FVector Location, float Radius, float Intensity) {
}

void UExplosiveComponent::Detonate() {
}

void UExplosiveComponent::DamageActor(AActor* Actor, const FVector Direction, float Intensity) {
}

void UExplosiveComponent::CancelDetonationTimer() {
}

UExplosiveComponent::UExplosiveComponent() {
    this->Power = 0.00f;
    this->AutoResourceGenerationPercentage = 0.00f;
    this->CombineExplosionsRadiusRatio = 0.50f;
    this->ExplosionRadiusCraterScale = 0.50f;
    this->PowerToRadiusScale = 1600.00f;
    this->DamageTypeClass = NULL;
    this->IsEnabled = true;
    this->EffectsConfig = NULL;
    this->CombinedPower = 0.00f;
    this->CombinedRadius = 0.00f;
}

