#include "SlotControlUnlockBehaviorDefinition.h"
#include "SlotControlUnlockBehavior.h"

USlotControlUnlockBehaviorDefinition::USlotControlUnlockBehaviorDefinition() {
    this->Name = TEXT("Default__SlotControlUnlockBehaviorDefinition");
    this->RuntimeSubobjectType = USlotControlUnlockBehavior::StaticClass();
}


