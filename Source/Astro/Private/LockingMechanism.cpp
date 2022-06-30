#include "LockingMechanism.h"

bool ULockingMechanism::IsOpen() const {
    return false;
}

ULockingMechanism::ULockingMechanism() {
    this->bIsOpen = false;
}

