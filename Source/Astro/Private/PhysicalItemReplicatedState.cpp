#include "PhysicalItemReplicatedState.h"

FPhysicalItemReplicatedState::FPhysicalItemReplicatedState() {
    this->MotionState = EPhysicalItemMotionState::Simulating;
    this->SubslotIndex = 0;
    this->SlotFacingCardinalDirection = 0;
    this->LastSlotFromTool = false;
    this->LastSlotOnInitialization = false;
    this->PartOfSwap = false;
}

