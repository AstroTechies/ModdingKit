#include "PowerFlowLockingMechanism.h"

void UPowerFlowLockingMechanism::OnFullyPowered() {
}

void UPowerFlowLockingMechanism::OnEndFullyPowered() {
}

UPowerFlowLockingMechanism::UPowerFlowLockingMechanism() {
    this->AccumulatedFullyPoweredTime = 0.00f;
}

