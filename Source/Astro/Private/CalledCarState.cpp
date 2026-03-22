#include "CalledCarState.h"

FCalledCarState::FCalledCarState() {
    this->State = ECalledCarState::None;
    this->StartingPathDistance = 0.00f;
    this->CurrentPathDistance = 0.00f;
    this->LatestCarSpeed = 0.00f;
    this->CarMovementState = ERailCarMovementState::Off;
}

