#include "VehicleSlotComponent.h"

UVehicleSlotComponent::UVehicleSlotComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AutoSlotDistance = 2500.00f;
    this->MaxConnectedVehicles = 6;
}

TArray<UVehicleSlotComponent*> UVehicleSlotComponent::GetConnectedVehicles() {
    return TArray<UVehicleSlotComponent*>();
}

UVehicleSlotComponent* UVehicleSlotComponent::ActorVehicleSlotComponent(AActor* Actor) {
    return NULL;
}


