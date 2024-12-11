#include "RailCarMovementReplicatedData.h"

FRailCarMovementReplicatedData::FRailCarMovementReplicatedData() {
    this->movementState = ERailCarMovementState::Off;
    this->DistanceFromTargetPost = 0.00f;
    this->CurrentRailConnectionID = 0;
    this->LatestValidConnectionID = 0;
    this->bInvertRotation = false;
    this->CurrentSpeedMultiplier = 0.00f;
    this->StartingDesiredPathLength = 0.00f;
    this->DesiredPathLength = 0.00f;
    this->RemainingPowerGracePeriodTicks = 0;
}

