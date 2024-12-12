#include "PowerFlowLockingMechanismDefinition.h"
#include "PowerFlowLockingMechanism.h"

UPowerFlowLockingMechanismDefinition::UPowerFlowLockingMechanismDefinition() {
    this->Name = TEXT("Default__PowerFlowLockingMechanismDefinition");
    this->RuntimeSubobjectType = UPowerFlowLockingMechanism::StaticClass();
    this->FullyPoweredMaintenanceTime = 5.00f;
    this->AccumulatedFullyPoweredTimeDecayDuration = 3.00f;
}


