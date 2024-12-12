#include "LockComponentContainer.h"

ULockComponentContainer::ULockComponentContainer() {
}

FLockComponent ULockComponentContainer::GetLockComponent(FAstroDatumRef lockComponentRef, bool& bOutSuccess) {
    return FLockComponent{};
}

FLockComponent ULockComponentContainer::FindLockComponent(FAstroDatumRef EntityRef, bool& bOutSuccess) {
    return FLockComponent{};
}


