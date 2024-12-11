#include "LockingMechanismDefinition.h"
#include "LockingMechanism.h"

ULockingMechanismDefinition::ULockingMechanismDefinition() {
    this->Name = TEXT("Default__LockingMechanismDefinition");
    this->RuntimeSubobjectType = ULockingMechanism::StaticClass();
    this->bCanBeClosedAfterOpening = false;
    this->bAutoClosesAfterOpening = false;
}


