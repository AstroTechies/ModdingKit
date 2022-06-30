#include "InterruptPowerConnectionComponent.h"
#include "Net/UnrealNetwork.h"

class ASlotConnection;

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

UInterruptPowerConnectionComponent::UInterruptPowerConnectionComponent() {
    this->bConnectionInterrupted = false;
}

