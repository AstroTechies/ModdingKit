#include "InterruptPowerConnectionComponent.h"
#include "Net/UnrealNetwork.h"

UInterruptPowerConnectionComponent::UInterruptPowerConnectionComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    this->bConnectionInterrupted = false;
}

void UInterruptPowerConnectionComponent::ToggleInterrupt(bool bInterrupt) {
}

void UInterruptPowerConnectionComponent::OnRep_ConnectionInterrupted() {
}

void UInterruptPowerConnectionComponent::OnConnectionPostComplete(FSlotReference Slot, ASlotConnection* Connection) {
}

void UInterruptPowerConnectionComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UInterruptPowerConnectionComponent, bConnectionInterrupted);
}


