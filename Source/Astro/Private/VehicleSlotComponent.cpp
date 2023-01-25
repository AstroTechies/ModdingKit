#include "VehicleSlotComponent.h"

class AActor;
class UVehicleSlotComponent;

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

