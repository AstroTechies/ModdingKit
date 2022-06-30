#include "ActorSolarPowerGeneratorComponent.h"

class UPrimitiveComponent;

void UActorSolarPowerGeneratorComponent::OnSpawnedInSlot() {
}

void UActorSolarPowerGeneratorComponent::OnReleasedFromSlot(bool NewOwner) {
}

void UActorSolarPowerGeneratorComponent::OnPlacedInSlot() {
}

void UActorSolarPowerGeneratorComponent::HandleStoppedGeneratingPower() {
}

void UActorSolarPowerGeneratorComponent::HandleStartedGeneratingPower() {
}

void UActorSolarPowerGeneratorComponent::HandlePickedUpFromWorld(bool PhysicalMovement) {
}

void UActorSolarPowerGeneratorComponent::HandleDroppedInWorld(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal) {
}

UActorSolarPowerGeneratorComponent::UActorSolarPowerGeneratorComponent() {
    this->MinPowerOutput = 0.50f;
    this->MaxPowerOutput = 0.50f;
    this->SolarPanelShouldTrackSun = false;
    this->SunTrackingBehavior = ESolarGeneratorSunTrackingBehavior::Pivot;
    this->SunFacingRotationLimit = 90.00f;
    this->SolarPanelRotatorInterpolationStrength = 4.00f;
    this->CastComponent = NULL;
    this->SunFacingSolarPanel = NULL;
    this->PowerComponent = NULL;
}

