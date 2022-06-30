#include "VehicleSlotComponent.h"

class UVehicleSlotComponent;
class AActor;

TArray<UVehicleSlotComponent*> UVehicleSlotComponent::GetConnectedVehicles() {
    return TArray<UVehicleSlotComponent*>();
}

UVehicleSlotComponent* UVehicleSlotComponent::ActorVehicleSlotComponent(AActor* Actor) {
    return NULL;
}

UVehicleSlotComponent::UVehicleSlotComponent() {
    this->AutoSlotDistance = 2500.00f;
    this->MaxConnectedVehicles = 6;
}

