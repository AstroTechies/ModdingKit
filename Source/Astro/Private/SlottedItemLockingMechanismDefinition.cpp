#include "SlottedItemLockingMechanismDefinition.h"
#include "SlottedItemLockingMechanism.h"

USlottedItemLockingMechanismDefinition::USlottedItemLockingMechanismDefinition() {
    this->Name = TEXT("Default__SlottedItemLockingMechanismDefinition");
    this->RuntimeSubobjectType = USlottedItemLockingMechanism::StaticClass();
}


