#include "ControlActivatorComponent.h"
#include "Net/UnrealNetwork.h"

UControlActivatorComponent::UControlActivatorComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    this->ActiveControl = NULL;
    this->ControlledToolActor = NULL;
    this->PassengerToolActor = NULL;
    this->ChangedControlActor = false;
}

void UControlActivatorComponent::OnRep_ControlledToolActor(AActor* oldActor) {
}

void UControlActivatorComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UControlActivatorComponent, ControlledToolActor);
    DOREPLIFETIME(UControlActivatorComponent, PassengerToolActor);
}


