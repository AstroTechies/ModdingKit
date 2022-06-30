#include "ControlActivatorComponent.h"
#include "Net/UnrealNetwork.h"

class AActor;

void UControlActivatorComponent::OnRep_ControlledToolActor(AActor* oldActor) {
}

void UControlActivatorComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UControlActivatorComponent, ControlledToolActor);
    DOREPLIFETIME(UControlActivatorComponent, PassengerToolActor);
}

UControlActivatorComponent::UControlActivatorComponent() {
    this->ActiveControl = NULL;
    this->ControlledToolActor = NULL;
    this->PassengerToolActor = NULL;
    this->ChangedControlActor = false;
}

