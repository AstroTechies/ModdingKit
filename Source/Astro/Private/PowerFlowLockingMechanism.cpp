#include "PowerFlowLockingMechanism.h"

UPowerFlowLockingMechanism::UPowerFlowLockingMechanism() {
    this->AccumulatedFullyPoweredTime = 0.00f;
}

void UPowerFlowLockingMechanism::OnFullyPowered() {
}

void UPowerFlowLockingMechanism::OnEndFullyPowered() {
}


