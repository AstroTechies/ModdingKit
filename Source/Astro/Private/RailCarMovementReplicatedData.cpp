#include "RailCarMovementReplicatedData.h"

FRailCarMovementReplicatedData::FRailCarMovementReplicatedData() {
    this->movementState = ERailCarMovementState::Off;
    this->DistanceFromTargetPost = 0.00f;
    this->CurrentRailConnectionID = 0;
    this->LatestValidConnectionID = 0;
    this->bInvertRotation = false;
    this->bHasPower = false;
    this->TargetSpeedMultiplier = 0.00f;
    this->CurrentSpeedMultiplier = 0.00f;
}

