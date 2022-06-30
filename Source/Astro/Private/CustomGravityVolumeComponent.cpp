#include "CustomGravityVolumeComponent.h"

class UPrimitiveComponent;
class AActor;

void UCustomGravityVolumeComponent::OnComponentExitedCustomGravityVolume(UPrimitiveComponent* volumeComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex) {
}

void UCustomGravityVolumeComponent::OnComponentEnteredCustomGravityVolume(UPrimitiveComponent* volumeComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

UCustomGravityVolumeComponent::UCustomGravityVolumeComponent() {
    this->GravityStrength = 6.50f;
    this->GravityVolume = NULL;
}

