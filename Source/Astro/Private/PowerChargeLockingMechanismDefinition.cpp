#include "PowerChargeLockingMechanismDefinition.h"
#include "PowerChargeLockingMechanism.h"

UPowerChargeLockingMechanismDefinition::UPowerChargeLockingMechanismDefinition() {
    this->Name = TEXT("Default__PowerChargeLockingMechanismDefinition");
    this->RuntimeSubobjectType = UPowerChargeLockingMechanism::StaticClass();
}


