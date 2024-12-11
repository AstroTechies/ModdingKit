#include "CustomGravityVolumeComponent.h"

UCustomGravityVolumeComponent::UCustomGravityVolumeComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->GravityStrength = 6.50f;
    this->GravityVolume = NULL;
}

void UCustomGravityVolumeComponent::OnComponentExitedCustomGravityVolume(UPrimitiveComponent* volumeComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex) {
}

void UCustomGravityVolumeComponent::OnComponentEnteredCustomGravityVolume(UPrimitiveComponent* volumeComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}


