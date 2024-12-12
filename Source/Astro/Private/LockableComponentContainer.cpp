#include "LockableComponentContainer.h"

ULockableComponentContainer::ULockableComponentContainer() {
}

FLockableComponent ULockableComponentContainer::GetLockableComponent(FAstroDatumRef lockableComponentRef, bool& bOutSuccess) {
    return FLockableComponent{};
}

FLockableComponent ULockableComponentContainer::FindLockableComponent(FAstroDatumRef EntityRef, bool& bOutSuccess) {
    return FLockableComponent{};
}


