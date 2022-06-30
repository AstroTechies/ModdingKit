#include "CalledCarStatus.h"

FCalledCarStatus::FCalledCarStatus() {
    this->CarMovementState = ERailCarMovementState::Off;
    this->DistanceFromStation = 0.00f;
    this->StartingDistanceFromStation = 0.00f;
    this->RecalledFromStationForward = false;
}

