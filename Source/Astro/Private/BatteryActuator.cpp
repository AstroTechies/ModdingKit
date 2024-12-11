#include "BatteryActuator.h"

ABatteryActuator::ABatteryActuator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void ABatteryActuator::OnAuthorityFullyCharged() {
}

void ABatteryActuator::OnAuthorityEndFullyCharged() {
}

void ABatteryActuator::OnAuthorityEndEmptyCharge() {
}

void ABatteryActuator::OnAuthorityEmptyCharge() {
}

void ABatteryActuator::AuthorityHandleTargetStorageSlotsReset() {
}

void ABatteryActuator::AuthorityHandleAttachedStorageSlotEvent(APhysicalItem* movedItem) {
}


