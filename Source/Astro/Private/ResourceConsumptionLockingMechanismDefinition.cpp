#include "ResourceConsumptionLockingMechanismDefinition.h"
#include "ResourceConsumptionLockingMechanism.h"

UResourceConsumptionLockingMechanismDefinition::UResourceConsumptionLockingMechanismDefinition() {
    this->Name = TEXT("Default__ResourceConsumptionLockingMechanismDefinition");
    this->RuntimeSubobjectType = UResourceConsumptionLockingMechanism::StaticClass();
    this->ConsumedResource = NULL;
    this->RequiredResourceUnits = 0;
    this->ResourceUnitConsumptionTime = 3.00f;
}


