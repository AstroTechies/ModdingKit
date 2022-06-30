#include "PowerFlowLockingMechanismView.h"
#include "Net/UnrealNetwork.h"

class ULockingMechanism;

void UPowerFlowLockingMechanismView::OnRep_CompletionRatio() {
}

void UPowerFlowLockingMechanismView::OnAccumulatedFullyPoweredTimeChanged(ULockingMechanism* LockingMechanism, const FLockChangedEventMetadata& EventData) {
}

void UPowerFlowLockingMechanismView::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UPowerFlowLockingMechanismView, CompletionRatio);
}

UPowerFlowLockingMechanismView::UPowerFlowLockingMechanismView() {
    this->CompletionRatio = 0.00f;
}

